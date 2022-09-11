#ifndef TANGARA_IPROPSETIMPL_HPP
#define TANGARA_IPROPSETIMPL_HPP
#include "tg_structs.h"

namespace Tangara {
    struct IPropSetImpl {
        virtual tgPropSetFuncPtr GetImplementaion() {
            return nullptr; // TODO: throw Tangara excpetion
        }
    };
}

#endif //TANGARA_IPROPSETIMPL_HPP
