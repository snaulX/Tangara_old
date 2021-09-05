#pragma once
#ifndef TG_FILE_H
#define TG_FILE_H

#include "Tangara.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {  // only need to export C interface if used by C++ source code
#endif
    
TANGARA_API FILE* open_write(const char* file_name);
TANGARA_API void close_file(FILE*);
void write_class(FILE*, Class);
void write_func(FILE*, Func);
void write_var(FILE*, Var);

TANGARA_API FILE* open_read(const char* file_name);
void read_class(FILE*, Class*);

TANGARA_API void write_class_block(FILE*, ClassBlock*);
TANGARA_API void read_class_block(FILE*, ClassBlock*);

#ifdef __cplusplus
}
#endif

#endif
