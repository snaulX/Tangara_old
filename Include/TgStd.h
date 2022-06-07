#ifndef TANGARA_TGSTD_H
#define TANGARA_TGSTD_H
#include "TgObj.h"

#ifdef __cplusplus
#include <cstdint>
#include "Class.hpp"
#include "Entry.hpp"

namespace Tangara::Std {
    [[nodiscard]] Entry* GetEntry();

    [[nodiscard]] Class* GetPtrClass();

    [[nodiscard]] Class* GetVoidClass();
    [[nodiscard]] Class* GetCharClass();
    // Signed numbers
    [[nodiscard]] Class* GetSByteClass();
    [[nodiscard]] Class* GetShortClass();
    [[nodiscard]] Class* GetIntClass();
    [[nodiscard]] Class* GetLongClass();
    // Unsigned numbers
    [[nodiscard]] Class* GetByteClass();
    [[nodiscard]] Class* GetUShortClass();
    [[nodiscard]] Class* GetUIntClass();
    [[nodiscard]] Class* GetULongClass();
    // Numbers with float point
    [[nodiscard]] Class* GetFloatClass();
    [[nodiscard]] Class* GetDoubleClass();
    // Strings
    [[nodiscard]] Class* GetCStrClass();
    [[nodiscard]] Class* GetStrClass();
}

extern "C" {
#else
#include <stdint.h>
#endif

TANGARA_API void *TgStdInit();
TANGARA_API void *TgStdEntry();

TANGARA_API TgObj *TgNull();
TANGARA_API TgObj *TgMakePtr(TgObj* data);
TANGARA_API TgObj *TgStr(const char* str);
TANGARA_API TgObj *TgInt(int data);
TANGARA_API TgObj *TgFloat(float data);

TANGARA_API uint32_t TgPtrHash();
TANGARA_API uint32_t TgVoidHash();
TANGARA_API uint32_t TgIntHash();
TANGARA_API uint32_t TgFloatHash();
TANGARA_API uint32_t TgCStrHash();
TANGARA_API uint32_t TgStrHash();

#ifdef __cplusplus
}
#endif
#endif //TANGARA_TGSTD_H
