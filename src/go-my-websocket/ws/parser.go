package ws

import (
	"encoding/binary"
	"fmt"
	"strings"
)

/*
	RFC 6455 Data Framing 数据帧

	  0                   1                   2                   3
	  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
	 +-+-+-+-+-------+-+-------------+-------------------------------+
	 |F|R|R|R| opcode|M| Payload len |    Extended payload length    |
	 |I|S|S|S|  (4)  |A|     (7)     |             (16/64)           |
	 |N|V|V|V|       |S|             |   (if payload len==126/127)   |
	 | |1|2|3|       |K|             |                               |
	 +-+-+-+-+-------+-+-------------+ - - - - - - - - - - - - - - - +
	 |     Extended payload length continued, if payload len == 127  |
	 + - - - - - - - - - - - - - - - +-------------------------------+
	 |     and more continued        |Masking-key, if MASK set to 1  |
	 +-------------------------------+-------------------------------+
	 | Masking-key (continued)       |          Payload Data         |
	 +-------------------------------- - - - - - - - - - - - - - - - +
	 :                     Payload Data continued ...                :
	 + - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - +
	 |                     Payload Data continued ...                |
	 +---------------------------------------------------------------+

*/

const (

	// The message types are defined in RFC 6455, section 11.8.
	BrokenMessage     MessageType = 0xf0
	ContinuationFrame MessageType = 0
	TextMessage       MessageType = 1
	BinaryMessage     MessageType = 2
	CloseMessage      MessageType = 8
	PingMessage       MessageType = 9
	PongMessage       MessageType = 10

	EIO_Close   EngineioPacket = "1"
	EIO_Ping    EngineioPacket = "2"
	EIO_Pond    EngineioPacket = "3"
	EIO_Message EngineioPacket = "4"
	EIO_Upgrade EngineioPacket = "5"
	EIO_Noop    EngineioPacket = "6"

	SIO_Connect      SocketioPacket = "0"
	SIO_Disconnect   SocketioPacket = "1"
	SIO_Event        SocketioPacket = "2"
	SIO_Ack          SocketioPacket = "3"
	SIO_Error        SocketioPacket = "4"
	SIO_Binary_Event SocketioPacket = "5"
	SIO_Binary_Ack   SocketioPacket = "6"

	// ErrorCode
	ErrorNil ErrorCode = iota
	ErrorLength
	ErrorKeyLength
	ErrorMessageType
)

type ErrorCode uint

func (s ErrorCode) String() string {
	cs := map[ErrorCode]string{
		ErrorNil:         "ErrorNil",
		ErrorLength:      "ErrorLength",
		ErrorKeyLength:   "ErrorKeyLength",
		ErrorMessageType: "ErrorMessageType",
	}[s]
	if cs != "" {
		return cs
	} else {
		return fmt.Sprintf("<ErrorCode v:%d>", s)
	}
}

type MessageType byte

func (s MessageType) String() string {
	cs := map[MessageType]string{
		0xf0: "BrokenMessage",
		0:    "ContinuationFrame",
		1:    "TextMessage",
		2:    "BinaryMessage",
		8:    "CloseMessage",
		9:    "PingMessage",
		10:   "PongMessage",
	}[s]
	if cs > "" {
		return cs
	} else {
		return fmt.Sprintf("<MessageType unknown:%d>", s)
	}
}

type EngineioPacket string

func (s EngineioPacket) Unknown() bool {
	return strings.HasPrefix(s.String(), "<EngineioPacket unknown:")
}
func (s EngineioPacket) String() string {
	cs := map[EngineioPacket]string{
		"1": "EIO_Close",
		"2": "EIO_Ping",
		"3": "EIO_Pond",
		"4": "EIO_Message",
		"5": "EIO_Upgrade",
		"6": "EIO_Noop",
	}[s]
	if cs > "" {
		return cs + "[OK]"
	} else {
		return fmt.Sprintf("<EngineioPacket unknown:%q>", string(s))
	}
}

type SocketioPacket string

