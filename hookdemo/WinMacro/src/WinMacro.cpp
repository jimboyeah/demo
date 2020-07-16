//This file is the starting point while running
//UI is shown from the InitInstance() method

#include <afxwin.h>
#include <fstream>


#include "hooks.h"
#include "WinMacroDialog2.h"

extern HHOOK getmsg_hook_handle;
extern HINSTANCE hinstance;

class myapp:public CWinApp
{
public:
	int InitInstance()
	{
		hinstance=m_hInstance ;
		
		//Install the GetMsgProc hook to monitor system messages
		//so that we can capture WM_CANCELJOURNAL message when the user
		//presses Ctrl+Esc to stop Recording/Playback
		getmsg_hook_handle=SetWindowsHookEx(WH_GETMESSAGE,GetMsgProc,hinstance,0);
		
		WinMacroDialog2 dialog;
		m_pMainWnd=(CWnd *)&dialog;
		dialog.m_initialPath = m_lpCmdLine;
		dialog.DoModal();
		
		return 1;
	}
};

myapp a;


