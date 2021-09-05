#pragma once
#ifndef TG_FILE_H
#define TG_FILE_H

#include "Tangara.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {  // only need to export C interface if used by C++ source code
#endif
    
TANGARA_API FILE* tgOpenWrite(const char* file_name);
TANGARA_API void tgCloseFile(FILE*);

TANGARA_API FILE* tgOpenRead(const char* file_name);

TANGARA_API void tgWriteClassBlock(FILE*, TgClassBlock*);
TANGARA_API void tgReadClassBlock(FILE*, TgClassBlock*);

#ifdef __cplusplus
}
#endif

#endif
