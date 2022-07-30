#ifndef TANGARA_ENTRY_HPP
#define TANGARA_ENTRY_HPP
#include <vector>
#include "Type.hpp"
#include "IHashable.hpp"
#include "Class.hpp"

namespace Tangara {

    class Entry : public IHashable {
    public:
        explicit Entry(const char* name);

        ~Entry();

        void AddType(Type* type);
        void AddType(Class* cl) { AddType((Type*)cl); }
        void LinkEntry(Entry* e);

        Type* GetType(const char* name);

        [[nodiscard]] const char* GetName() const { return name; }
    private:
        const char* name;

        std::vector<Type*> types;
        std::vector<Entry*> references;
    };
} // Tangara

#endif //TANGARA_ENTRY_HPP
