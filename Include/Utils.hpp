#ifndef TANGARA_UTILS_HPP
#define TANGARA_UTILS_HPP

#include "TgObj.h"

namespace Tangara {
    void CheckParams(const TgParams& params, const TgParamTypes& paramTypes);
    TgParams EmptyParams();

    bool operator==(const TgParamTypes& left, const TgParamTypes& right);
}

#endif //TANGARA_UTILS_HPP
