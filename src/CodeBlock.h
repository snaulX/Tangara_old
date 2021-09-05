#ifndef TANGARA_CODEBLOCK_H
#define TANGARA_CODEBLOCK_H

#include "Tangara.h"

#define CALL 0

typedef struct {
    size_t size;
    void* data;
} Data;

typedef struct {
    size_t count;
    Data* data;
} ArrayData;

typedef struct {
    unsigned code;
    ArrayData args;
} Command;

typedef struct {
    Var* locals;
    Command* commands;
} CodeBlock;

struct StrData
{
    size_t size;
    char* str;
};

union ConvStrData
{
    Data* data;
    struct StrData* str;
};

Data (*call)(ArrayData args);

#endif //TANGARA_CODEBLOCK_H
