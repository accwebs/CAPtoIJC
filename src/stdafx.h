// Required header file (because this header is included by globalplatform.h on Win32)

#ifndef STDAFXH_INCLUDED
#define STDAFXH_INCLUDED

#ifdef WIN32
    #ifndef _UNICODE
    #define _UNICODE
    #endif
    #ifndef UNICODE
    #define UNICODE
    #endif
    #define WIN32_LEAN_AND_MEAN
    #include <windows.h>
    #include <tchar.h>
#endif

#endif