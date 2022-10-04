#ifndef TANGARA_TGVALUE_HPP
#define TANGARA_TGVALUE_HPP

#include "tg_structs.h"
#include <cstdlib>

namespace Tangara {
    namespace TgValue {
        template<typename T>
        inline tgConstValue Value(T value, tgValueType valueType) {
            T *data = (T*) malloc(sizeof(T));
            *data = value;
            return {valueType, (void*) data};
        }

        tgConstValue CStr(const char* str);
        inline tgConstValue Int(int value) { return Value<int>(value, ValueType_Int); }
        inline tgConstValue UInt(uint value) { return Value<uint>(value, ValueType_UInt); }
    };
}

#endif //TANGARA_TGVALUE_HPP
