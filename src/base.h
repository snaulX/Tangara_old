// Based on https://github.com/electronicarts/EABase/blob/master/include/Common/EABase/eabase.h
#pragma once
#ifndef BASE_H
#define BASE_H

#if defined(NULL)
	#undef NULL
#endif

#if defined(__cplusplus)
	#define NULL 0
#else
	#define NULL ((void*)0)
#endif

#include <stdint.h>   // int32_t, INT64_C, UINT8_MAX, etc.
#include <math.h>     // float_t, double_t, etc.
#include <float.h>    // FLT_EVAL_METHOD.
#if defined(_MSC_VER)
	#pragma warning(pop)
#endif

#if !defined(FLT_EVAL_METHOD) && (defined(__FLT_EVAL_METHOD__) || defined(_FEVAL)) // GCC 3.x defines __FLT_EVAL_METHOD__ instead of the C99 standard FLT_EVAL_METHOD.
	#ifdef __FLT_EVAL_METHOD__
		#define FLT_EVAL_METHOD __FLT_EVAL_METHOD__
	#else
		#define FLT_EVAL_METHOD _FEVAL
	#endif
#endif
	
#if !defined(__BIT_TYPES_DEFINED__) && !defined(__byte_t_defined)
	typedef signed char             byte_t;             //< 8 bit signed integer
#endif
#if !defined( __byte_t_defined )
	typedef signed short            short_t;            //< 16 bit signed integer
	typedef signed int              int_t;            //< 32 bit signed integer. This works for both 32 bit and 64 bit platforms, as we assume the LP64 is followed.
	#define __byte_t_defined
#endif
	typedef unsigned char           ubyte_t;            //< 8 bit unsigned integer
	typedef unsigned short         ushort_t;            //< 16 bit unsigned integer
#if !defined( __uint_t_defined )
	typedef unsigned int           uint_t;            //< 32 bit unsigned integer. This works for both 32 bit and 64 bit platforms, as we assume the LP64 is followed.
	#define __uint_t_defined
#endif

#if !defined(__cplusplus)
	typedef byte_t bool;
	#define true 1
	#define false 0
#endif

// According to the C98/99 standard, FLT_EVAL_METHOD defines control the 
// width used for floating point _t types.
#if defined(_MSC_VER) && _MSC_VER >= 1800
	// MSVC's math.h provides float_t, double_t under this condition.
#elif defined(FLT_EVAL_METHOD)
	#if (FLT_EVAL_METHOD == 0)
		typedef float           float_t;
		typedef double          double_t;
	#elif (FLT_EVAL_METHOD == 1)
		typedef double          float_t;
		typedef double          double_t;
	#elif (FLT_EVAL_METHOD == 2)
		typedef long double     float_t;
		typedef long double     double_t;
	#endif
#endif

// ------------------------------------------------------------------------
// char8_t  -- Guaranteed to be equal to the compiler's char data type.
//             Some compilers implement char8_t as unsigned, though char 
//             is usually set to be signed.
//
// char16_t -- This is set to be an unsigned 16 bit value. If the compiler
//             has wchar_t as an unsigned 16 bit value, then char16_t is 
//             set to be the same thing as wchar_t in order to allow the 
//             user to use char16_t with standard wchar_t functions.
//
// char32_t -- This is set to be an unsigned 32 bit value. If the compiler
//             has wchar_t as an unsigned 32 bit value, then char32_t is 
//             set to be the same thing as wchar_t in order to allow the 
//             user to use char32_t with standard wchar_t functions.
//
// CHAR8_UNIQUE
// CHAR16_NATIVE
// CHAR32_NATIVE
// WCHAR_UNIQUE
//
// VS2010 unilaterally defines char16_t and char32_t in its yvals.h header
// unless _HAS_CHAR16_T_LANGUAGE_SUPPORT or _CHAR16T are defined. 
// However, VS2010 does not support the C++0x u"" and U"" string literals, 
// which makes its definition of char16_t and char32_t somewhat useless. 
// Until VC++ supports string literals, the build system should define 
// _CHAR16T and let us define char16_t and CHAR16.
//
// GCC defines char16_t and char32_t in the C compiler in -std=gnu99 mode, 
// as __CHAR16_TYPE__ and __CHAR32_TYPE__, and for the C++ compiler 
// in -std=c++0x and -std=gnu++0x modes, as char16_t and char32_t too.
//
// The WCHAR_UNIQUE symbol is defined to 1 if wchar_t is distinct from
// char8_t, char16_t, and char32_t, and defined to 0 if not. In some cases, 
// if the compiler does not support char16_t/char32_t, one of these two types 
// is typically a typedef or define of wchar_t. For compilers that support 
// the C++11 unicode character types often overloads must be provided to 
// support existing code that passes a wide char string to a function that 
// takes a unicode string.
//
// The CHAR8_UNIQUE symbol is defined to 1 if char8_t is distinct type 
// from char in the type system, and defined to 0 if otherwise.

