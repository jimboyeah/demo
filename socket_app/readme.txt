
基于Visual C++的Winsock API研究
http://tech.163.com/05/1009/13/1VKHINQ200091589.html

* 在Windows平台使用Winsocket来进行网络编程时要引入头文件和库文件如下：

对于Winsocket 1.1版本
#include<winsock.h>
#pragma comment(lib, "wsock32.lib")

对于Winsocket 2.2版本
#include<winsock2.h>
#pragma comment(lib, "ws2_32.lib")


[文章信息]
    作者:刘 涛 时间:2003-01-02 出处:yesky 责任编辑:方舟
[文章导读]
    为了方便网络编程，90年代初，由Microsoft联合了其他几家公司共同制定了一套WINDOWS下的网络编程接口，
    即Windows Sockets规范，它不是一种网络协议,而是一套开放的、支持多种协议的Windows下的网络编程接口。
    现在的Winsock已经基本上实现了与协议无关，你可以使用Winsock来调用多种协议的功能，但较常使用的是
    TCP/IP协议。Socket实际在计算机中提供了一个通信端口，可以通过这个端口与任何一个具有Socket接口的
    计算机通信。应用程序在网络上传输，接收的信息都通过这个Socket接口来实现。

    微软为VC定义了Winsock类如CAsyncSocket类和派生于CAsyncSocket 的CSocket类，它们简单易用，读者朋友
    当然可以使用这些类来实现自己的网络程序，但是为了更好的了解Winsock API编程技术，我们这里探讨怎样
    使用底层的API函数实现简单的 Winsock 网络应用程式设计，分别说明如何在Server端和Client端操作Socket，
    实现基于TCP/IP的数据传送，最后给出相关的源代码。

    在VC中进行WINSOCK的API编程开发的时候，需要在项目中使用下面三个文件，否则会出现编译错误。

    1．WINSOCK.H: 这是WINSOCK API的头文件，需要包含在项目中。
    2．WSOCK32.LIB: WINSOCK API连接库文件。在使用中，一定要把它作为项目的非缺省的连接库包含到项目文件中去。
    3．WINSOCK.DLL: WINSOCK的动态连接库，位于WINDOWS的安装目录下。

