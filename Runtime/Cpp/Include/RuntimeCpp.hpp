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
    Class* TgCreateClass(const char* name);
    void TgCreateMethod(const char* name, TgMethodDelegate delegate, uint32_t types[], char* paramNames[], int length);
    void TgCreateCtor(TgFuncDelegate delegate, uint32_t* types, char** paramNames, int length);

    class CreateEntry {
    public:
        explicit CreateEntry(const char* name) {
            TgCreateEntry(name);
        }
    };
    class CreateClass {
    public:
        explicit CreateClass(const char* name) {
            TgCreateClass(name);
        }
    };
    class CreateCtor {
    public:
        explicit CreateCtor(TgFuncDelegate ctor, const int length, ...) {
            char** paramNames = (char**)(calloc(length, sizeof(char *)));
            uint32_t* types = (uint32_t*)calloc(length, sizeof(uint32_t));
            uint32_t *vaTypes = (uint32_t*)(&length + sizeof(int));
            for (int i = 0; i < length; i++) {
                types[i] = *vaTypes;
                vaTypes++;
            }
            vaTypes--;
            char* *vaNames = (char**)(vaTypes);
            for (int i = 0; i < length; i++) {
                paramNames[i] = *vaNames;
                vaNames++;
            }
            TgCreateCtor(ctor, types, paramNames, length);
        }
    };
    class CreateMethod {
    public:
        explicit CreateMethod(const char* name, TgMethodDelegate method, const int length, ...) {
            char** paramNames = (char**)(calloc(length, sizeof(char *)));
            uint32_t* types = (uint32_t*)calloc(length, sizeof(uint32_t));
            uint32_t *vaTypes = (uint32_t*)(&length + sizeof(int));
            for (int i = 0; i < length; i++) {
                types[i] = *vaTypes;
                vaTypes++;
            }
            vaTypes--;
            char* *vaNames = (char**)(vaTypes);
            for (int i = 0; i < length; i++) {
                paramNames[i] = *vaNames;
                vaNames++;
            }
            TgCreateMethod(name, method, types, paramNames, length);
        }
    };
}

#endif //TANGARA_RUNTIMECPP_HPP
