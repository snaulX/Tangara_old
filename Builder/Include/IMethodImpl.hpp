#ifndef TANGARA_IMETHODIMPL_HPP
#define TANGARA_IMETHODIMPL_HPP
#include "tg_structs.h"

namespace Tangara {
    struct IMethodImpl {
        virtual tgMethodFuncPtr GetImplementaion() {
            return nullptr; // TODO: throw Tangara excpetion
        }

        virtual void *GetCustomObject() {
            return nullptr;
        }
    };
}

#endif //TANGARA_IMETHODIMPL_HPP
