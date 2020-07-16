;#ifndef __MESSAGES_H__
;#define __MESSAGES_H__

;////////////////////////////////////////
;// Header Section
;//
LanguageNames =
    (
        English = 0x0409:Resource_ENU
        Chinese = 0x0804:Resource_CHS
        Taiwan  = 0x0404:Resource_CHT
        German  = 0x0407:Resource_GER
    )

;////////////////////////////////////////
;// Message Definitions - Eventlog categories
;//
MessageId       = 1
SymbolicName    = CATEGORY_ONE
Severity        = Success

Language        = English
First category event
.
Language        = German
Ereignis erster Kategorie
.
Language        = Chinese
事件消息
.
Language        = Taiwan
事件消息
.

MessageId       = +1
SymbolicName    = CATEGORY_TWO
Severity        = Success

Language        = English
Second category event
.
Language        = German
Ereignis zweiter Kategorie
.
Language        = Chinese
另一事件消息
.
Language        = Taiwan
另一事件消息
.

;////////////////////////////////////////
;// Message Definitions - Events
;//

MessageId       = +1
SymbolicName    = EVENT_STARTED_BY

Language        = English
The app %1 has been started by user %2
.
Language        = German
Der Benutzer %2 konnte das Programm %1 erfolgreich starten
.
Language        = Chinese
程序 %1 已经由 %2 用户启动
.
Language        = Taiwan
程序 %1 已經由 %2 用戶啟動
.

MessageId       = +1
SymbolicName    = EVENT_BACKUP

Language        = English
You should backup your data regulary!
.
Language        = German
Sie sollten Ihre Daten regelm??ig sichern!
.
Language        = Chinese
是时候做备份了!
.
Language        = Taiwan
是時候做備份了！
.

;
;#endif  //__MESSAGES_H__
;
