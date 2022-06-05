#ifndef TANGARA_TGSTD_H
#define TANGARA_TGSTD_H
#include "TgObj.h"

#ifdef __cplusplus
#include <cstdint>
#include "Class.hpp"
#include "Entry.hpp"

namespace Tangara::Std {
    Entry* StdEntry;

    Class* VoidClass;
    Class* CharClass;
    // Signed numbers
    Class* SByteClass;
    Class* ShortClass;
    Class* IntClass;
    Class* LongClass;
    // Unsigned numbers
    Class* ByteClass;
    Class* UShortClass;
    Class* UIntClass;
    Class* ULongClass;
    // Numbers with float point
    Class* FloatClass;
    Class* DoubleClass;
    // Strings
    Class* CStrClass;
    Class* StrClass;
}

extern "C" {
#else
#include <stdint.h>
#endif

TANGARA_API void *TgStdInit();

TANGARA_API TgObj *TgNull();
TANGARA_API TgObj *TgInt(int data);
TANGARA_API TgObj *TgFloat(float data);

TANGARA_API uint32_t TgVoidHash();
TANGARA_API uint32_t TgIntHash();
TANGARA_API uint32_t TgFloatHash();
TANGARA_API uint32_t TgCStrHash();
TANGARA_API uint32_t TgStrHash();

#ifdef __cplusplus
}
#endif
#endif //TANGARA_TGSTD_H
