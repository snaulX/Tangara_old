#ifndef TANGARA_TGOBJ_H
#define TANGARA_TGOBJ_H
#include "TangaraBase.h"

#ifdef _cplusplus
extern "C" {
#endif
typedef struct _TgObj {
    const char* type_name;
    void *data;
    size_t size;
} TgObj;
TANGARA_API TgObj *TgPtr(void *data, const char* type_name);
TANGARA_API TgObj *TgInt(int data);
TANGARA_API TgObj *TgFloat(float data);
TANGARA_API void TgDestroy(TgObj *tgObj);


typedef TgObj*(TgMethodDelegate)(void*, TgObj**);
typedef TgObj*(TgCtorDelegate)(TgObj**);
#ifdef _cplusplus
}
#endif

#endif //TANGARA_TGOBJ_H
