
����Visual C++��Winsock API�о�
http://tech.163.com/05/1009/13/1VKHINQ200091589.html

* ��Windowsƽ̨ʹ��Winsocket������������ʱҪ����ͷ�ļ��Ϳ��ļ����£�

����Winsocket 1.1�汾
#include<winsock.h>
#pragma comment(lib, "wsock32.lib")

����Winsocket 2.2�汾
#include<winsock2.h>
#pragma comment(lib, "ws2_32.lib")


[������Ϣ]
    ����:�� �� ʱ��:2003-01-02 ����:yesky ���α༭:����
[���µ���]
    Ϊ�˷��������̣�90���������Microsoft�������������ҹ�˾��ͬ�ƶ���һ��WINDOWS�µ������̽ӿڣ�
    ��Windows Sockets�淶��������һ������Э��,����һ�׿��ŵġ�֧�ֶ���Э���Windows�µ������̽ӿڡ�
    ���ڵ�Winsock�Ѿ�������ʵ������Э���޹أ������ʹ��Winsock�����ö���Э��Ĺ��ܣ����ϳ�ʹ�õ���
    TCP/IPЭ�顣Socketʵ���ڼ�������ṩ��һ��ͨ�Ŷ˿ڣ�����ͨ������˿����κ�һ������Socket�ӿڵ�
    �����ͨ�š�Ӧ�ó����������ϴ��䣬���յ���Ϣ��ͨ�����Socket�ӿ���ʵ�֡�

    ΢��ΪVC������Winsock����CAsyncSocket���������CAsyncSocket ��CSocket�࣬���Ǽ����ã���������
    ��Ȼ����ʹ����Щ����ʵ���Լ���������򣬵���Ϊ�˸��õ��˽�Winsock API��̼�������������̽������
    ʹ�õײ��API����ʵ�ּ򵥵� Winsock ����Ӧ�ó�ʽ��ƣ��ֱ�˵�������Server�˺�Client�˲���Socket��
    ʵ�ֻ���TCP/IP�����ݴ��ͣ���������ص�Դ���롣

    ��VC�н���WINSOCK��API��̿�����ʱ����Ҫ����Ŀ��ʹ�����������ļ����������ֱ������

    1��WINSOCK.H: ����WINSOCK API��ͷ�ļ�����Ҫ��������Ŀ�С�
    2��WSOCK32.LIB: WINSOCK API���ӿ��ļ�����ʹ���У�һ��Ҫ������Ϊ��Ŀ�ķ�ȱʡ�����ӿ��������Ŀ�ļ���ȥ��
    3��WINSOCK.DLL: WINSOCK�Ķ�̬���ӿ⣬λ��WINDOWS�İ�װĿ¼�¡�

