#ifndef TANGARA_ENTRY_HPP
#define TANGARA_ENTRY_HPP
#include <vector>
#include "Class.hpp"

namespace Tangara {

    class Entry {
    public:
        explicit Entry(const char* name);

        ~Entry();

        void AddClass(Class* cl);
        void LinkEntry(Entry* e);

        Class* GetClass(const char* name);

        [[nodiscard]] const char* GetName() const { return name; }
        [[nodiscard]] uint32_t GetHashCode() const { return hashcode; }
    private:
        const char* name;
        const uint32_t hashcode;

        std::vector<Class*> classes;
        std::vector<Entry*> links;
    };

    inline bool operator==(const Entry& left, const Entry& right) {
        return left.GetHashCode() == right.GetHashCode();
    }
} // Tangara

#endif //TANGARA_ENTRY_HPP
