#ifndef TANGARA_CODEBLOCK_H
#define TANGARA_CODEBLOCK_H

#include "TangaraCore.h"

#define CALL 0

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
    char_t* str;
};

union ConvStrData
{
    Data* data;
    struct StrData* str;
};

Data (*call)(ArrayData args);

#endif //TANGARA_CODEBLOCK_H
