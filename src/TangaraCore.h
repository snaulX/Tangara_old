#pragma once
#ifndef TANGARA_CORE_H
#define TANGARA_CORE_H

#include "base.h"
#include "constants.h"

#ifdef __cplusplus
extern "C" {  // only need to export C interface if used by C++ source code
#endif

STRUCTDEF(TgVar)
STRUCTDEF(TgField)
STRUCTDEF(TgClass)
STRUCTDEF(TgFunc)
STRUCTDEF(ARRNAME(TgField))
STRUCTDEF(ARRNAME(TgVar))
STRUCTDEF(ARRNAME(TgFunc))
STRUCTDEF(ARRNAME(TgClass))

struct TgClass {
    unsigned int visibility: 1;
    unsigned int class_type: 2;
    char_t *name;
    ARRNAME(TgField) *fields;
    ARRNAME(TgFunc) *methods;
};

GEN_ARRAY_STRUCT(TgClass)

struct TgVar {
    char_t *name;
    TgClass *type;
    void *value;
};

GEN_ARRAY_STRUCT(TgVar)

struct TgField {
    unsigned int visibility: 2;
    unsigned int var_type: 1;
    TgVar var;
};

GEN_ARRAY_STRUCT(TgField)

struct TgFunc {
    unsigned int visibility: 2;
    unsigned int func_type: 2;
    char_t *name;
    TgClass *return_type;
    ARRNAME(TgVar) *parameters;
};

GEN_ARRAY_STRUCT(TgFunc)

TANGARA_API TgClass tgInitClass(unsigned visibility, unsigned class_type, char_t *name);

TANGARA_API TgField tgInitField(unsigned visibility, unsigned field_type, char_t *name, TgClass *type, void *value);

TANGARA_API TgFunc tgInitFunc(unsigned visibility, unsigned func_type, char_t *name, TgClass *return_type, ARRNAME(TgVar) *params);

#ifdef __cplusplus
}
#endif

#endif