[服务器端操作 socket（套接字）]
    1)在初始化阶段调用WSAStartup()
    此函数在应用程序中初始化Windows Sockets DLL ，只有此函数调用成功后，应用程序才可以再调用其他
    Windows Sockets DLL中的API函数。在程式中调用该函数的形式如下：

    WSAStartup((WORD)((1<<8|1)，（LPWSADATA）&WSAData);
    if( WSAStartup( MAKEWORD(2,2), &wsaData) != 0 ) printf( "WSAStartup 无法初始化！");

    其中(1<<8|1)表示我们用的是WinSocket1.1版本，WSAata用来存储系统传回的关于WinSocket的资料。

    2)建立Socket
    初始化WinSock的动态连接库后，需要在服务器端建立一个监听的Socket，为此可以调用Socket()函数用来建立
    这个监听的Socket，并定义此Socket所使用的通信协议。此函数调用成功返回Socket对象，失败则返回INVALID_SOCKET
    调用WSAGetLastError()可得知原因，所有WinSocket 的函数都可以使用这个函数来获取失败的原因。

    SOCKET PASCAL FAR socket( int af, int type, int protocol )
    参数:
    af:目前只提供 PF_INET(AF_INET)；
    type：Socket 的类型 (SOCK_STREAM、SOCK_DGRAM)；
    protocol：通讯协定(如果使用者不指定则设为0)；

    如果要建立的是遵从TCP/IP协议的socket，第二个参数type应为SOCK_STREAM，如为UDP（数据报）的socket，应为SOCK_DGRAM。

    3)绑定端口
    接下来要为服务器端定义的这个监听的Socket指定一个地址及端口（Port），这样客户端才知道待会要连接哪
    一个地址的哪个端口，为此我们要调用bind()函数，该函数调用成功返回0，否则返回SOCKET_ERROR。

    int PASCAL FAR bind( SOCKET s, const struct sockaddr FAR *name,int namelen );
    参 数：
    s：Socket对象名；
    name：Socket的地址值，这个地址必须是执行这个程式所在机器的IP地址；
    namelen：name的长度；

    如果使用者不在意地址或端口的值，那么可以设定地址为INADDR_ANY，及Port为0，Windows Sockets 会自动将其
    设定适当之地址及Port (1024 到 5000之间的值)。此后可以调用getsockname()函数来获知其被设定的值。

    4）监听
    当服务器端的Socket对象绑定完成之后,服务器端必须建立一个监听的队列来接收客户端的连接请求。listen()函数
    使服务器端的Socket 进入监听状态，并设定可以建立的最大连接数(目前最大值限制为 5, 最小值为1)。该函数调用
    成功返回0，否则返回SOCKET_ERROR。

    int PASCAL FAR listen( SOCKET s, int backlog );
    参 数：
    s：需要建立监听的Socket；
    backlog：最大连接个数；
    服务器端的Socket调用完listen()后，如果此时客户端调用connect()函数提出连接申请的话，Server 端必须再
    调用accept()函数，这样服务器端和客户端才算正式完成通信程序的连接动作。为了知道什么时候客户端提出连
    接要求，从而服务器端的Socket在恰当的时候调用accept()函数完成连接的建立，我们就要使用WSAAsyncSelect()
    函数，让系统主动来通知我们有客户端提出连接请求了。该函数调用成功返回0，否则返回SOCKET_ERROR。

    int PASCAL FAR WSAAsyncSelect( SOCKET s, HWND hWnd,unsigned int wMsg, long lEvent );
    参数：
    s：Socket 对象；
    hWnd：接收消息的窗口句柄；
    wMsg：传给窗口的消息；
    lEvent：被注册的网络事件，也即是应用程序向窗口发送消息的网路事件，该值为下列值FD_READ、FD_WRITE、
    FD_OOB、FD_ACCEPT、FD_CONNECT、FD_CLOSE的组合，各个值的具体含意为
    FD_READ：希望在套接字S收到数据时收到消息；
    FD_WRITE：希望在套接字S上可以发送数据时收到消息；
    FD_ACCEPT：希望在套接字S上收到连接请求时收到消息；
    FD_CONNECT：希望在套接字S上连接成功时收到消息；
    FD_CLOSE：希望在套接字S上连接关闭时收到消息；
    FD_OOB：希望在套接字S上收到带外数据时收到消息。
    具体应用时，wMsg应是在应用程序中定义的消息名称，而消息结构中的lParam则为以上各种网络事件名称。所以，
    可以在窗口处理自定义消息函数中使用以下结构来响应Socket的不同事件：

    switch(lParam){
        case FD_READ:
            …
        break;
        case FD_WRITE:
            …
        break;
            …
    }

    5）服务器端接受客户端的连接请求
    当Client提出连接请求时，Server 端hwnd视窗会收到Winsock Stack送来我们自定义的一个消息，这时，
    我们可以分析lParam，然后调用相关的函数来处理此事件。为了使服务器端接受客户端的连接请求，就要
    使用accept() 函数，该函数新建一Socket与客户端的Socket相通，原先监听之Socket继续进入监听状态，
    等待他人的连接要求。该函数调用成功返回一个新产生的Socket对象，否则返回INVALID_SOCKET。

    SOCKET PASCAL FAR accept( SCOKET s, struct sockaddr FAR *addr,int FAR *addrlen );
    参数：
    s：Socket的识别码；
    addr：存放来连接的客户端的地址；
    addrlen：addr的长度

    6）结束 socket 连接
    结束服务器和客户端的通信连接是很简单的，这一过程可以由服务器或客户机的任一端启动，只要调用
    closesocket()就可以了，关闭Server端监听状态的socket，同样也是利用此函数。另外，与程序启动时
    调用WSAStartup()憨数相对应，程式结束前，需要调用 WSACleanup() 来通知Winsock Stack释放Socket
    所占用的资源。这两个函数都是调用成功返回0，否则返回SOCKET_ERROR。

    int PASCAL FAR closesocket( SOCKET s );
    参 数：
    s：Socket 的识别码；

    int PASCAL FAR WSACleanup( void );
    参 数： 无

[二、客户端Socket的操作]
    1）建立客户端的Socket
    客户端应用程序首先也是调用WSAStartup() 函数来与Winsock的动态连接库建立关系，然后同样调用socket()
    来建立一个TCP或UDP socket，相同协定的 sockets 才能相通，TCP 对 TCP，UDP 对 UDP。与服务器端的socket
    不同的是，客户端的socket 可以调用 bind() 函数，由自己来指定IP地址及port号码；但是也可以不调用 bind()，
    而由 Winsock来自动设定IP地址及port号码。

    2）提出连接申请
    客户端的Socket使用connect()函数来提出与服务器端的Socket建立连接的申请，函数调用成功返回0，否则返回SOCKET_ERROR。

    int PASCAL FAR connect( SOCKET s, const struct sockaddr FAR *name, int namelen );
    参 数：
    s：Socket 的识别码；
    name：Socket想要连接的对方地址；
    namelen：name的长度

