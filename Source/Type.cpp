#include "Type.hpp"
#include "xxhash/xxhash32.h"

namespace Tangara {
    Type::Type(const char *_name) : name(_name), hashcode(XXHash32::hash(_name, sizeof(_name), TG_CLASS_SEED))
    { }

    Type::~Type() = default;

    Method *Type::GetMethod(const char *name) {
        for (Method* m : methods) {
            if (strcmp(m->GetName(), name) == 0) return m;
        }
        return nullptr;
    }
}