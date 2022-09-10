#ifndef TANGARA_TGVALUE_HPP
#define TANGARA_TGVALUE_HPP

#include "tg_structs.h"

namespace Tangara {
    namespace TgValue {
        tgConstValue CStr(const char* str);
        tgConstValue Int(int value);
    };
}

#endif //TANGARA_TGVALUE_HPP