[三、数据的传送]
    虽然基于TCP/IP连接协议（流套接字）的服务是设计客户机/服务器应用程序时的主流标准，但有些服务也是
    可以通过无连接协议（数据报套接字）提供的。先介绍一下TCP socket 与UDP socket 在传送数据时的特性：
    Stream (TCP) Socket 提供双向、可靠、有次序、不重复的资料传送。
    Datagram (UDP) Socket 虽然提供双向的通信，但没有可靠、有次序、不重复的保证，所以UDP传送数据可能
    会收到无次序、重复的资料，甚至资料在传输过程中出现遗漏。由于UDP Socket 在传送资料时，并不保证资料
    能完整地送达对方，所以绝大多数应用程序都是采用TCP处理Socket，以保证资料的正确性。一般情况下
    TCP Socket 的数据发送和接收是调用send() 及recv() 这两个函数来达成，
    UDP Socket 则是用sendto() 及recvfrom() 这两个函数，这两个函数调用成功发挥发送或接收的资料的长度，
    否则返回SOCKET_ERROR。

    int PASCAL FAR send( SOCKET s, const char FAR *buf, int len, int flags );
    参数：
    s：Socket 的识别码
    buf：存放要传送的资料的暂存区
    len：buf的长度
    flags：此函数被调用的方式

    int PASCAL FAR recv( SOCKET s, char FAR *buf, int len, int flags );
    参数：
    s：Socket 的识别码
    buf：存放接收到的资料的暂存区
    len：buf的长度
    flags：此函数被调用的方式

    对于Datagram Socket而言，若是 datagram 的大小超过限制，则将不会送出任何资料，并会传回错误值。
    对Stream Socket 言，Blocking 模式下，若是传送系统内的储存空间不够存放这些要传送的资料，send()
    将会被block住，直到资料送完为止；如果该Socket被设定为 Non-Blocking 模式，那么将视目前的output buffer
    空间有多少，就送出多少资料，并不会被 block 住。flags 的值可设为 0 或 MSG_DONTROUTE及 MSG_OOB 的组合。

    对Stream Socket 言，我们可以接收到目前input buffer内有效的资料，但其数量不超过len的大小。

[四、自定义的CMySocket类的实现]
    根据上面的知识，我自定义了一个简单的CMySocket类，下面是我定义的该类的部分实现代码：

//////////////////////////////////////
CMySocket::CMySocket() : file://类的构造函数
{
   WSADATA wsaD;
   memset( m_LastError, 0, ERR_MAXLENGTH );
   // m_LastError是类内字符串变量,初始化用来存放最后错误说明的字符串；
   // 初始化类内sockaddr_in结构变量，前者存放客户端地址，后者对应于服务器端地址;
   memset( &m_sockaddr, 0, sizeof( m_sockaddr ) );
   memset( &m_rsockaddr, 0, sizeof( m_rsockaddr ) );
   int result = WSAStartup((WORD)((1<<8|1)， &wsaD);//初始化WinSocket动态连接库;
   if( result != 0 ) // 初始化失败；
   { set_LastError( "WSAStartup failed!", WSAGetLastError() );
     return;
   }
}

//////////////////////////////
CMySocket::~CMySocket() { WSACleanup(); }//类的析构函数；
////////////////////////////////////////////////////
int CMySocket::Create( void )
   {// m_hSocket是类内Socket对象，创建一个基于TCP/IP的Socket变量，并将值赋给该变量；
     if ( (m_hSocket = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP )) == INVALID_SOCKET )
     {
       set_LastError( "socket() failed", WSAGetLastError() );
       return ERR_WSAERROR;
     }
     return ERR_SUCCESS;
   }
