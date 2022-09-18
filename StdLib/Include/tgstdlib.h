#ifndef TANGARA_TGSTDLIB_H
#define TANGARA_TGSTDLIB_H
#include "tg_structs.h"
#include "tgbase.h"

#ifdef __cplusplus
extern "C"
{
#endif

TANGARA_API tgEntry* tgLoadStdLib();

TANGARA_API tgType* tgVoidType();
TANGARA_API tgType* tgIntType();
TANGARA_API tgType* tgCStrType();

#ifdef __cplusplus
}
#endif

#endif //TANGARA_TGSTDLIB_H
