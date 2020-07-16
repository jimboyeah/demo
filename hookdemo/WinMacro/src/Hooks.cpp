//This file is the most important one
//It contains code for recording and playing back messages

#include "hooks.h"
#include "winmacro.h"


#include "WinMacroDialog2.h"

//to indicate to UI that recording/playback has stopped
extern WinMacroDialog2 *dialog_ptr;

extern HWND thiswindow_hwnd;
//Are we playing back
extern BOOL playing_back;
//Are we recording
extern BOOL recording;

//Should we move to the next message (set when HC_SKIP is called)
static BOOL move_next=TRUE;
//To keep track of messages sent so far, used to produce time interval
static int mesg_count=0;
//How many times have we repeated playback
static int repeat_index=0;
//Is there another message to playback?
static BOOL next_message_exists=TRUE;


LRESULT CALLBACK JournalRecordProc(int code,WPARAM wparam,LPARAM lparam)
{
	//The recording callback hook function
	
	SHORT val=GetKeyState(VK_PAUSE);

	//If Pause/Break key is pressed, stop recording
	//The other key sequence to stop recording, Ctrl+Esc automatically evicts the hook
	//so all we have to do is update the UI accordingly, that code is there in
	//the GetMsgProc function
	if (val & 0x80000000)
	{
		dialog_ptr->StopRecording();
		return CallNextHookEx(hook_handle,code,wparam,lparam);
	}
	//if( val ) PostQuitMessage(0);
	
	EVENTMSG *mesg=NULL;
	
	switch (code)
	{
	case HC_ACTION:
		
		
		//The main part. HC_ACTION is called whenever there is a mouse or keyboard event.
		//lparam is a pointer to EVENTMSG struct, which contains the necessary information
		//to replay the message.
		
		
		mesg=(EVENTMSG *)lparam;
		
		//Ignore events on our window. Doesn't work :(
		if (mesg->hwnd!=thiswindow_hwnd)
		{
			//Subtract message tick count from the start of recording tick count
			//Subtracted value gives the relative delay between start of recording and
			//current message. We use this at playback to reproduce this delay.
			mesg->time=mesg->time-start_time;
			
			//Write out the EVENTMSG struct to file
			output->write((const char *)mesg,sizeof(EVENTMSG));
			output->flush();
		}
		
		
		break;
		
	default:
		return CallNextHookEx(hook_handle,code,wparam,lparam);
		
	}
	
	return 0;
}

