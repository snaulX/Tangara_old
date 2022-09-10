#ifndef TANGARA_NATIVEMETHODIMPL_HPP
#define TANGARA_NATIVEMETHODIMPL_HPP

#include "IMethodImpl.hpp"

namespace Tangara {
    struct NativeMethodImpl : public IMethodImpl {
        NativeMethodImpl(tgMethodFuncPtr funcPtr) : _funcPtr(funcPtr) {}

        tgMethodFuncPtr GetImplementaion() {
            return _funcPtr;
        }

        void *GetCustomObject() {
            return nullptr;
        }

    private:
        tgMethodFuncPtr _funcPtr;
    };
}

#endif //TANGARA_NATIVEMETHODIMPL_HPP
