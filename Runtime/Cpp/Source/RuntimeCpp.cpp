#include "RuntimeCpp.hpp"
#include "TgStd.h"

namespace Tangara::Runtime::Cpp {
    static Entry* entry;
    static Class* currentClass;

    Entry *TgCreateEntry(const char *name) {
        auto* e = new Entry(name);
        e->LinkEntry(static_cast<Entry *>(TgStdInit()));
        entry = e;
        return e;
    }

    uint32_t TgGetClassHash(const char* name) {
        return entry->GetClass(name)->GetHashCode();
    }

    Class *TgCreateClass(const char* name) {
        auto* cl = new Class(name);
        entry->AddClass(cl);
        currentClass = cl;
        return cl;
    }

    void TgCreateMethod(const char* name, TgMethodDelegate delegate, uint32_t* types, char** paramNames, int length) {
        TgParamTypes paramTypes = {length, types, paramNames};
        currentClass->CreateMethod(name, delegate, paramTypes);
    }

    void TgCreateCtor(TgFuncDelegate delegate, uint32_t* types, char** paramNames, int length) {
        TgParamTypes paramTypes = {length, types, paramNames};
        currentClass->AddConstructor(new Constructor(delegate, paramTypes));
    }

    Entry *TgGetEntry() {
        return entry;
    }
}