[�������˲��� socket���׽��֣�]
    1)�ڳ�ʼ���׶ε���WSAStartup()
    �˺�����Ӧ�ó����г�ʼ��Windows Sockets DLL ��ֻ�д˺������óɹ���Ӧ�ó���ſ����ٵ�������
    Windows Sockets DLL�е�API�������ڳ�ʽ�е��øú�������ʽ���£�

    WSAStartup((WORD)((1<<8|1)����LPWSADATA��&WSAData);
    if( WSAStartup( MAKEWORD(2,2), &wsaData) != 0 ) printf( "WSAStartup �޷���ʼ����");

    ����(1<<8|1)��ʾ�����õ���WinSocket1.1�汾��WSAata�����洢ϵͳ���صĹ���WinSocket�����ϡ�

    2)����Socket
    ��ʼ��WinSock�Ķ�̬���ӿ����Ҫ�ڷ������˽���һ��������Socket��Ϊ�˿��Ե���Socket()������������
    ���������Socket���������Socket��ʹ�õ�ͨ��Э�顣�˺������óɹ�����Socket����ʧ���򷵻�INVALID_SOCKET
    ����WSAGetLastError()�ɵ�֪ԭ������WinSocket �ĺ���������ʹ�������������ȡʧ�ܵ�ԭ��

    SOCKET PASCAL FAR socket( int af, int type, int protocol )
    ����:
    af:Ŀǰֻ�ṩ PF_INET(AF_INET)��
    type��Socket ������ (SOCK_STREAM��SOCK_DGRAM)��
    protocol��ͨѶЭ��(���ʹ���߲�ָ������Ϊ0)��

    ���Ҫ�����������TCP/IPЭ���socket���ڶ�������typeӦΪSOCK_STREAM����ΪUDP�����ݱ�����socket��ӦΪSOCK_DGRAM��

    3)�󶨶˿�
    ������ҪΪ�������˶�������������Socketָ��һ����ַ���˿ڣ�Port���������ͻ��˲�֪������Ҫ������
    һ����ַ���ĸ��˿ڣ�Ϊ������Ҫ����bind()�������ú������óɹ�����0�����򷵻�SOCKET_ERROR��

    int PASCAL FAR bind( SOCKET s, const struct sockaddr FAR *name,int namelen );
    �� ����
    s��Socket��������
    name��Socket�ĵ�ֵַ�������ַ������ִ�������ʽ���ڻ�����IP��ַ��
    namelen��name�ĳ��ȣ�

    ���ʹ���߲������ַ��˿ڵ�ֵ����ô�����趨��ַΪINADDR_ANY����PortΪ0��Windows Sockets ���Զ�����
    �趨�ʵ�֮��ַ��Port (1024 �� 5000֮���ֵ)���˺���Ե���getsockname()��������֪�䱻�趨��ֵ��

    4������
    ���������˵�Socket��������֮��,�������˱��뽨��һ�������Ķ��������տͻ��˵���������listen()����
    ʹ�������˵�Socket �������״̬�����趨���Խ��������������(Ŀǰ���ֵ����Ϊ 5, ��СֵΪ1)���ú�������
    �ɹ�����0�����򷵻�SOCKET_ERROR��

    int PASCAL FAR listen( SOCKET s, int backlog );
    �� ����
    s����Ҫ����������Socket��
    backlog��������Ӹ�����
    �������˵�Socket������listen()�������ʱ�ͻ��˵���connect()���������������Ļ���Server �˱�����
    ����accept()�����������������˺Ϳͻ��˲�����ʽ���ͨ�ų�������Ӷ�����Ϊ��֪��ʲôʱ��ͻ��������
    ��Ҫ�󣬴Ӷ��������˵�Socket��ǡ����ʱ�����accept()����������ӵĽ��������Ǿ�Ҫʹ��WSAAsyncSelect()
    ��������ϵͳ������֪ͨ�����пͻ���������������ˡ��ú������óɹ�����0�����򷵻�SOCKET_ERROR��

    int PASCAL FAR WSAAsyncSelect( SOCKET s, HWND hWnd,unsigned int wMsg, long lEvent );
    ������
    s��Socket ����
    hWnd��������Ϣ�Ĵ��ھ����
    wMsg���������ڵ���Ϣ��
    lEvent����ע��������¼���Ҳ����Ӧ�ó����򴰿ڷ�����Ϣ����·�¼�����ֵΪ����ֵFD_READ��FD_WRITE��
    FD_OOB��FD_ACCEPT��FD_CONNECT��FD_CLOSE����ϣ�����ֵ�ľ��庬��Ϊ
    FD_READ��ϣ�����׽���S�յ�����ʱ�յ���Ϣ��
    FD_WRITE��ϣ�����׽���S�Ͽ��Է�������ʱ�յ���Ϣ��
    FD_ACCEPT��ϣ�����׽���S���յ���������ʱ�յ���Ϣ��
    FD_CONNECT��ϣ�����׽���S�����ӳɹ�ʱ�յ���Ϣ��
    FD_CLOSE��ϣ�����׽���S�����ӹر�ʱ�յ���Ϣ��
    FD_OOB��ϣ�����׽���S���յ���������ʱ�յ���Ϣ��
    ����Ӧ��ʱ��wMsgӦ����Ӧ�ó����ж������Ϣ���ƣ�����Ϣ�ṹ�е�lParam��Ϊ���ϸ��������¼����ơ����ԣ�
    �����ڴ��ڴ����Զ�����Ϣ������ʹ�����½ṹ����ӦSocket�Ĳ�ͬ�¼���

    switch(lParam){
        case FD_READ:
            ��
        break;
        case FD_WRITE:
            ��
        break;
            ��
    }

    5���������˽��ܿͻ��˵���������
    ��Client�����������ʱ��Server ��hwnd�Ӵ����յ�Winsock Stack���������Զ����һ����Ϣ����ʱ��
    ���ǿ��Է���lParam��Ȼ�������صĺ�����������¼���Ϊ��ʹ�������˽��ܿͻ��˵��������󣬾�Ҫ
    ʹ��accept() �������ú����½�һSocket��ͻ��˵�Socket��ͨ��ԭ�ȼ���֮Socket�����������״̬��
    �ȴ����˵�����Ҫ�󡣸ú������óɹ�����һ���²�����Socket���󣬷��򷵻�INVALID_SOCKET��

    SOCKET PASCAL FAR accept( SCOKET s, struct sockaddr FAR *addr,int FAR *addrlen );
    ������
    s��Socket��ʶ���룻
    addr����������ӵĿͻ��˵ĵ�ַ��
    addrlen��addr�ĳ���

    6������ socket ����
    �����������Ϳͻ��˵�ͨ�������Ǻܼ򵥵ģ���һ���̿����ɷ�������ͻ�������һ��������ֻҪ����
    closesocket()�Ϳ����ˣ��ر�Server�˼���״̬��socket��ͬ��Ҳ�����ô˺��������⣬���������ʱ
    ����WSAStartup()�������Ӧ����ʽ����ǰ����Ҫ���� WSACleanup() ��֪ͨWinsock Stack�ͷ�Socket
    ��ռ�õ���Դ���������������ǵ��óɹ�����0�����򷵻�SOCKET_ERROR��

    int PASCAL FAR closesocket( SOCKET s );
    �� ����
    s��Socket ��ʶ���룻

    int PASCAL FAR WSACleanup( void );
    �� ���� ��

