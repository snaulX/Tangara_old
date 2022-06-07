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

    uint32_t TgGetClassHash(const char* name) {
        return entry->GetClass(name)->GetHashCode();
    }
}