LRESULT CALLBACK JournalPlaybackProc(int code,WPARAM wparam,LPARAM lparam)
{
	EVENTMSG *mesg;
	
	
	//Holds the struct read from file
	static EVENTMSG mesg_from_file;
	
	//To compute how much we need to sleep
	LRESULT delta;
	
	//Used to access the list sequentially when we are playing back from it.
	static POSITION list_position;
	
	//The playback callback hook function
	
	switch(code)
	{
	case HC_GETNEXT:
		
		
		//Like JournalRecordProc, this function also has the lparam, except that we must
		//supply the EVENTMSG structure. The system then rthe lparam, and uses the
		//info in the EVENTMSG to replay the message.
		
		mesg=(EVENTMSG *)lparam;
		
		//HC_GETNEXT can be called as many times as the system wants, we have to supply the
		//same message. Only when HC_SKIP is called, we can advance to the next message in our
		//file. move_next is the BOOL variable that takes care of this.
		if (move_next)
		{
			
			//If no repeat and we have not reached EOF
			//or with repeat and repeat_index has not yet reached repeatcount
			if (next_message_exists)
			{
				
				
				//Read next message
				//From file if we are playing back the first time
				if (repeat_index==0)
				{
					input->read((char *)&mesg_from_file,sizeof(EVENTMSG));
					//If this is EOF, reset next_message_exists
					if (input->eof()) next_message_exists=FALSE;
					
					
					//Add it message list so that we can use this as cache
					//Only if we need to repeat playback
					if (repeat_count)
					{
						message_list->AddTail(mesg_from_file);
					}
				}
				//We're playing back from the list now.
				else
				{
					//If we've not reached the end of the list
					if (list_position!=NULL)
					{
						//Read next struct
						mesg_from_file=message_list->GetNext(list_position);
					}
					else
					{
						next_message_exists=FALSE;
					}
					
				}	
				
			}
			else
			{
				//We have played back all messages and that's why next_message_exists
				//had been set to false. 
				
				//If we've repeated playback enough times
				if (repeat_index>=repeat_count)
				{
					//Remove the hook, close the file handle
					//and reset playing_back, 
					uninstall_playback_hook();
					MessageBox(thiswindow_hwnd,"Playback Over","WinMacro v1.2",MB_OK|MB_ICONEXCLAMATION);
					return 0;
				}
				else
				{
					repeat_index++;
				
					//Re initialize start_time to current tick count so that messages can be played back
					//with the same delays between them.
					start_time=GetTickCount();
					
					//Reset everything else
					mesg_count=0;
					move_next=TRUE;
					next_message_exists=TRUE;

					//Initialize list position to start of list
					list_position=message_list->GetHeadPosition();
					
					//Clear Keyboard state (remove control,alt or other key presses)
					BYTE keyboard_state[256];
					GetKeyboardState(keyboard_state);
					keyboard_state[VK_CONTROL]=keyboard_state[VK_CONTROL] & 0x00000000;
					keyboard_state[VK_MENU]=keyboard_state[VK_MENU] & 0x00000000;

					SetKeyboardState(keyboard_state);
	
					
					//Set flag variable to indicate we are playing back.  This is needed because a click to the "Stop Recording" button 
					//of this application is also stored when recording. When the file is played back, that button gets clicked again, but this 
					//time "Start Recording" gets clicked,(because it's playing back, not recording). This unfortunately causes recording to begin
					//again. Took lots of time to figure this out :)
					playing_back=TRUE;
	
				}
				return 0;
			}
			
			//This is so that the same message is sent, until HC_SKIP is called
			move_next=FALSE;
			
		}
		
		//Copy mesg from file to the lparam structure (which has been typecast)
		mesg->hwnd=mesg_from_file.hwnd ;
		mesg->message=mesg_from_file.message ;
		mesg->paramH=mesg_from_file.paramH ;
		mesg->paramL=mesg_from_file.paramL ;
		
		//Whatever the option (user defined interval or normal)
		//initialize mesg time with start_time
		//if user defined, add it with the specified time times mesg count
		//Simply supplying time_interval is not going to work because it then adds time_interval
		//with every event, resulting in only the first event getting delayed by time_interval,
		//For eg, Assuming constant time_interval of 50
		 //if start_time is 100, then first message is fired at 150
		//so a delay of 50 is there.Current time now becomes 150. Now next message is also fired at
		//150, it never goes past that. So we multiply time_interval with mesg_count, so the second
		//message is scheduled at 100+2*50 or 200, so that at 150, a delay of 50 (200-150) is created.
		//aaaaaah. Relax now.

		mesg->time =start_time+time_interval*mesg_count;

		//Check whether user has selected normal speed or given his own speed
		if (normal_speed || add_to_recorded_time )
		{
			//If playing at normal speed or if time_interval is to be added to recorded time
			//add it with time from the stored message from file.
			mesg->time+=mesg_from_file.time;
			
			
		}
		
		//This measures the difference between when mesg is to played and current time.
		
		delta=mesg->time-GetTickCount();
		
		
		//If more than zero (ie mesg is to played some time in the future)
		// return that time. The system sleeps for that time, before
		//calling HC_GETNEXT again, in which case, delta will be <=0, and we return 0.
		//The system then plays that message.
		if (delta>0)
		{
			
			return delta;
		}
		else
		{
			return 0;
		}

		break;
	
	case HC_SKIP:
		//Move to the next message
		move_next=TRUE;
		mesg_count++;

	

		break;
	default:
			return CallNextHookEx(hook_handle,code,wparam,lparam);
	}
	//System ignores this. Just to satisfy the compiler.
	return 0;
}


LRESULT CALLBACK GetMsgProc(int code, WPARAM wparam, LPARAM lparam)
{
	//This hook is needed to respond to Ctrl+Break or Ctrl+Esc or Ctrl+Alt+Del
	//which is used when the user wants to stop recording or playing back.
	//The system removes the hook anyway, but WinMacro will not be aware of that
	//so we need to watch for all messages and see if WM_CANCELJOURNAL is sent.
	//If so, we need to change our UI state to indicate recording/playback has 
	//been cancelled. I've also removed the hook, but itsn't necessary, the system
	//does it.

	if (code <0)
	{
		return CallNextHookEx(getmsg_hook_handle,code,wparam,lparam);
	}
	if (code==HC_ACTION)
	{
		MSG *msg=(MSG *)lparam;
			
		
		if (msg->message==WM_CANCELJOURNAL)
		{
				
			//If user interrupted playback. 
			if (playing_back)
			{
				uninstall_playback_hook();

				MessageBox(thiswindow_hwnd,"Playback Interrupted","WinMacro v1.2",MB_OK|MB_TASKMODAL|MB_ICONEXCLAMATION);
				
			}
			else if (recording)
			{
				//Indicate that recording must stop.
				dialog_ptr->StopRecording();
				
			}
				
		}

	}
	else
	{
		return CallNextHookEx(getmsg_hook_handle,code,wparam,lparam);
	}
return 0;
}

//A utility function that removes the playback hook
void uninstall_playback_hook()
{
	UnhookWindowsHookEx(hook_handle);
	playing_back=FALSE;
	repeat_index=0;

	
	input->close();
	
	//Call this so that app is restored from taskbar
	dialog_ptr->FinishedPlayback();
	
	mesg_count=0;
	move_next=TRUE;
	next_message_exists=TRUE;
	
	
}