[�����ͻ���Socket�Ĳ���]
    1�������ͻ��˵�Socket
    �ͻ���Ӧ�ó�������Ҳ�ǵ���WSAStartup() ��������Winsock�Ķ�̬���ӿ⽨����ϵ��Ȼ��ͬ������socket()
    ������һ��TCP��UDP socket����ͬЭ���� sockets ������ͨ��TCP �� TCP��UDP �� UDP����������˵�socket
    ��ͬ���ǣ��ͻ��˵�socket ���Ե��� bind() ���������Լ���ָ��IP��ַ��port���룻����Ҳ���Բ����� bind()��
    ���� Winsock���Զ��趨IP��ַ��port���롣

    2�������������
    �ͻ��˵�Socketʹ��connect()�����������������˵�Socket�������ӵ����룬�������óɹ�����0�����򷵻�SOCKET_ERROR��

    int PASCAL FAR connect( SOCKET s, const struct sockaddr FAR *name, int namelen );
    �� ����
    s��Socket ��ʶ���룻
    name��Socket��Ҫ���ӵĶԷ���ַ��
    namelen��name�ĳ���

[�������ݵĴ���]
    ��Ȼ����TCP/IP����Э�飨���׽��֣��ķ�������ƿͻ���/������Ӧ�ó���ʱ��������׼������Щ����Ҳ��
    ����ͨ��������Э�飨���ݱ��׽��֣��ṩ�ġ��Ƚ���һ��TCP socket ��UDP socket �ڴ�������ʱ�����ԣ�
    Stream (TCP) Socket �ṩ˫�򡢿ɿ����д��򡢲��ظ������ϴ��͡�
    Datagram (UDP) Socket ��Ȼ�ṩ˫���ͨ�ţ���û�пɿ����д��򡢲��ظ��ı�֤������UDP�������ݿ���
    ���յ��޴����ظ������ϣ����������ڴ�������г�����©������UDP Socket �ڴ�������ʱ��������֤����
    ���������ʹ�Է������Ծ������Ӧ�ó����ǲ���TCP����Socket���Ա�֤���ϵ���ȷ�ԡ�һ�������
    TCP Socket �����ݷ��ͺͽ����ǵ���send() ��recv() ��������������ɣ�
    UDP Socket ������sendto() ��recvfrom() �������������������������óɹ����ӷ��ͻ���յ����ϵĳ��ȣ�
    ���򷵻�SOCKET_ERROR��

    int PASCAL FAR send( SOCKET s, const char FAR *buf, int len, int flags );
    ������
    s��Socket ��ʶ����
    buf�����Ҫ���͵����ϵ��ݴ���
    len��buf�ĳ���
    flags���˺��������õķ�ʽ

    int PASCAL FAR recv( SOCKET s, char FAR *buf, int len, int flags );
    ������
    s��Socket ��ʶ����
    buf����Ž��յ������ϵ��ݴ���
    len��buf�ĳ���
    flags���˺��������õķ�ʽ

    ����Datagram Socket���ԣ����� datagram �Ĵ�С�������ƣ��򽫲����ͳ��κ����ϣ����ᴫ�ش���ֵ��
    ��Stream Socket �ԣ�Blocking ģʽ�£����Ǵ���ϵͳ�ڵĴ���ռ䲻�������ЩҪ���͵����ϣ�send()
    ���ᱻblockס��ֱ����������Ϊֹ�������Socket���趨Ϊ Non-Blocking ģʽ����ô����Ŀǰ��output buffer
    �ռ��ж��٣����ͳ��������ϣ������ᱻ block ס��flags ��ֵ����Ϊ 0 �� MSG_DONTROUTE�� MSG_OOB ����ϡ�

    ��Stream Socket �ԣ����ǿ��Խ��յ�Ŀǰinput buffer����Ч�����ϣ���������������len�Ĵ�С��

