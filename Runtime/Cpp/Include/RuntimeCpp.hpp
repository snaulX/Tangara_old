#ifndef TANGARA_RUNTIMECPP_HPP
#define TANGARA_RUNTIMECPP_HPP
#include <vector>
#include "TgObj.h"
#include "Class.hpp"
#include "Constructor.hpp"
#include "Entry.hpp"

namespace Tangara::Runtime::Cpp {
    Entry* TgCreateEntry(const char* name);
    Class* TgCreateClass(const char* name);
    void TgSetCurrentType(Class *typeHandle);
    void TgCreateMethod(const char* name, TgMethodDelegate delegate);
    void TgCreateCtor(TgCtorDelegate delegate);

    class CreateClass {
    public:
        explicit CreateClass(const char* name) {
            auto* handle = TgCreateClass(name);
            TgSetCurrentType(handle);
        }
    };
    class CreateCtor {
    public:
        explicit CreateCtor(TgCtorDelegate ctor) {
            TgCreateCtor(ctor);
        }
    };
    class CreateMethod {
    public:
        explicit CreateMethod(const char* name, TgMethodDelegate method) {
            TgCreateMethod(name, method);
        }
    };
}

#endif //TANGARA_RUNTIMECPP_HPP
