#ifndef TANGARA_CLASS_HPP
#define TANGARA_CLASS_HPP

#include <vector>
#include "xxhash/xxhash32.h"
#include "Constructor.hpp"
#include "Method.hpp"

namespace Tangara {

    class Class {
    public:
        explicit Class(const char *_name);

        ~Class();

        void AddConstructor(Constructor* ctor) { ctors.push_back(ctor); }
        Method* CreateMethod(const char* name, TgMethodDelegate* delegate, const TgParamTypes& params) {
            auto* method = new Method(name, hashcode, delegate, params);
            methods.push_back(method);
            return method;
        }
        /// Creates new Tangara object of this class
        TgObj* New(const TgParams &params);

        [[nodiscard]] const char* GetName() const { return name; }
        [[nodiscard]] uint32_t GetHashCode() const { return hashcode; }
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