[�ġ��Զ����CMySocket���ʵ��]
    ���������֪ʶ�����Զ�����һ���򵥵�CMySocket�࣬�������Ҷ���ĸ���Ĳ���ʵ�ִ��룺

//////////////////////////////////////
CMySocket::CMySocket() : file://��Ĺ��캯��
{
   WSADATA wsaD;
   memset( m_LastError, 0, ERR_MAXLENGTH );
   // m_LastError�������ַ�������,��ʼ���������������˵�����ַ�����
   // ��ʼ������sockaddr_in�ṹ������ǰ�ߴ�ſͻ��˵�ַ�����߶�Ӧ�ڷ������˵�ַ;
   memset( &m_sockaddr, 0, sizeof( m_sockaddr ) );
   memset( &m_rsockaddr, 0, sizeof( m_rsockaddr ) );
   int result = WSAStartup((WORD)((1<<8|1)�� &wsaD);//��ʼ��WinSocket��̬���ӿ�;
   if( result != 0 ) // ��ʼ��ʧ�ܣ�
   { set_LastError( "WSAStartup failed!", WSAGetLastError() );
     return;
   }
}

//////////////////////////////
CMySocket::~CMySocket() { WSACleanup(); }//�������������
////////////////////////////////////////////////////
int CMySocket::Create( void )
   {// m_hSocket������Socket���󣬴���һ������TCP/IP��Socket����������ֵ�����ñ�����
     if ( (m_hSocket = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP )) == INVALID_SOCKET )
     {
       set_LastError( "socket() failed", WSAGetLastError() );
       return ERR_WSAERROR;
     }
     return ERR_SUCCESS;
   }
///////////////////////////////////////////////
int CMySocket::Close( void )//�ر�Socket����
{
   if ( closesocket( m_hSocket ) == SOCKET_ERROR )
   {
     set_LastError( "closesocket() failed", WSAGetLastError() );
     return ERR_WSAERROR;
   }
   file://����sockaddr_in �ṹ������
   memset( &m_sockaddr, 0, sizeof( sockaddr_in ) );
   memset( &m_rsockaddr, 0, sizeof( sockaddr_in ) );
   return ERR_SUCCESS;
}
/////////////////////////////////////////
int CMySocket::Connect( char* strRemote, unsigned int iPort )//�������Ӻ�����
{
   if( strlen( strRemote ) == 0 || iPort == 0 )
     return ERR_BADPARAM;
   hostent *hostEnt = NULL;
   long lIPAddress = 0;
   hostEnt = gethostbyname( strRemote );//���ݼ�������õ��ü������������ݣ�
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
int CMySocket::Bind( char* strIP, unsigned int iPort )//�󶨺�����
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
int CMySocket::Accept( SOCKET s )//�������Ӻ�����SΪ����Socket��������
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
file://�¼�ѡ������
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
int CMySocket::Listen( int iQueuedConnections )//����������
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
int CMySocket::Send( char* strData, int iLen )//���ݷ��ͺ�����
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
int CMySocket::Receive( char* strData, int iLen )//���ݽ��պ�����
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
file://WinSock API���������ַ������ú�����
{
   memset( m_LastError, 0, ERR_MAXLENGTH );
   memcpy( m_LastError, newError, strlen( newError ) );
   m_LastError[strlen(newError)+1] = '\0';
}

    ����������Ķ��壬�Ϳ������������ķ������Ϳͻ��˷ֱ���CMySocket���󣬽������ӣ����������ˡ����磬
    Ϊ���ڷ������Ϳͻ��˷������ݣ���Ҫ�ڷ������˶�������CMySocket����ServerSocket1��ServerSocket2���ֱ�
    ���ڼ��������ӣ��ͻ��˶���һ��CMySocket����ClientSocket�����ڷ��ͻ�������ݣ��������������������һ��
    �����ڷ��������ٶ���CMySocket���󣬵�Ҫע����������Ҫ�����塣

    ����Socket API����������࣬���ȡԶ�˷����������ؿͻ�����IP��ַ���������ȵȣ����߿����ٴ˻����϶�
    CMySocket�������ƣ�ʵ�ָ���Ĺ��ܡ�
    [�༭�������]
