#pragma once
#ifndef BASE_H
#define BASE_H

#include <stdlib.h>
#include <stdio.h>

#ifdef WIN32
#define TANGARA_API __declspec(dllexport)
#else
#define TANGARA_API __attribute__((visibility("default")))
#endif

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

typedef struct {
    char_t *message;
} err_info;

struct {
    err_info* errs;
    size_t count;
} errors;

#define err(message) { \
    perror(message); \
    errors.count++;  \
    }


#define ARRAY(type) struct {size_t count; type* data;}
#define ARRNAME(type) type##Array
#define EMPTY_ARRAY {0, NULL}
#define INIT_ARRAY(type) tgInit##type##Array ()
#define GEN_ARRTYPE(type) typedef ARRAY(type) ARRNAME(type);

#define GEN_INIT_METHOD(type) TANGARA_API ARRNAME(type) INIT_ARRAY(type) \
{ \
ARRNAME(type) arr = EMPTY_ARRAY; \
return arr; \
}

#define GEN_ADD_METHOD(type) TANGARA_API void tgAdd##type(type data, ARRNAME(type)* arr) \
{ \
arr->data = realloc(arr->data, ++arr->count * sizeof(data)); \
arr->data[arr->count - 1] = data; \
}

#define GEN_GET_METHOD(type) TANGARA_API type* tgGet##type##FromArray(ARRNAME(type) arr, unsigned index) \
{ \
if (index >= arr.count) \
err("Index greater or equals then length of array") \
return &arr.data[index]; \
}

#define GEN_ARRAY(type) GEN_ARRTYPE(type) \
    GEN_INIT_METHOD(type)                   \
    GEN_ADD_METHOD(type)                    \
    GEN_GET_METHOD(type)

#define ADD(type, data, arr) tgAdd##type(data, &arr)
#define GET(type, index, arr) tgGet##type##FromArray(arr, index)
#define ARR_VAR(type, name) ARRNAME(type) name = INIT_ARRAY(type);


#define STRUCTDEF(structName) typedef struct structName structName;

typedef struct {
    size_t size;
    void* data;
} Data;

typedef struct {
    size_t count;
    Data* data;
} ArrayData;

Data* _getDataFromArrayData(ArrayData arr, unsigned index);

#endif