///////////////////////////////////////////////
int CMySocket::Close( void )//关闭Socket对象；
{
   if ( closesocket( m_hSocket ) == SOCKET_ERROR )
   {
     set_LastError( "closesocket() failed", WSAGetLastError() );
     return ERR_WSAERROR;
   }
   file://重置sockaddr_in 结构变量；
   memset( &m_sockaddr, 0, sizeof( sockaddr_in ) );
   memset( &m_rsockaddr, 0, sizeof( sockaddr_in ) );
   return ERR_SUCCESS;
}
/////////////////////////////////////////
int CMySocket::Connect( char* strRemote, unsigned int iPort )//定义连接函数；
{
   if( strlen( strRemote ) == 0 || iPort == 0 )
     return ERR_BADPARAM;
   hostent *hostEnt = NULL;
   long lIPAddress = 0;
   hostEnt = gethostbyname( strRemote );//根据计算机名得到该计算机的相关内容；
   if( hostEnt != NULL )
   {
     lIPAddress = ((in_addr*)hostEnt->h_addr)->s_addr;
     m_sockaddr.sin_addr.s_addr = lIPAddress;
   }
   else
   {
     m_sockaddr.sin_addr.s_addr = inet_addr( strRemote );
   }
   m_sockaddr.sin_family = AF_INET;
   m_sockaddr.sin_port = htons( iPort );
   if( connect( m_hSocket, (SOCKADDR*)&m_sockaddr, sizeof( m_sockaddr ) ) == SOCKET_ERROR )
   {
     set_LastError( "connect() failed", WSAGetLastError() );
     return ERR_WSAERROR;
   }
   return ERR_SUCCESS;
}
///////////////////////////////////////////////////////
int CMySocket::Bind( char* strIP, unsigned int iPort )//绑定函数；
{
   if( strlen( strIP ) == 0 || iPort == 0 )
     return ERR_BADPARAM;
   memset( &m_sockaddr,0, sizeof( m_sockaddr ) );
   m_sockaddr.sin_family = AF_INET;
   m_sockaddr.sin_addr.s_addr = inet_addr( strIP );
   m_sockaddr.sin_port = htons( iPort );
   if ( bind( m_hSocket, (SOCKADDR*)&m_sockaddr, sizeof( m_sockaddr ) ) == SOCKET_ERROR )
   {
     set_LastError( "bind() failed", WSAGetLastError() );
     return ERR_WSAERROR;
   }
   return ERR_SUCCESS;
}
//////////////////////////////////////////
int CMySocket::Accept( SOCKET s )//建立连接函数，S为监听Socket对象名；
{
   int Len = sizeof( m_rsockaddr );
   memset( &m_rsockaddr, 0, sizeof( m_rsockaddr ) );
   if( ( m_hSocket = accept( s, (SOCKADDR*)&m_rsockaddr, &Len ) ) == INVALID_SOCKET )
   {
     set_LastError( "accept() failed", WSAGetLastError() );
     return ERR_WSAERROR;
   }
   return ERR_SUCCESS;
}
/////////////////////////////////////////////////////
int CMySocket::asyncSelect( HWND hWnd, unsigned int wMsg, long lEvent )
file://事件选择函数；
{
   if( !IsWindow( hWnd ) || wMsg == 0 || lEvent == 0 )
     return ERR_BADPARAM;
   if( WSAAsyncSelect( m_hSocket, hWnd, wMsg, lEvent ) == SOCKET_ERROR )
   {
     set_LastError( "WSAAsyncSelect() failed", WSAGetLastError() );
     return ERR_WSAERROR;
   }
   return ERR_SUCCESS;
}
////////////////////////////////////////////////////
int CMySocket::Listen( int iQueuedConnections )//监听函数；
{
   if( iQueuedConnections == 0 )
     return ERR_BADPARAM;
   if( listen( m_hSocket, iQueuedConnections ) == SOCKET_ERROR )
   {
     set_LastError( "listen() failed", WSAGetLastError() );
     return ERR_WSAERROR;
   }
   return ERR_SUCCESS;
}
////////////////////////////////////////////////////
int CMySocket::Send( char* strData, int iLen )//数据发送函数；
{
   if( strData == NULL || iLen == 0 )
     return ERR_BADPARAM;
   if( send( m_hSocket, strData, iLen, 0 ) == SOCKET_ERROR )
   {
     set_LastError( "send() failed", WSAGetLastError() );
     return ERR_WSAERROR;
   }
   return ERR_SUCCESS;
}
/////////////////////////////////////////////////////
int CMySocket::Receive( char* strData, int iLen )//数据接收函数；
{
   if( strData == NULL )
     return ERR_BADPARAM;
   int len = 0;
   int ret = 0;
   ret = recv( m_hSocket, strData, iLen, 0 );
   if ( ret == SOCKET_ERROR )
   {
     set_LastError( "recv() failed", WSAGetLastError() );
     return ERR_WSAERROR;
   }
   return ret;
}
void CMySocket::set_LastError( char* newError, int errNum )
file://WinSock API操作错误字符串设置函数；
{
   memset( m_LastError, 0, ERR_MAXLENGTH );
   memcpy( m_LastError, newError, strlen( newError ) );
   m_LastError[strlen(newError)+1] = '\0';
}

    有了上述类的定义，就可以在网络程序的服务器和客户端分别定义CMySocket对象，建立连接，传送数据了。例如，
    为了在服务器和客户端发送数据，需要在服务器端定义两个CMySocket对象ServerSocket1和ServerSocket2，分别
    用于监听和连接，客户端定义一个CMySocket对象ClientSocket，用于发送或接收数据，如果建立的连接数大于一，
    可以在服务器端再定义CMySocket对象，但要注意连接数不要大于五。

    由于Socket API函数还有许多，如获取远端服务器、本地客户机的IP地址、主机名等等，读者可以再此基础上对
    CMySocket补充完善，实现更多的功能。
    [编辑：邹妙君]
