/*
 * Timer in console Demo by Jimbowhy
 * compiler:
   g++ -o setTimer setTimer.cpp -lwinmm && settimer
 */

#define _WIN32_WINNT 0x0400 // used for CreateWaitableTimer()

#include <cstdio>
#include <windows.h>
#include <winbase.h>
#include <mmsystem.h>

#pragma comment( lib, "Winmm.lib" )


typedef HWND (WINAPI *TGetConsoleWindow)();
HWND GetConsoleWin()
{
    HMODULE hKernel32 = GetModuleHandle("kernel32");
    TGetConsoleWindow f = (TGetConsoleWindow)GetProcAddress(hKernel32,"GetConsoleWindow");
    return f();
}

void CALLBACK TimerProc( HWND hwnd, UINT uMsg, UINT id, DWORD ms )
{
	PostMessage( NULL, WM_USER+3, 9, 8 );
	printf( "TimeProc callback \n" );
}

void CALLBACK TimeSetProc( UINT uID, UINT uMsg, DWORD dwUser, DWORD dw1, DWORD dw2 )
{
	static int count;
	if(count++>9) return;
	PostMessage( NULL, WM_USER+2, 9, 8 );
	printf( "TimeSet callback %x \t",dwUser );
}

ULONG WINAPI thread( PVOID pv ){
    MSG msg;
	printf( "thread run %d \n", *(int*)pv );

	HWND hwnd = GetConsoleWin();
    SetTimer( hwnd, 0, 500, &TimerProc ); // GetLastError 5 Access is denied
	printf( "GetLastError %d", GetLastError() );
    unsigned int timer = SetTimer(0, 0, 500, &TimerProc);
    unsigned int tmm = SetTimer(0, 0, 500, NULL); // use WM_TIMER only
	//KillTimer(timer);

    MMRESULT mm = timeSetEvent( 10,0,TimeSetProc,0xABCD,TIME_PERIODIC);

    while(GetMessage(&msg,NULL,0,0))
    {
		switch( msg.message ){
			case WM_TIMER:  printf( "WM_TIMER\t"); break;
			case WM_USER+3: printf( "WM_USER+3\t"); break;
			case WM_USER+2: printf( "WM_USER+2\t"); break;
		}
        DispatchMessage(&msg);
    }
	return 0;
}

int main()
{	
	DWORD tid;

	printf( "Use Timers in console \n" );

	int p = 999;
	HANDLE h = CreateThread( NULL, 0, thread, &p, 0, &tid );
	DWORD  w = WaitForSingleObject(h,1000*3);
	switch(w)   
	{   
	case   WAIT_ABANDONED:   
		  printf("WaitForSingleObject => WAIT_ABANDONED\n");   
		  break;   
	case   WAIT_OBJECT_0:   
		  printf("WaitForSingleObject => WAIT_OBJECT_0\n");   
		  break;   
	case   WAIT_TIMEOUT:   
		  printf("WaitForSingleObject => WAIT_TIMEOUT\n");   
		  break;   
	}   
	CloseHandle(h);

	int periodic = 1000;
	LARGE_INTEGER li;
	li.QuadPart = -30000000; // 3s, in 100 nanosecond intervals
	HANDLE timer = CreateWaitableTimer( NULL,true, "Waitable" );
	SetWaitableTimer( timer,&li,periodic,NULL,NULL,true );
	if( WaitForSingleObject( timer, INFINITE) == WAIT_OBJECT_0 ){
		printf( "WaitForSingleObject Final \n" );
	}
	CloseHandle(timer);

	return 0;
}
