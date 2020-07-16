#include <fstream>
#include <afxtempl.h>

DWORD start_time;

HINSTANCE hinstance;

HHOOK hook_handle;
HHOOK getmsg_hook_handle;

std::fstream *output;
std::fstream *input;

CList<EVENTMSG,EVENTMSG> *message_list;

BOOL add_to_recorded_time=TRUE;
BOOL normal_speed=TRUE;
int time_interval=0;
int repeat_count=0;

