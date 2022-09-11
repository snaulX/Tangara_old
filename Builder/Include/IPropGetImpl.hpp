#ifndef TANGARA_IPROPGETIMPL_HPP
#define TANGARA_IPROPGETIMPL_HPP
#include "tg_structs.h"

namespace Tangara {
    struct IPropGetImpl {
        virtual tgPropGetFuncPtr GetImplementaion() {
            return nullptr; // TODO: throw Tangara excpetion
        }

        virtual void *GetCustomObject() {
            return nullptr;
        }
    };
}

#endif //TANGARA_IPROPGETIMPL_HPP
