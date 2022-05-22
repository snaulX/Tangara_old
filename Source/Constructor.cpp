#include <exception>
#include "Constructor.hpp"

namespace Tangara {
    Constructor::Constructor(TgCtorDelegate *delegate, const TgParamTypes& paramTypes)
    : delegate(delegate), paramTypes(paramTypes) { }

    TgObj *Constructor::RunSafe(const TgParams &params) {
        // Checking length of parameters
        if (params.length != paramTypes.length) {
            throw std::exception("Given parameters length is wrong");
        }
        // Type-checking
        for (int i = 0; i < params.length; i++) {
            if (params.params[i]->type_hash != paramTypes.types[i])
                throw std::exception("Parameter type doesn't equals constructor parameter type");
        }
        return Run(params);
    }

    TgObj *Constructor::Run(const TgParams &params) {
        return delegate(params.params);
    }

    Constructor::~Constructor() = default;
}