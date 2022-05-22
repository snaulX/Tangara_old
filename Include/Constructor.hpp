#ifndef TANGARA_CONSTRUCTOR_HPP
#define TANGARA_CONSTRUCTOR_HPP

#include <cstdint>
#include "TgObj.h"

namespace Tangara {

    class Constructor {
    public:
        explicit Constructor(TgCtorDelegate *delegate, const TgParamTypes& paramTypes);

        ~Constructor();

        TgObj* RunSafe(const TgParams &params);
        TgObj* Run(const TgParams &params);
    private:
        TgCtorDelegate* delegate;
        TgParamTypes paramTypes;
    };

} // Tangara

#endif //TANGARA_CONSTRUCTOR_HPP
