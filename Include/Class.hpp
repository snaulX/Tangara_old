#ifndef TANGARA_CLASS_HPP
#define TANGARA_CLASS_HPP

#include <vector>
#include "xxhash/xxhash32.h"
#include "Constructor.hpp"

namespace Tangara {

    class Class {
    public:
        explicit Class(const char *_name);

        ~Class();

        void AddConstructor(Constructor* ctor) { ctors.push_back(ctor); }
        TgObj* New(const TgParams &params);

        [[nodiscard]] const char* GetName() const { return name; }
        [[nodiscard]] uint32_t GetHashCode() const { return hashcode; }
    private:
        const char* name;
        std::vector<Constructor*> ctors;
        const uint32_t hashcode;
    };

} // Tangara

#endif //TANGARA_CLASS_HPP
