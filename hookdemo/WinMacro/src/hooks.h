#include <afxwin.h>

LRESULT CALLBACK JournalRecordProc(int code,WPARAM wparam,LPARAM lparam);
LRESULT CALLBACK JournalPlaybackProc(int code,WPARAM wparam,LPARAM lparam);

LRESULT CALLBACK GetMsgProc(int code,WPARAM wparam,LPARAM lparam);

//Utility function
void uninstall_playback_hook();