#if !defined(CHAR16_NATIVE)
	#if defined(_MSC_VER) && (_MSC_VER >= 1600) && defined(_HAS_CHAR16_T_LANGUAGE_SUPPORT) && _HAS_CHAR16_T_LANGUAGE_SUPPORT // VS2010+
		#define CHAR16_NATIVE 1
	#elif defined(EA_COMPILER_CLANG) && defined(EA_COMPILER_CPP11_ENABLED)
		#if __has_feature(cxx_unicode_literals)
			#define CHAR16_NATIVE 1
		#elif (EA_COMPILER_VERSION >= 300) && !(defined(EA_PLATFORM_IPHONE) || defined(EA_PLATFORM_OSX))
			#define CHAR16_NATIVE 1
		#elif defined(EA_PLATFORM_APPLE)
			#define CHAR16_NATIVE 1 
		#else
			#define CHAR16_NATIVE 0
		#endif
	#elif defined(__EDG_VERSION__) && (__EDG_VERSION__ >= 404) && defined(__CHAR16_TYPE__) && defined(EA_COMPILER_CPP11_ENABLED)// EDG 4.4+.
		#define CHAR16_NATIVE 1
	#elif defined(EA_COMPILER_GNUC) && (EA_COMPILER_VERSION >= 4004) && !defined(EA_COMPILER_EDG) && (defined(EA_COMPILER_CPP11_ENABLED) || defined(__STDC_VERSION__)) // g++ (C++ compiler) 4.4+ with -std=c++0x or gcc (C compiler) 4.4+ with -std=gnu99
		#define CHAR16_NATIVE 1
	#else
		#define CHAR16_NATIVE 0
	#endif
#endif

#if !defined(CHAR32_NATIVE)                    // Microsoft currently ties char32_t language support to char16_t language support. So we use CHAR16_T here.
	// To do: Change this to be based on EA_COMPILER_NO_NEW_CHARACTER_TYPES.
	#if defined(_MSC_VER) && (_MSC_VER >= 1600) && defined(_HAS_CHAR16_T_LANGUAGE_SUPPORT) && _HAS_CHAR16_T_LANGUAGE_SUPPORT // VS2010+
		#define CHAR32_NATIVE 1
	#elif defined(EA_COMPILER_CLANG) && defined(EA_COMPILER_CPP11_ENABLED)
		#if __has_feature(cxx_unicode_literals)
			#define CHAR32_NATIVE 1
		#elif (EA_COMPILER_VERSION >= 300) && !(defined(EA_PLATFORM_IPHONE) || defined(EA_PLATFORM_OSX))
			#define CHAR32_NATIVE 1
		#elif defined(EA_PLATFORM_APPLE)
			#define CHAR32_NATIVE 1 
		#else
			#define CHAR32_NATIVE 0
		#endif
	#elif defined(__EDG_VERSION__) && (__EDG_VERSION__ >= 404) && defined(__CHAR32_TYPE__) && defined(EA_COMPILER_CPP11_ENABLED)// EDG 4.4+.
		#define CHAR32_NATIVE 1
	#elif defined(EA_COMPILER_GNUC) && (EA_COMPILER_VERSION >= 4004) && !defined(EA_COMPILER_EDG) && (defined(EA_COMPILER_CPP11_ENABLED) || defined(__STDC_VERSION__)) // g++ (C++ compiler) 4.4+ with -std=c++0x or gcc (C compiler) 4.4+ with -std=gnu99
		#define CHAR32_NATIVE 1
	#else
		#define CHAR32_NATIVE 0
	#endif
#endif


#if CHAR16_NATIVE || CHAR32_NATIVE
	#define WCHAR_UNIQUE 1
#else
	#define WCHAR_UNIQUE 0
#endif


