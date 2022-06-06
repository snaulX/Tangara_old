#include "Entry.hpp"
#include "xxhash/xxhash32.h"

namespace Tangara {
    Entry::Entry(const char* name) : name(name), hashcode(XXHash32::hash(this, sizeof(Entry), TG_HASH_SEED))
    { }

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

    void Entry::AddClass(Class *cl) {
        for (Class* c : classes) {
            // Check this class if it exists in this entry already
            if (c == cl) return;
        }
        classes.push_back(cl);
    }

    void Entry::LinkEntry(Entry *e) {
        uint32_t eHash = e->hashcode;
        if (hashcode == eHash)
            return;
        for (Entry* link : links) {
            if (link->hashcode == eHash) return;
        }
        links.push_back(e);
    }
}