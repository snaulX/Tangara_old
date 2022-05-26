#include "Utils.hpp"
#include "Method.hpp"

namespace Tangara {

    Method::Method(const char* name, uint32_t typeHash, TgMethodDelegate *delegate, const TgParamTypes &paramTypes)
    : name(name), type(typeHash), delegate(delegate), paramTypes(paramTypes) { }

    TgObj *Method::RunSafe(TgObj *callObj, const TgParams &params) {
        CheckParams(params, paramTypes);
        return Run(callObj->data, params);
    }

    TgObj *Method::Run(void *callObj, const TgParams &params) {
        return delegate(callObj, params.params);
    }

    Method::~Method() = default;
}