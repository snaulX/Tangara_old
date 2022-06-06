#ifndef TANGARA_RUNTIMECPP_HPP
#define TANGARA_RUNTIMECPP_HPP
#include <vector>
#include "TgObj.h"
#include "Class.hpp"
#include "Constructor.hpp"
#include "Entry.hpp"

namespace Tangara::Runtime::Cpp {
    Entry* TgCreateEntry(const char* name);
    uint32_t TgGetClassHash(const char* name);
    Class* TgCreateClass(const char* name);
    void TgCreateMethod(const char* name, TgMethodDelegate delegate, const TgParamTypes& paramTypes);
    void TgCreateCtor(TgFuncDelegate delegate, char** typeNames, char** paramNames, int length);

    class CreateEntry {
    public:
        explicit CreateEntry(const char* name) {
            TgCreateEntry(name);
        }
    };
    class CreateClass {
    public:
        explicit CreateClass(const char* name) {
            auto* handle = TgCreateClass(name);
        }
    };
    class CreateCtor {
    public:
        explicit CreateCtor(TgFuncDelegate ctor, char** typeNames, char** paramNames, int length) {
            TgCreateCtor(ctor, typeNames, paramNames, length);
        }
    };
    class CreateMethod {
    public:
        explicit CreateMethod(const char* name, TgMethodDelegate method, const TgParamTypes& paramTypes) {
            TgCreateMethod(name, method, paramTypes);
        }
    };
}

#endif //TANGARA_RUNTIMECPP_HPP
