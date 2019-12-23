package ws

import (
	"bufio"
	"crypto/sha1"
	"encoding/base64"
	"encoding/json"
	"errors"
	"fmt"
	"io"
	stdLog "log"
	"net"
	"net/http"
	"os"
	"runtime"
	"time"
)

const (
	TOO_LONG     = "[payload too long]"
	PingTimeout  = time.Second * 5
	PingInterval = time.Second * 15000
)

func printStack() {
	var buf [4096]byte
	n := runtime.Stack(buf[:], false)
	os.Stdout.Write(buf[:n])
}

var log = stdLog.New(os.Stderr, "[ws]", stdLog.Ltime)

type Wsdemo struct {
	w       http.ResponseWriter
	r       *http.Request
	netconn net.Conn
	brw     *bufio.ReadWriter
	who     string
}

func (c Wsdemo) read() {
	fm := FrameParser{}
	for {
		p, err := c.peek(2)
		if err != nil {
			break
		} else if len(p) != 2 {
			continue
		}
		log.Printf("Read a 2bytes header: %d [%x] [%x]\n", len(p), p, p)
		// onData...
		msgtype, exsize, ec := fm.Detect(p)
		if ec != ErrorNil {
			continue
		}
		ex, err := c.peek(int(exsize))
		if err != nil {
			break
		} else if uint(len(ex)) != exsize {
			continue
		}
		log.Printf("Read an ex-header [%d] %s: %d [%x] [%x]\n", exsize, msgtype.String(), len(ex), ex, ex)
		payloadlen, _ := fm.DecideLength(ex)
		payload, err := c.peek(int(payloadlen))
		if err != nil {
			break
		}
		log.Printf("Read payload [%d] %s: %d [%x]", payloadlen, msgtype.String(), len(payload), payload)
		fm.Load(payload)
		c.onMessage(fm)
	}
}

func (c Wsdemo) ServeHTTP(w http.ResponseWriter, r *http.Request) {
	c.w = w
	c.r = r

	if r.URL.RequestURI() == "/socket.io/socket.io.js" {
		w.Write([]byte(`
		// socket.io.js not provide here, use CDN below:
		// https://cdnjs.com/libraries/socket.io
		// https://cdnjs.cloudflare.com/ajax/libs/socket.io/2.3.0/socket.io.js
		`))
		return
	}

	netConn, brw, _ := c.Upgrade(w, r)
	c.netconn = netConn
	c.brw = brw
	c.who = c.netconn.RemoteAddr().String()

	log.Println("Wsdemo.ServeHTTP()...", r.URL.RequestURI(), r.RequestURI)

	Upgrade := r.Header.Get("Upgrade") == "websocket"
	Connection := r.Header.Get("Connection") == "Upgrade"
	if isWebsocketUpgrade := Upgrade && Connection; isWebsocketUpgrade {
		c.OpenHandshake()
		c.EngineioOpen("Engine.io Open")
		go c.read()
	} else {
		// w.WriteHeader(200)
		// w.Write([]byte("Ok"))
		// brw.Write([]byte("Totally-Control: Yes\r\n"))
		// brw.Flush()
		netConn.Write([]byte("HTTP/1.1 200 OK\r\n\r\nThis is an websocket server, use websocket client to connect."))
		netConn.Close()
	}
}

func (c Wsdemo) peek(size int) (p []byte, err error) {
	if size == 0 {
		return []byte{}, nil
	}
	c.netconn.SetDeadline(time.Now().Add(30000 * time.Millisecond))
	var brw *bufio.ReadWriter = c.brw
	buf, err := brw.Peek(size)
	brw.Discard(len(buf))
	// buf := []byte{}
	// size, err := brw.Read(buf)
	if err != nil && err == io.EOF { // client disconnect
		c.netconn.Close()
		return buf, err
	} else if err != nil {
		switch err.(type) {
		case *net.OpError:
			var e *net.OpError = err.(*net.OpError)
			log.Printf("Peeking net.OpError [%x] timeout:%t temporary:%t %#+v", p, e.Timeout(), e.Temporary(), e.Err)
			if !(e.Timeout() || e.Temporary()) {
				log.Printf("Client leave %s", c.who)
				c.netconn.Close()
				return buf, err
			}
		default:
			log.Printf("Peeking error %#+v", err)
		}
	}

	return buf, nil
}

