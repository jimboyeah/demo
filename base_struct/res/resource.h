#ifndef __MESSAGES_H__
#define __MESSAGES_H__
////////////////////////////////////////
// Header Section
//
////////////////////////////////////////
// Message Definitions - Eventlog categories
//
//
//  Values are 32 bit values layed out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +---+-+-+-----------------------+-------------------------------+
//  |Sev|C|R|     Facility          |               Code            |
//  +---+-+-+-----------------------+-------------------------------+
//
//  where
//
//      Sev - is the severity code
//
//          00 - Success
//          01 - Informational
//          10 - Warning
//          11 - Error
//
//      C - is the Customer code flag
//
//      R - is a reserved bit
//
//      Facility - is the facility code
//
//      Code - is the facility's status code
//
//
// Define the facility codes
//


//
// Define the severity codes
//


//
// MessageId: CATEGORY_ONE
//
// MessageText:
//
//  First category event
//
#define CATEGORY_ONE                     0x00000001L

//
// MessageId: CATEGORY_TWO
//
// MessageText:
//
//  Second category event
//
#define CATEGORY_TWO                     0x00000002L

////////////////////////////////////////
// Message Definitions - Events
//
//
// MessageId: EVENT_STARTED_BY
//
// MessageText:
//
//  The app %1 has been started by user %2
//
#define EVENT_STARTED_BY                 0x00000003L

//
// MessageId: EVENT_BACKUP
//
// MessageText:
//
//  You should backup your data regulary!
//
#define EVENT_BACKUP                     0x00000004L


#endif  //__MESSAGES_H__

