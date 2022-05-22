#include "RuntimeCpp.hpp"

namespace Tangara::Runtime::Cpp {
    static Entry* entry;
    static Class* currentClass;

    Entry *TgCreateEntry(const char *name) {
        auto* e = new Entry(name);
        entry = e;
        return e;
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

    void TgCreateCtor(TgCtorDelegate delegate) {
        auto* ctor = new Constructor(delegate);
        ctor->delegate = delegate;
        currentClass->ctor = ctor;
    }
}