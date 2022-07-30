#ifndef TANGARA_TYPE_HPP
#define TANGARA_TYPE_HPP
#include <vector>
#include "Method.hpp"
#include "IHashable.hpp"

namespace Tangara {

    class Type : public IHashable {
    public:
        explicit Type(const char* name);

        ~Type();

        [[nodiscard]] const char* GetName() const { return name; }

        virtual Method* GetMethod(const char* name) = 0;
    private:
        const char* name;
    };

} // Tangara

#endif //TANGARA_TYPE_HPP