// CHAR8_UNIQUE
//
// Check for char8_t support in the cpp type system. Moving forward from c++20,
// the char8_t type allows users to overload function for character encoding.   
//
// CHAR8_UNIQUE is 1 when the type is a unique in the type system and 
// can there be used as a valid overload. CHAR8_UNIQUE is 0 otherwise.
//
// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p0482r6.html
//
#ifdef __cpp_char8_t
	#define CHAR8_T_DEFINED
	#define CHAR8_UNIQUE 1
#else
	#define CHAR8_UNIQUE 0
#endif


#ifndef CHAR8_T_DEFINED // If the user hasn't already defined these...
	#define CHAR8_T_DEFINED
	#if defined(EA_PLATFORM_APPLE)
		#define char8_t char    // The Apple debugger is too stupid to realize char8_t is typedef'd to char, so we #define it.
	#else
		typedef char char8_t;
	#endif
	
	#if CHAR16_NATIVE
		// In C++, char16_t and char32_t are already defined by the compiler.
		// In MS C, char16_t and char32_t are already defined by the compiler/standard library.
		// In GCC C, __CHAR16_TYPE__ and __CHAR32_TYPE__ are defined instead, and we must define char16_t and char32_t from these.
		#if defined(__GNUC__) && !defined(__GXX_EXPERIMENTAL_CXX0X__) && defined(__CHAR16_TYPE__) // If using GCC and compiling in C...
			typedef __CHAR16_TYPE__ char16_t;
			typedef __CHAR32_TYPE__ char32_t;
		#endif
	#elif (WCHAR_SIZE == 2)
		#if (defined(_MSC_VER) && (_MSC_VER >= 1600)) // if VS2010+ or using platforms that use Dinkumware under a compiler that doesn't natively support C++11 char16_t.
			#if !defined(_CHAR16T)
				#define _CHAR16T
			#endif
			#if !defined(_HAS_CHAR16_T_LANGUAGE_SUPPORT) || !_HAS_CHAR16_T_LANGUAGE_SUPPORT
				typedef wchar_t  char16_t;
				typedef uint32_t char32_t;
			#endif
		#else
			typedef wchar_t  char16_t;
			typedef uint32_t char32_t;
		#endif
	#else
		typedef uint16_t char16_t;
		#if defined(__cplusplus)
			typedef wchar_t  char32_t;
		#else
			typedef uint32_t char32_t;
		#endif
	#endif
#endif

// CHAR8 / CHAR16 / CHAR32 / WCHAR 
//
// Supports usage of portable string constants.
//
// Example usage:
//     const char16_t* str = CHAR16("Hello world");
//     const char32_t* str = CHAR32("Hello world");
//     const char16_t  c   = CHAR16('\x3001');
//     const char32_t  c   = CHAR32('\x3001');
//
#ifndef CHAR8
	#if CHAR8_UNIQUE
		#define CHAR8(s) u8 ## s
	#else
		#define CHAR8(s) s
	#endif
#endif

#ifndef WCHAR
	#define WCHAR_(s) L ## s
	#define WCHAR(s)  WCHAR_(s)
#endif

#ifndef CHAR16
	#if CHAR16_NATIVE && !defined(_MSC_VER) // Microsoft doesn't support char16_t string literals.
		#define CHAR16_(s) u ## s
		#define CHAR16(s)  CHAR16_(s)
	#elif (WCHAR_SIZE == 2)
		#if defined(_MSC_VER) && (_MSC_VER >= 1900) && defined(__cplusplus) // VS2015 supports u"" string literals.
			#define CHAR16_(s) u ## s
			#define CHAR16(s)  CHAR16_(s)
		#else
			#define CHAR16_(s) L ## s
			#define CHAR16(s)  CHAR16_(s)
		#endif
	#else
		//#define CHAR16(s) // Impossible to implement efficiently.
	#endif
#endif

#ifndef CHAR32
	#if CHAR32_NATIVE && !defined(_MSC_VER) // Microsoft doesn't support char32_t string literals.
		#define CHAR32_(s) U ## s
		#define CHAR32(s)  CHAR32_(s)
	#elif (WCHAR_SIZE == 2)
		#if defined(_MSC_VER) && (_MSC_VER >= 1900) && defined(__cplusplus) // VS2015 supports u"" string literals.
			#define CHAR32_(s) U ## s
			#define CHAR32(s)  CHAR32_(s)
		#else
			//#define CHAR32(s) // Impossible to implement.
		#endif
	#elif (WCHAR_SIZE == 4)
		#define CHAR32_(s) L ## s
		#define CHAR32(s)  CHAR32_(s)
	#else
		#error Unexpected size of wchar_t
	#endif
#endif

#endif
