#include <cstring>
#include "RuntimeCpp.hpp"
#include "TgStd.h"

namespace Tangara::Runtime::Cpp {
    static Entry* entry;

    Entry *TgGetEntry() {
        return entry;
    }

    Entry *TgCreateEntry(const char *name) {
        auto* e = new Entry(name);
        e->LinkEntry(static_cast<Entry *>(TgStdInit()));
        entry = e;
        return e;
    }

    Type* TgGetType(const char* name) {
        if (strstr(name, "char*") != nullptr)
            return (Type*)Tangara::Std::GetCStrClass();
        size_t len = strlen(name) - 1;
        if (name[len] == '*') {
            char* type = (char*)calloc(len + 1, sizeof(char));
            strncpy(type, name, len);
            return entry->GetType(type);
        }
        return entry->GetType(name);
    }

    uint32_t TgGetTypeHash(const char* name) {
        return TgGetType(name)->GetHashCode();
    }
}