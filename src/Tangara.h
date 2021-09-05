#pragma once
#ifndef TANGARA_H
#define TANGARA_H

#include <stdio.h>
#include <stdlib.h>
//#include "base.h"
#include "constants.h"

#ifdef __cplusplus
extern "C" {  // only need to export C interface if used by C++ source code
#endif

typedef struct Var Var;
typedef struct Field Field;
typedef struct Class Class;
typedef struct Func Func;
typedef struct VarBlock VarBlock;
typedef struct FieldBlock FieldBlock;
typedef struct FuncBlock FuncBlock;

struct Class {
    unsigned int visibility: 1;
    unsigned int class_type: 2;
    char *name;
    FieldBlock *fields;
    FuncBlock *methods;
};

struct Var {
    char *name;
    Class *type;
    void *value;
};

struct Field {
    unsigned int visibility: 2;
    unsigned int var_type: 1;
    Var var;
};

struct Func {
    unsigned int visibility: 2;
    unsigned int func_type: 2;
    char *name;
    Class *return_type;
    VarBlock *parameters;
};

#define CLASS_SIZE sizeof(Class)
#define FUNC_SIZE sizeof(Func)
#define VAR_SIZE sizeof(Var)
#define FIELD_SIZE sizeof(Field)

typedef struct {
    unsigned count;
    Class *classes;
} ClassBlock;

struct FuncBlock {
    unsigned count;
    Func *functions;
};

struct VarBlock {
    unsigned count;
    Var *variables;
};

struct FieldBlock {
    unsigned count;
    Field *fields;
};

TANGARA_API ClassBlock init_class_block();

TANGARA_API FuncBlock init_func_block();

TANGARA_API VarBlock init_var_block();

TANGARA_API FieldBlock init_field_block();

TANGARA_API Class init_class(unsigned visibility, unsigned class_type, char *name);

TANGARA_API Field init_field(unsigned visibility, unsigned field_type, char *name, Class *type, void *value);

TANGARA_API Func init_func(unsigned visibility, unsigned func_type, char *name, Class *return_type, VarBlock *params);

TANGARA_API void add_class(Class, ClassBlock *);

TANGARA_API void add_func(Func, FuncBlock *);

TANGARA_API void add_var(Var, VarBlock *);

TANGARA_API void add_field(Field, FieldBlock *);

#ifdef __cplusplus
}
#endif

#endif
