#ifndef TANGARA_ICTORIMPL_HPP
#define TANGARA_ICTORIMPL_HPP
#include "tg_structs.h"

namespace Tangara {
    struct ICtorImpl {
        virtual tgCtorFuncPtr GetImplementaion() const {
            return nullptr; // TODO: throw Tangara excpetion
        }

        virtual void *GetCustomObject() const {
            return nullptr;
        }
    };
}
#endif //TANGARA_ICTORIMPL_HPP
