#pragma once
#ifndef TANGARA_H
#define TANGARA_H

#include "base.h"
#include "constants.h"

#ifdef __cplusplus
extern "C" {  // only need to export C interface if used by C++ source code
#endif

typedef struct TgVar TgVar;
typedef struct TgField TgField;
typedef struct TgClass TgClass;
typedef struct TgFunc TgFunc;
typedef struct TgClassBlock TgClassBlock;
typedef struct TgVarBlock TgVarBlock;
typedef struct TgFieldBlock TgFieldBlock;
typedef struct TgFuncBlock TgFuncBlock;

struct TgClass {
    unsigned int visibility: 1;
    unsigned int class_type: 2;
    char_t *name;
    TgFieldBlock *fields;
    TgFuncBlock *methods;
};

struct TgVar {
    char_t *name;
    TgClass *type;
    void *value;
};

struct TgField {
    unsigned int visibility: 2;
    unsigned int var_type: 1;
    TgVar var;
};

struct TgFunc {
    unsigned int visibility: 2;
    unsigned int func_type: 2;
    char_t *name;
    TgClass *return_type;
    TgVarBlock *parameters;
};

#define CLASS_SIZE sizeof(TgClass)
#define FUNC_SIZE sizeof(TgFunc)
#define VAR_SIZE sizeof(TgVar)
#define FIELD_SIZE sizeof(TgField)

struct TgClassBlock {
    unsigned count;
    TgClass *classes;
};

struct TgFuncBlock {
    unsigned count;
    TgFunc *functions;
};

struct TgVarBlock {
    unsigned count;
    TgVar *variables;
};

struct TgFieldBlock {
    unsigned count;
    TgField *fields;
};

TANGARA_API TgClassBlock tgInitClassBlock();

TANGARA_API TgFuncBlock tgInitFuncBlock();

TANGARA_API TgVarBlock tgInitVarBlock();

TANGARA_API TgFieldBlock tgInitFieldBlock();

TANGARA_API TgClass tgInitClass(unsigned visibility, unsigned class_type, char_t *name);

TANGARA_API TgField tgInitField(unsigned visibility, unsigned field_type, char_t *name, TgClass *type, void *value);

TANGARA_API TgFunc tgInitFunc(unsigned visibility, unsigned func_type, char_t *name, TgClass *return_type, TgVarBlock *params);

TANGARA_API void tgAddClass(TgClass, TgClassBlock *);

TANGARA_API void tgAddFunc(TgFunc, TgFuncBlock *);

TANGARA_API void tgAddVar(TgVar, TgVarBlock *);

TANGARA_API void tgAddField(TgField, TgFieldBlock *);

#ifdef __cplusplus
}
#endif

#endif
