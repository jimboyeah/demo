Readme for WinMacro v1.2
*******************

 WinMacro is a simple Macro recorder/player for Windows written in Microsoft Visual C++ 6.0. It can record whatever you do at your Windows Desktop, and can replay them exactly. It doesn't record video, instead it uses windows hooking mechanisms to monitor your mouse and keyboard events, and plays them back. Therefore the recorded file is much smaller than what would be if you recorded live video, typically in the range of kilobytes. It looks exactly like all you're actions have been recorded by video though.

 This is the second version of the software, and comes with a cleaner (IHMO) UI ,adjustable playback speed, ability to repeat playback any no. of times.
 
 You can use it for automating a sequence of tasks, as a practical demonstration of an application, or for GUI testing. The source code is available from the website geocities.com/win_macro, so you're free to do whatever you want.



New in WinMacro v1.2
********************

Repeatable playback
--------------------
To repeat playback, check the "Repeat Playback" checkbox and type in the no. of times you want to repeat playback in the "No. of Repetitions" textbox. Remember, it's the number of repetitions, so if you type 1 in there, WinMacro will play back the file twice. 

Adjustable playback speed
-------------------------
   WARNING: Increasing playback speed may lead to unpredictable results. Please check the entire playback at increased speed once before doing
anything useful with it.

  WinMacro v1.2 comes with the ability to adjust playback rate.  To adjust playback speed, Click the Options button in the main WinMacro window. It
shows a dialog box. You can choose between
1. Playback At Recorded Speed
2. Playback at My Own Speed

 The first option plays back the file with the exact time interval between events as it happened while recording. This is the
default option. If you want to play back files faster or slower, choose the second option.

 Now enter the Time Interval value by which you want to speed or slow things up. Negative values indicate lesser time between
playback (and therefore faster playback) and positive values slow things down. 

BE WARNED though, speeding things up may
produce unpredictable results. For eg, if you opened an application and typed something in it while recording, it may replay correctly with the original delay, but at faster playback, the application may not open in time and keystrokes may be lost.

 The Add to Recorded Time is checked by default. This adds the Time Interval value you've specified WITH the original delay while recording. Unchecking this means that events playback with a constant Time Interval delay between them (which may be even more unpredictable).



Using WinMacro
***************

Using WinMacro is very simple, in fact, you can't go wrong anywhere.
If you are going to record,

1.Type the name of the file you want to record into, directly or by selecting it by clicking Browse.
2. Click the "Record" button. 
3.Do whatever you wanted to record.
4. Press Pause/Break (preferable) or Ctrl+Esc, when you are finished.



If you're going to playback

1. Type the name of the file you want to playback, directly or by selecting it by clicking Browse.
2. Click the "Playback" button.
3.The application then gets minimized to the taskbar, takes control of the mouse and keyboard and begins to play back the actions stored in the file. Once it's finished, a message box pops out, which says "Playback Over" and the application is restored back. The application returns control back to you.
4. If you ever wanted to interrupt playback (or recording), press Ctrl+Esc or Ctrl+Alt+Del.

That's all there is to it.

Bugs and Limitations
*********************
1. Ctrl+Alt+Del, Ctrl+Esc and Ctrl+Break keys break the recording or playing back process, by evicting the hook. That means you can't record or playback those keystrokes. But if WinMacro ever hangs, you can easily recover control by using any of those keystrokes.

2. The Windows key doesn't work properly with WinMacro. Trouble is, it gets recorded as  some other keystroke, and playing it back can give weird results. So you'd better move your mouse to the Start button than rely on the Windows key.

3. WinMacro is intelligent enough to recognise files it recorded, so you can't simply play any file. But if you ever fiddle with the recorded file yourselves, the application may hang. Of course, you can always use the keystrokes mentioned above to recover. 

4. And remember, WinMacro simply records mouse and keyboard messages. So if you have an application that opens up in different window coordinates everytime you open it, then your mouse actions on that window may not be played back correctly. Notepad on Windows 98 has this behaviour. It opened up on center screen while I was recording, and opened on the left corner of the desktop when I played back. As a result, my mouse clicks on the window didn't play back correctly. However, you wouldn't have any problem with keystrokes, and you can always use Alt+F4 to close any application :)


About the Author
***************
I'm S. Senthil Kumar and I've finished my B.E in Computer Science and Engineering from Thiagarajar College of Engineering, Madurai, TamilNadu, India. I'm interested and have decent knowledge in Java Programming (Client and Server Side), MFC and windows hooking/subclassing. 

   It was just plain curiosity that drove me to write this application, curious to see the mouse and keyboard actions appearing all by themselves. But it turned out to be quite useful, and I figured it might be so for someone else too. I'm giving the source ,so you can use it any way you can imagine. 

   Your feedback, comments, anything.. can be sent to senthilkumar_tce@yahoo.com or win_macro@yahoo.co.in. Unlike so many other developers, I rarely receive any mail, so any feedback is welcome. 

Good luck.

You downloaded this from http://geocities.com/win_macro


