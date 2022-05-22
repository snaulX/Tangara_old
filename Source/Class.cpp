#include "Class.hpp"

namespace Tangara {
    Class::Class(const char *_name) : name(_name), ctors() { }

    TgObj *Class::New(TgObj **params) {
        // TODO: Parameters type checking
        return ctors[0]->Run(params);
    }

    Class::~Class() = default;
}