#include "Class.hpp"

namespace Tangara {
    Class::Class() = default;

    Class::~Class() = default;

    Method *Class::CreateMethod(const char *name) {
        return nullptr;
    }

    Method *Class::GetMethod(const std::string& name) {
        return nullptr;
    }
}