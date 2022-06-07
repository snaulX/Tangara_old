#ifndef TANGARA_CONSTRUCTOR_HPP
#define TANGARA_CONSTRUCTOR_HPP
#include <cstdint>
#include "TgObj.h"

namespace Tangara {

    class Constructor {
    public:
        explicit Constructor(uint32_t type, TgFuncDelegate *delegate, const TgParamTypes& paramTypes);

        ~Constructor();

        /// Runs constructor checking given parameters
        /// Throws exception if parameters doesn't match
        TgObj* RunSafe(const TgParams &params);
        /// Runs constructor without checking given parameters
        /// Use only when you know that params matches constructor's
        TgObj* Run(const TgParams &params);

        [[nodiscard]] uint32_t GetType() const { return type; }
    private:
        uint32_t type;
        TgFuncDelegate* delegate;
        TgParamTypes paramTypes;
    };

} // Tangara

#endif //TANGARA_CONSTRUCTOR_HPP