func (c Wsdemo) read_demo() {
	var brw *bufio.ReadWriter = c.brw
	for {
		c.netconn.SetDeadline(time.Now().Add(30000 * time.Millisecond))
		// size := 2
		// buf, err := brw.Peek(size)
		// brw.Discard(len(buf))

		// buf := []byte{}
		// size, err := brw.Read(buf)

		buf, ok, err := brw.ReadLine() // '\n' as delim and it not include in buf
		size := len(buf)

		// buf, err := brw.ReadBytes('B') // 'B' included in buf or error return
		// size := len(buf)

		msg := fmt.Sprintf("4recv %s [%d]: %x", c.who, size, string(buf))
		// c.TextFrame(msg)
		log.Println(msg, " ok:", ok)
		if err != nil && err == io.EOF { // client disconnect
			c.netconn.Close()
			break
		} else if err != nil {
			log.Printf("Error: %#+v", err)
		}
	}
}

func (c Wsdemo) read_unworking() {
	input := bufio.NewScanner(c.netconn)
	buf := []byte{}
	input.Buffer(buf, 2)
	c.netconn.SetDeadline(time.Now().Add(100 * time.Millisecond))
	log.Printf("read by bufio.Scanner...")
	for input.Scan() {
		c.netconn.SetDeadline(time.Now().Add(100 * time.Millisecond))
		msg := fmt.Sprintf("4recv %s: 0x%x", c.who, input.Text())
		c.TextFrame(msg)
		log.Println(msg)
	}
}

func (c Wsdemo) onSocketioMessage(data []byte, fm FrameParser) {
	msgtype := SocketioPacket(data[0:1])
	switch msgtype {
	case SIO_Binary_Event:
		packet := []string{}
		err := json.Unmarshal(data[3:], &packet)
		if err != nil {
			log.Printf("onSocketio Event unmarshal error %s raw[%s]", err, string(data[1:]))
			return
		}
		event := packet[0]
		c.SocketioEventDemo(event, packet[1])
		log.Printf("onSocketio BinaryEvent %s %s len[%d]", event, packet[1], len(data))
	case SIO_Event:
		packet := []string{}
		err := json.Unmarshal(data[1:], &packet)
		if err != nil {
			log.Printf("onSocketio Event unmarshal error %s raw[%s]", err, string(data[1:]))
			return
		}
		event := packet[0]
		c.SocketioEventDemo(event, packet[1])
		log.Printf("onSocketio Event %s %s len[%d]", event, packet[1], len(data))
	default:
		log.Printf("onSocketioPacet %s %s len[%d]: %x", msgtype.String(), string(data), len(data), data)
	}
}
func (c Wsdemo) onEngineioPacket(data []byte, fm FrameParser) {
	msgtype := EngineioPacket(data[0:1])
	log.Printf("onEnginioMessage %s %s len[%d]: % x", msgtype.String(), string(data), len(data), data)
	if msgtype == EIO_Ping {
		c.EngineioPond("Pong...")
	} else if msgtype == EIO_Message {
		c.onSocketioMessage(data[1:], fm)
	} else if msgtype.Unknown() {
		c.TextFrame("Unknown Type::" + string(data))
	}
}
func (c Wsdemo) onMessage(fm FrameParser) {
	if fm.Type == CloseMessage {
		log.Println("Close connection for " + fm.Type.String() + string(fm.Data))
		c.netconn.Close()
	} else if fm.Type == TextMessage {
		c.onEngineioPacket(fm.Data, fm)
	} else {
		log.Printf("onMessage %s data:%s len[%d]: % x", fm.Type.String(), string(fm.Data), len(fm.Raw), fm.Raw)
	}
}

func (c Wsdemo) computeAcceptKey(challengeKey string) string {
	var keyGUID = []byte("258EAFA5-E914-47DA-95CA-C5AB0DC85B11")
	sn := append([]byte(challengeKey), keyGUID...)
	h := sha1.New()
	h.Write(sn)
	// hash := sha1.Sum(sn)
	return base64.StdEncoding.EncodeToString(h.Sum(nil))
}

