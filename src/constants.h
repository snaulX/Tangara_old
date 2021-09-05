#pragma once
#ifndef INTERNAL

#ifdef WIN32
#define TANGARA_API __declspec(dllexport)
#else
#define TANGARA_API __attribute__((visibility(""default"")))
#endif

#define INTERNAL 0
#define PUBLIC 1
#define PRIVATE 2
#define PROTECTED 3
#define PROTECTED_INTERNAL 4

#define DEFAULT 0
#define STATIC 1
#define ABSTRACT 2
#define SEALED 3

#endif
