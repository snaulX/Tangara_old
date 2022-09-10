#include "TgValue.hpp"
#include <cstring>
#include <cstdlib>

namespace Tangara {
    namespace TgValue {
        tgConstValue CStr(const char* str) {
            size_t data_size = strlen(str) * sizeof(char) + 1;
            char* data = (char*)malloc(data_size);
            strcpy_s(data, data_size, str);
            return {ValueType_CStr, (void*) data};
        }

        tgConstValue Int(int value) {
            int* data = (int*)malloc(sizeof(int));
            *data = value;
            return {ValueType_Int, (void*) data};
        }
    };
}
