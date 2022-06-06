#include "RuntimeCpp.hpp"
#include "TgStd.h"

namespace Tangara::Runtime::Cpp {
    static Entry* entry;
    static Class* currentClass;

    Entry *TgCreateEntry(const char *name) {
        auto* e = new Entry(name);
        e->LinkEntry(static_cast<Entry *>(TgStdEntry()));
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

    void TgCreateMethod(const char* name, TgMethodDelegate delegate, const TgParamTypes& paramTypes) {
        currentClass->CreateMethod(name, delegate, paramTypes);
    }

    void TgCreateCtor(TgFuncDelegate delegate, char** typeNames, char** paramNames, int length) {
        auto* hashes = new uint32_t[length];
        for (int i = 0; i < length; i++) {
            hashes[i] = TgGetClassHash(typeNames[i]);
        }
        TgParamTypes types = {
                .length = length,
                .types = hashes,
                .names = paramNames
        };
        auto* ctor = new Constructor(delegate, types);
        currentClass->AddConstructor(ctor);
    }
}