func (c Wsdemo) TextFrame(payload string) {
	if len(payload) > 125 {
		payload = payload[0:124-len(TOO_LONG)] + TOO_LONG
	}
	len := byte(len(payload))
	frame := []byte{0x80 | byte(TextMessage), len}
	frame = append(frame, []byte(payload)...)
	c.send(frame)
}
func (c Wsdemo) BinaryFrame(payload string) {
	if len(payload) > 125 {
		payload = payload[0:124-len(TOO_LONG)] + TOO_LONG
	}
	len := byte(len(payload))
	frame := []byte{0x80 | byte(BinaryMessage), len}
	frame = append(frame, []byte(payload)...)
	c.send(frame)
}
func (c Wsdemo) CloseFrame(payload string) {
	if len(payload) > 125 {
		payload = payload[0:124-len(TOO_LONG)] + TOO_LONG
	}
	len := byte(len(payload))
	frame := []byte{0x80 | byte(CloseMessage), len}
	frame = append(frame, []byte(payload)...)
	c.send(frame)
}
func (c Wsdemo) PingFrame(payload string) {
	if len(payload) > 125 {
		payload = payload[0:124-len(TOO_LONG)] + TOO_LONG
	}
	len := byte(len(payload))
	frame := []byte{0x80 | byte(PingMessage), len}
	frame = append(frame, []byte(payload)...)
	c.send(frame)
}
func (c Wsdemo) PongFrame(payload string) {
	if len(payload) > 125 {
		payload = payload[0:124-len(TOO_LONG)] + TOO_LONG
	}
	len := byte(len(payload))
	frame := []byte{0x80 | byte(PongMessage), len}
	frame = append(frame, []byte(payload)...)
	c.send(frame)
}
func (c Wsdemo) send(frame []byte) {
	c.netconn.SetWriteDeadline(time.Now().Add(30 * time.Second))
	c.brw.Write(frame)
	c.brw.Writer.Flush()
	// c.brw.Flush()
}

func (c Wsdemo) OpenHandshake() {
	challengeKey := c.r.Header.Get("Sec-WebSocket-Key")
	Extensions := c.r.Header.Get("Sec-WebSocket-Extensions")
	Protocol := c.r.Header.Get("Sec-WebSocket-Protocol")

	p := []byte{}
	p = append(p, "HTTP/1.1 101 Switching Protocols\r\n"...)
	p = append(p, "Upgrade: websocket\r\n"...)
	p = append(p, "Connection: Upgrade\r\n"...)
	if Protocol > "" {
		p = append(p, ("Sec-WebSocket-Protocol: " + Protocol + "\r\n")...)
	}
	if false && Extensions > "" {
		p = append(p, ("Sec-WebSocket-Extensions: permessage-deflate\r\n")...)
	}
	p = append(p, ("Sec-WebSocket-Accept: " + c.computeAcceptKey(challengeKey) + "\r\n")...)

	p = append(p, "\r\n"...)

	// Clear deadlines set by HTTP server.
	c.netconn.SetDeadline(time.Time{})

	log.Printf("OpenHandshake %s...", c.who)
	c.netconn.Write(p)
}

func (c Wsdemo) Upgrade(w http.ResponseWriter, r *http.Request) (net.Conn, *bufio.ReadWriter, error) {
	hj, ok := w.(http.Hijacker)
	if !ok {
		msg := "websocket: response does not implement http.Hijacker"
		http.Error(w, msg, http.StatusInternalServerError)
		return nil, nil, errors.New(msg)
	}
	var brw *bufio.ReadWriter
	netConn, brw, err := hj.Hijack()
	if err != nil {
		http.Error(w, err.Error(), http.StatusInternalServerError)
		return nil, nil, err
	}

	if brw.Reader.Buffered() > 0 {
		netConn.Close()
		msg := "websocket: client sent data before handshake is complete"
		http.Error(w, msg, http.StatusInternalServerError)
		return nil, nil, errors.New(msg)
	}

	return netConn, brw, nil
}

// Engine.io API
func (c Wsdemo) EngineioOpen(text string) {
	// Engine.io Open Message
	mo := `0{"sid":"client_%s","upgrades":[],"pingInterval":%d,"pingTimeout":%d}`
	packet := []byte(fmt.Sprintf(mo, c.who, PingInterval/time.Millisecond, PingTimeout/time.Millisecond))
	c.TextFrame(string(packet))
	c.TextFrame("40")
}
func (c Wsdemo) EngineioClose(text string) {
	c.TextFrame("1" + text)
}
func (c Wsdemo) EngineioPing(text string) {
	c.TextFrame("2" + text)
}
func (c Wsdemo) EngineioPond(text string) {
	c.TextFrame("3" + text)
}
func (c Wsdemo) EngineioMessage(text string) {
	c.TextFrame("4" + text)
}
func (c Wsdemo) EngineioUpgrade(text string) {
	c.TextFrame("5" + text) // ???
}
func (c Wsdemo) EngineioNoop(text string) {
	c.TextFrame("6" + text)
}

// Socket.io API
func (c Wsdemo) SocketioEventDemo(event string, data string) {
	res := fmt.Sprintf("%s received[%d]: %s", event, len(data), data)
	jsontxt := fmt.Sprintf("{%q:%q,%q:%q}", "userId", c.who, "text", res)
	event = "chat"
	c.SocketioEventEmit(event, jsontxt)
}
func (c Wsdemo) SocketioEventEmit(event string, text string) {
	// enc := base64.StdEncoding.EncodeToString([]byte(text))
	msg := fmt.Sprintf("2[%q,%s]", event, text)
	c.EngineioMessage(msg)
}
