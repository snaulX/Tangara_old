#pragma once
#ifndef TG_FILE_H
#define TG_FILE_H

#include "TangaraCore.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {  // only need to export C interface if used by C++ source code
#endif
    
TANGARA_API inline FILE* tgOpenWrite(const char* file_name);
TANGARA_API inline void tgCloseFile(FILE*);

TANGARA_API inline FILE* tgOpenRead(const char* file_name);

#define GEN_WRITEARR(type) TANGARA_API inline void tgWrite##type##Array(FILE* file, ARRNAME(type)* arr) \
{ \
fwrite(arr, sizeof(ARRNAME(type)), 1, file); \
}
#define GEN_READARR(type) TANGARA_API inline void tgRead##type##Array(FILE* file, ARRNAME(type)* arr) \
{ \
fread(arr, sizeof(ARRNAME(type)), 1, file); \
}
#define WRITEARR(file, type, arr) tgWrite##type##Array(file, arr)
#define READARR(file, type, arr) tgRead##type##Array(file, arr)

GEN_WRITEARR(TgClass)
GEN_READARR(TgClass)

#ifdef __cplusplus
}
#endif

#endif