func (s SocketioPacket) Unknown() bool {
	return strings.HasPrefix(s.String(), "<SocketioPacket unknown:")
}
func (s SocketioPacket) String() string {
	cs := map[SocketioPacket]string{
		"0": "SIO_Connect",
		"1": "SIO_Disconnect",
		"2": "SIO_Event",
		"3": "SIO_Ack",
		"4": "SIO_Error",
		"5": "SIO_Binary_Event",
		"6": "SIO_Binary_Ack",
	}[s]
	if cs > "" {
		return cs
	} else {
		return fmt.Sprintf("<SocketioPacket unknown:%q>", string(s))
	}
}

type FrameParser struct {
	Raw          []byte
	parsed       bool
	Final        bool
	Rsv1         bool
	Rsv2         bool
	Rsv3         bool
	Opcode       byte
	Maskingkey   []byte
	Masking      bool
	Type         MessageType
	ExHeaderSize uint
	Length       uint64
	Header       []byte
	Data         []byte
}

func (c *FrameParser) Detect(header []byte) (msgtype MessageType, exsize uint, err ErrorCode) {
	c.Reset() // ready for a new frame
	if len(header) != 2 {
		return BrokenMessage, 0, ErrorLength
	}
	// 2bytes header
	c.Final = (header[0] | byte(1<<7)) > 0
	c.Rsv1 = (header[0] | byte(1<<6)) > 0
	c.Rsv2 = (header[0] | byte(1<<5)) > 0
	c.Rsv3 = (header[0] | byte(1<<4)) > 0
	c.Opcode = (header[0] & 0x0F)
	c.Type = MessageType(c.Opcode)
	c.Masking = (header[1] & byte(1<<7)) > 0
	c.Length = uint64(header[1] & 0x7f)

	c.ExHeaderSize = 0
	if c.Masking {
		c.ExHeaderSize += 4
	}
	if c.Length == 126 {
		c.ExHeaderSize += 2
	} else if c.Length == 127 {
		c.ExHeaderSize += 8
	}
	c.Raw = append([]byte{}, header...) // copy
	return c.Type, c.ExHeaderSize, ErrorNil
}

func (c *FrameParser) DecideLength(ex []byte) (payloadlen uint64, err ErrorCode) {
	if uint(len(ex)) != c.ExHeaderSize {
		return 0, ErrorLength
	}
	if c.Masking {
		c.Maskingkey = ex[len(ex)-4:]
	}
	if c.Length == 126 {
		c.Length = binary.BigEndian.Uint64(ex[0:2])
	} else if c.Length == 127 {
		c.Length = binary.BigEndian.Uint64(ex[0:8])
	}
	c.Raw = append(c.Raw, ex...) // copy
	return c.Length, ErrorNil
}

func (c *FrameParser) Load(data []byte) ErrorCode {
	if uint64(len(data)) != c.Length {
		return ErrorLength
	}
	c.Raw = append(c.Raw, data...)     // copy
	c.Data = append([]byte{}, data...) // copy
	c.Mask()
	return ErrorNil
}

func (c *FrameParser) Mask() ErrorCode {
	ldata := uint64(len(c.Data))
	lkey := len(c.Maskingkey)
	if !c.Masking && ldata == c.Length {
		return ErrorNil
	} else if !c.Masking && ldata != c.Length {
		return ErrorLength
	} else if c.Masking && lkey != 4 {
		return ErrorKeyLength
	} else if c.Masking {
		for i := uint64(0); i < c.Length; i++ {
			j := i % uint64(lkey)
			b := c.Maskingkey[j] ^ c.Data[i]
			c.Data[i] = b
		}
	}
	return ErrorNil
}

func (c *FrameParser) Reset() {
	c.Raw = []byte{}
	c.parsed = false
	c.Final = false
	c.Rsv1 = false
	c.Rsv2 = false
	c.Rsv3 = false
	c.Opcode = 0
	c.Maskingkey = []byte{}
	c.Masking = false
	c.Type = 0
	c.Length = 0
	c.Header = []byte{}
	c.Data = []byte{}
}
