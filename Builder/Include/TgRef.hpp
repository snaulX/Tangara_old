#ifndef TANGARA_TGREF_HPP
#define TANGARA_TGREF_HPP

#include "tg_structs.h"
#include "tg_funcs.h"

namespace Tangara {
    inline tgTypeRef TgRef(const char* name) {
        return tgCreateNameTypeRef(name);
    }

    inline tgTypeRef TgRef(uint hash) {
        return tgCreateHashTypeRef(hash);
    }

    template<typename T>
    inline tgTypeRef TgRef() {
        return tgCreateDirectTypeRef(T::_tangara_type);
    }
}

#endif //TANGARA_TGREF_HPP
