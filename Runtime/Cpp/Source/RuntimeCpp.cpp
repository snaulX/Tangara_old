#include "RuntimeCpp.hpp"

namespace Tangara::Runtime::Cpp {
    static Entry* entry;
    static Class* currentClass;

    Entry *TgCreateEntry(const char *name) {
        auto* e = new Entry(name);
        entry = e;
        return e;
    }

    uint32_t TgGetClassHash(const char* name) {
        return entry->GetClass(name)->GetHashCode();
    }

    Class * TgCreateClass(const char* name) {
        auto* cl = new Class(name);
        entry->AddClass(cl);
        return cl;
    }

    void TgSetCurrentType(Class *typeHandle) {
        currentClass = typeHandle;
    }

    void TgCreateMethod(const char* name, TgMethodDelegate delegate) {
        auto* method = new Method();
        method->name = name;
        method->delegate = delegate;
        currentClass->methods.push_back(method);
    }

    void TgCreateCtor(TgFuncDelegate delegate, char** typeNames, char** paramNames, int length) {
        auto* hashes = new uint32_t[length];
        for (int i = 0; i < length; i++) {
            hashes[i] = TgGetClassHash(typeNames[i]);
        }
        TgParamTypes types;
        types.length = length;
        types.types = hashes;
        types.names = paramNames;
        auto* ctor = new Constructor(delegate, types);
        currentClass->AddConstructor(ctor);
    }
}