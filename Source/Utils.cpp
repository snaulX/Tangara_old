#include <exception>
#include "Utils.hpp"

namespace Tangara {
    void CheckParams(const TgParams& params, const TgParamTypes& paramTypes) {
        // Checking length of parameters
        if (params.length != paramTypes.length) {
            throw std::exception("Given parameters length is wrong");
        }
        // Type-checking
        for (int i = 0; i < params.length; i++) {
            if (params.params[i]->type_hash != paramTypes.types[i])
                throw std::exception("Parameter type doesn't equals constructor parameter type");
        }
    }

    // Create local variable to avoid allocation of params on every calling
    TgParams emptyParams = {0, nullptr};
    TgParams EmptyParams() {
        return emptyParams;
    }

    bool operator==(const TgParamTypes& left, const TgParamTypes& right) {
        if (left.length == right.length) {
            for (int i = 0; i < left.length; i++) {
                if (left.types[i] != right.types[i])
                    return false;
            }
            return true;
        }
        return false;
    }
}