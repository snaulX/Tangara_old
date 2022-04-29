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
    uint visibility: 1;
    uint class_type: 2;
    const char_t *name;
    ARRNAME(TgField) *fields;
    ARRNAME(TgFunc) *methods;
};

GEN_ARRAY_STRUCT(TgClass)

struct TgVar {
    const char_t *name;
    TgClass *type;
    void *value;
};

GEN_ARRAY_STRUCT(TgVar)

struct TgField {
    uint visibility: 2;
    uint var_type: 1;
    TgVar var;
};

GEN_ARRAY_STRUCT(TgField)

struct TgFunc {
    uint visibility: 2;
    uint func_type: 2;
    const char_t *name;
    TgClass *return_type;
    ARRNAME(TgVar) *parameters;
};

GEN_ARRAY_STRUCT(TgFunc)

TANGARA_API TgClass tgInitClass(uint visibility, uint class_type, const char_t *name);

TANGARA_API TgField tgInitField(uint visibility, uint field_type, const char_t *name, TgClass *type, void *value);

TANGARA_API TgFunc tgInitFunc(uint visibility, uint func_type, const char_t *name, TgClass *return_type, ARRNAME(TgVar) *params);

#ifdef __cplusplus
}
#endif

#endif // TANGARA_CORE_H
