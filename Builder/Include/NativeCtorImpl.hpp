#ifndef TANGARA_NATIVECTORIMPL_HPP
#define TANGARA_NATIVECTORIMPL_HPP

#include "ICtorImpl.hpp"

namespace Tangara {
    struct NativeCtorImpl : public ICtorImpl {
        NativeCtorImpl(tgCtorFuncPtr funcPtr) : _funcPtr(funcPtr) {}

        tgCtorFuncPtr GetImplementaion() {
            return _funcPtr;
        }

        void *GetCustomObject() {
            return nullptr;
        }

    private:
        tgCtorFuncPtr _funcPtr;
    };
}

#endif //TANGARA_NATIVECTORIMPL_HPP
