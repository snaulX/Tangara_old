#include "Type.hpp"
#include "xxhash/xxhash32.h"

namespace Tangara {
    Type::Type(const char *_name) : name(_name), IHashable(XXHash32::hash(_name, sizeof(_name), TG_TYPE_SEED))
    { }

    Type::~Type() = default;
}