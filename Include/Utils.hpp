#ifndef TANGARA_UTILS_HPP
#define TANGARA_UTILS_HPP

#include "TgObj.h"

namespace Tangara {
    void CheckParams(const TgParams& params, const TgParamTypes& paramTypes);
    TgParams EmptyParams();
}

#endif //TANGARA_UTILS_HPP
