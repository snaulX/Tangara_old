#ifndef TANGARA_TYPE_HPP
#define TANGARA_TYPE_HPP

#include <vector>
#include "Method.hpp"

namespace Tangara {

    class Type {
    public:
        explicit Type(const char* name);

        ~Type();

        [[nodiscard]] const char* GetName() const { return name; }
        [[nodiscard]] uint32_t GetHashCode() const { return hashcode; }

        [[nodiscard]] Method* GetMethod(const char* name);
    private:
        const char* name;
        std::vector<Method*> methods{};
        const uint32_t hashcode;
    };

} // Tangara

#endif //TANGARA_TYPE_HPP
