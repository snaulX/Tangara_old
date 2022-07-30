#include "Entry.hpp"
#include "xxhash/xxhash32.h"

namespace Tangara {
    Entry::Entry(const char* name) : name(name), IHashable(XXHash32::hash(name, sizeof(name), TG_ENTRY_SEED))
    { }

    Entry::~Entry() = default;

    Type *Entry::GetType(const char *name) {
        for (Type* cl : types) {
            if (strcmp(cl->GetName(), name) == 0) return cl;
        }
        for (Entry* e : references) {
            Type *clInLink = e->GetType(name);
            if (clInLink != nullptr) return clInLink;
        }
        return nullptr;
    }

    void Entry::AddType(Type *type) {
        for (Type* t : types) {
            // Check this class if it exists in this entry already
            if (t == type) return;
        }
        types.push_back(type);
    }

    void Entry::LinkEntry(Entry *e) {
        uint32_t eHash = e->GetHashCode();
        if (GetHashCode() == eHash)
            return;
        for (Entry* link : references) {
            if (link->GetHashCode() == eHash) return;
        }
        references.push_back(e);
    }
}