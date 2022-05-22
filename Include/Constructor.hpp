#ifndef TANGARA_CONSTRUCTOR_HPP
#define TANGARA_CONSTRUCTOR_HPP

#include "TgObj.h"

namespace Tangara {

    class Constructor {
    public:
        explicit Constructor(TgCtorDelegate *delegate, char** paramTypes);

        ~Constructor();

        TgObj* Run(TgObj* params[]);
    private:
        TgCtorDelegate* delegate;
        char** paramTypes;
    };

} // Tangara

#endif //TANGARA_CONSTRUCTOR_HPP
