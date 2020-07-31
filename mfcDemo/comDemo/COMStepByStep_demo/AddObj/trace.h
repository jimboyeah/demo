#ifndef __TRACE_H__
#define __TRACE_H__

#ifdef DEBUG
    #include <stdio.h>
    #define trace(arg) printf(arg)
#else
    #define trace(arg) // arg
#endif

#endif