#ifndef TANGARA_CLASS_HPP
#define TANGARA_CLASS_HPP

#include <vector>
#include "Constructor.hpp"

namespace Tangara {

    class Class {
    public:
        explicit Class(const char *_name);

        ~Class();

        void AddConstructor(Constructor* ctor) { ctors.push_back(ctor); }
        TgObj* New(TgObj* params[]);

        [[nodiscard]] const char* GetName() const { return name; }
    private:
        const char* name;
        std::vector<Constructor*> ctors;
    };

} // Tangara

#endif //TANGARA_CLASS_HPP
