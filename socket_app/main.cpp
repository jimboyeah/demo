#include <iostream>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")
/* Codeblocks project's linker setting on Win7 x64:
 * use mingw libws2_32.a
 * C:\Program Files (x86)\Visual C++ 6.0\VC98\Lib\WS2_32.LIB
 * C:\Program Files\Microsoft SDKs\Windows\v7.1\Lib\WS2_32.Lib
 * DOC: MSDN Platform SDK - Windows Sockets verson 2
 */

using namespace std;

#define HOST "127.0.0.1"
#define PORT 8080

char HTTPMSG[] = "HTTP/1.0 200 OK\r\n"
	"Server: Socket Tiny\r\n"
	"Date:Fri, 1 Feb 2016 00:29:55 GTM\r\n"
	"Content-Type: text/html\r\n"
	"Accept-Ranges: bytes\r\n"
	"Content-Length: 108\r\n"
	"\r\n"
	"<html><head><title>Socket Tiny</title></head>\r\n"
	"<body>\r\n"
	"<h1><center>It works!</center></h1>\r\n"
	"</body></html>\r\n\r\n";


int main()
{
    cout << "Hello Socket Server Programme!" << endl;


	cout << "#1 Startup" << endl;
    WSADATA wsaData;
    if( WSAStartup( MAKEWORD(2,2), &wsaData) != 0 )
    {
        cout << "WSAStartup fail to initialize" << endl;
        cout << "Error #" << WSAGetLastError() << endl;
        return 1;
    }


	cout << "#2 build a Socket" << endl;
    SOCKET skt = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(skt == INVALID_SOCKET){
        cout << "Socket fail to initialize";
        cout << "Error #" << WSAGetLastError() << endl;
    }


	cout << "#3 bind a Socket" << endl;
    sockaddr_in sai;
    sai.sin_family = AF_INET;
    sai.sin_addr.s_addr = inet_addr(HOST);
    sai.sin_port = htons(PORT);
    //sai.sin_zero = what?
    if ( bind( skt, (SOCKADDR*)&sai, sizeof(sai) ) == SOCKET_ERROR){
        cout << "Binding failed:" << endl;
        cout << "Error #" << WSAGetLastError() << endl;
    }


	cout << "#4 Lestening a Socket" << endl;
    if( listen( skt, 1 ) == SOCKET_ERROR ) {
        cout << "Lestening failed:";
        cout << "Error #" << WSAGetLastError() << endl;
    }

	cout << "#5 Accept client conection & comunication" << endl;
	cout << "Try to visit " << HOST << ":" << PORT << endl;
    //system("explorer.exe http://127.0.0.1:8080");

    /*
       Usually used a asynchronous service to notice our programme:
       int PASCAL FAR WSAAsyncSelect( SOCKET s, HWND hWnd, unsigned int wMsg, long lEvent );
     */
    sockaddr_in sai_client;
    int len = sizeof(sai_client);
	int ml = sizeof HTTPMSG;
    SOCKET skt_client = accept(skt, (SOCKADDR*)& sai_client, &len);
    if( skt_client != INVALID_SOCKET ){
        cout << "Client connected " << inet_ntoa(sai_client.sin_addr) << ":" << sai_client.sin_port;
        unsigned int hexaddr = static_cast<unsigned int>(sai_client.sin_addr.S_un.S_addr);
        cout << std::hex << " IPv 0x" << hexaddr << std::dec << endl;
    }
    if( skt_client == INVALID_SOCKET ){
        cout << "Acceptance failed:";
        cout << "Error #" << WSAGetLastError() << endl;
    }else if(ml != send( skt_client, HTTPMSG, ml, MSG_DONTROUTE) ){
		cout << "Message fail to send" << endl;
        cout << "Error #" << WSAGetLastError() << endl;
	}
    cout << ml << "bytes send" << endl;


    cout << "#6 Socket clean" << endl;
    shutdown( skt_client, SD_SEND);
	if( WSACleanup() == SOCKET_ERROR ){
        cout << "WSACleanup failed!";
        cout << "Error #" << WSAGetLastError() << endl;
    }

    return 0;
}
