#pragma once
#ifndef BASE_H
#define BASE_H

#include <stdlib.h>
#include <stdio.h>

#if defined(NULL)
	#undef NULL
#endif

#if defined(__cplusplus)
	#define NULL 0
#else
	#define NULL ((void*)0)
#endif

#if defined(WIN32) && !defined(UNIX)
    #include <wchar.h>
    typedef wchar_t char_t;
    #define STR(str) L ## str
    #define CH(ch) L ch
    #define print(str) wprintf(L"%s\n", str)
#elif defined(UNIX) && !defined(WIN32)
    typedef char char_t;
    #define STR(str) str
    #define CH(ch) ch
    #define print(str) printf("%s\n", str)
#else
    typedef char char_t;
    #define STR(str) str
    #define CH(ch) ch
    #define print(str) printf("%s\n", str)
#endif

#endif
