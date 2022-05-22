#include "Entry.hpp"

namespace Tangara {
    Entry::Entry(const char* name) : name(name) { }

    Entry::~Entry() = default;

    Class *Entry::GetClass(const char *name) {
        for (Class* cl : classes) {
            if (strcmp(cl->GetName(), name) == 0) return cl;
        }
        return nullptr;
    }
}