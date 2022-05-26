#include "Constructor.hpp"
#include "Utils.hpp"

namespace Tangara {
    Constructor::Constructor(TgCtorDelegate *delegate, const TgParamTypes& paramTypes)
    : delegate(delegate), paramTypes(paramTypes) { }

    TgObj *Constructor::RunSafe(const TgParams &params) {
        CheckParams(params, paramTypes);
        return Run(params);
    }

    TgObj *Constructor::Run(const TgParams &params) {
        return delegate(params.params);
    }

    Constructor::~Constructor() = default;
}