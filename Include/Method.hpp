#ifndef TANGARA_METHOD_HPP
#define TANGARA_METHOD_HPP
#include "TgObj.h"

namespace Tangara {

    class Method {
    public:
        explicit Method(const char* name, uint32_t typeHash, uint32_t retTypeHash, TgMethodDelegate *delegate, const TgParamTypes& paramTypes);

        ~Method();

        /// Runs method checking given parameters and calling object
        /// Throws exception if parameters doesn't match
        TgObj* RunSafe(TgObj *callObj, const TgParams &params);
        /// Runs method without checking given parameters
        /// Use only when you know that params matches method's
        TgObj* Run(void *callObj, const TgParams &params);

        [[nodiscard]] const char* GetName() const { return name; }
        [[nodiscard]] uint32_t GetType() const { return type; }
        [[nodiscard]] uint32_t GetReturnType() const { return returnType; }
    private:
        const char* name;
        uint32_t type;
        uint32_t returnType;
        TgMethodDelegate *delegate;
        TgParamTypes paramTypes;
    };

} // Tangara

#endif //TANGARA_METHOD_HPP
