#ifndef TANGARA_ICTORIMPL_HPP
#define TANGARA_ICTORIMPL_HPP
#include "tg_structs.h"

namespace Tangara {
    struct ICtorImpl {
        virtual tgCtorFuncPtr GetImplementaion() {
            return nullptr;
        }

        virtual void *GetCustomObject() {
            return nullptr;
        }
    };
}
#endif //TANGARA_ICTORIMPL_HPP
