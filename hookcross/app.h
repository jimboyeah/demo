#ifndef hookcross_app
#define hookcross_app

int WINAPI WinMain(HINSTANCE hApp, HINSTANCE hPre, LPSTR lpLine, int iCmd );
void CALLBACK TimerProc(HWND hwin, UINT uMsg, UINT id, DWORD t);
LRESULT CALLBACK circle( HWND, UINT, WPARAM, LPARAM );
void SendToPad(const char * buf);
const char * byte2hex(byte *bytes);

#endif
