#ifndef TANGARA_TGOBJ_H
#define TANGARA_TGOBJ_H
#include "TangaraBase.h"

#ifdef __cplusplus
#include <cstdint>
extern "C" {
#else
#include <stdint.h>
#endif
typedef struct _TgObj {
    uint32_t type_hash;
    void *data;
    size_t size;
} TgObj;
typedef struct _TgParams {
    int length;
    TgObj** params;
} TgParams;
typedef struct _TgParamTypes {
    int length;
    uint32_t* types;
    char** names;
} TgParamTypes;

TANGARA_API TgObj *TgPtr(void *data, uint32_t type_hash);
TANGARA_API void TgDestroy(TgObj *tgObj);

typedef TgObj*(TgMethodDelegate)(void*, TgObj**);
typedef TgObj*(TgFuncDelegate)(TgObj**);
#ifdef __cplusplus
}
#endif

#endif //TANGARA_TGOBJ_H
