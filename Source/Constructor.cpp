#include "Constructor.hpp"

namespace Tangara {
    Constructor::Constructor(TgCtorDelegate *delegate, char** paramTypes)
    : delegate(delegate), paramTypes(paramTypes) { }

    TgObj *Constructor::Run(TgObj **params) {
        return delegate(params);
    }

    Constructor::~Constructor() = default;
}