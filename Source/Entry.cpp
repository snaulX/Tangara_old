#include "Entry.hpp"

namespace Tangara {
    Entry::Entry(const char* name) : name(name) { }

    Entry::~Entry() = default;

    Class *Entry::GetClass(const char *name) {
        for (Class* cl : classes) {
            if (strcmp(cl->GetName(), name) == 0) return cl;
        }
        for (Entry* e : links) {
            Class *clInLink = e->GetClass(name);
            if (clInLink != nullptr) return clInLink;
        }
        return nullptr;
    }
}