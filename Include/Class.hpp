#ifndef TANGARA_CLASS_HPP
#define TANGARA_CLASS_HPP
#include <vector>
#include "Constructor.hpp"
#include "Method.hpp"
#include "Type.hpp"

namespace Tangara {

    class Class : public Type {
    public:
        explicit Class(const char *_name);

        ~Class();

        Constructor* CreateConstructor(TgFuncDelegate* delegate, const TgParamTypes& params) {
            auto* ctor = new Constructor(this, delegate, params);
            ctors.push_back(ctor);
            return ctor;
        }
        Method* CreateMethod(const char* name, TgMethodDelegate* delegate, Type* returnType, const TgParamTypes& params) {
            auto* method = new Method(name, this, returnType, delegate, params);
            methods.push_back(method);
            return method;
        }
        /// Creates new Tangara object of this class
        TgObj* New(const TgParams &params);
        TgObj* Run(TgObj* self, const char* methodName, const TgParams &params);

        [[nodiscard]] Method* GetMethod(const char* name) override;
        [[nodiscard]] Constructor* GetConstructor(const TgParamTypes& paramTypes);
    private:
        std::vector<Constructor*> ctors{};
        std::vector<Method*> methods{};
    };

} // Tangara

#endif //TANGARA_CLASS_HPP
