#include "Constructor.hpp"
#include "Utils.hpp"

namespace Tangara {
    Constructor::Constructor(uint32_t type, TgFuncDelegate *delegate, const TgParamTypes& paramTypes)
    : type(type), delegate(delegate), paramTypes(paramTypes) { }

    TgObj *Constructor::RunSafe(const TgParams &params) {
        CheckParams(params, paramTypes);
        return Run(params);
    }

    TgObj *Constructor::Run(const TgParams &params) {
        return delegate(params.params);
    }

    Constructor::~Constructor() = default;
}