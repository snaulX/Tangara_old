#ifndef TANGARA_RUNTIMECPP_HPP
#define TANGARA_RUNTIMECPP_HPP
#include <vector>
#include "TgObj.h"
#include "Class.hpp"
#include "Constructor.hpp"
#include "Entry.hpp"

#include "TgStd.h"

namespace Tangara::Runtime::Cpp {
    [[nodiscard]] Entry* TgGetEntry();
    Entry* TgCreateEntry(const char* name);
    [[nodiscard]] uint32_t TgGetClassHash(const char* name);
}

#endif //TANGARA_RUNTIMECPP_HPP
