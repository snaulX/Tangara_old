#ifndef TANGARA_CLASS_HPP
#define TANGARA_CLASS_HPP
#include <vector>
#include "Constructor.hpp"
#include "Method.hpp"

namespace Tangara {

    class Class {
    public:
        explicit Class(const char *_name);

        ~Class();

        Constructor* CreateConstructor(TgFuncDelegate* delegate, const TgParamTypes& params) {
            auto* ctor = new Constructor(hashcode, delegate, params);
            ctors.push_back(ctor);
            return ctor;
        }
        Method* CreateMethod(const char* name, TgMethodDelegate* delegate, uint32_t returnType, const TgParamTypes& params) {
            auto* method = new Method(name, hashcode, returnType, delegate, params);
            methods.push_back(method);
            return method;
        }
        /// Creates new Tangara object of this class
        TgObj* New(const TgParams &params);
        TgObj* Run(TgObj* self, const char* methodName, const TgParams &params);

        [[nodiscard]] const char* GetName() const { return name; }
        [[nodiscard]] uint32_t GetHashCode() const { return hashcode; }

        [[nodiscard]] Method* GetMethod(const char* name);
        [[nodiscard]] Constructor* GetConstructor(const TgParamTypes& paramTypes);
    private:
        const char* name;
        std::vector<Constructor*> ctors{};
        std::vector<Method*> methods{};
        const uint32_t hashcode;
    };

    inline bool operator==(const Class& lhs, const Class& rhs) {
        return lhs.GetHashCode() == rhs.GetHashCode();
    }

} // Tangara

#endif //TANGARA_CLASS_HPP
