#ifndef TANGARA_ENTRY_HPP
#define TANGARA_ENTRY_HPP
#include <vector>
#include "Class.hpp"

namespace Tangara {

    class Entry {
    public:
        explicit Entry(const char* name);

        ~Entry();

        void AddClass(Class* cl) { classes.push_back(cl); }
        void LinkEntry(Entry* e) { links.push_back(e); }

        Class* GetClass(const char* name);
    private:
        const char* name;
        std::vector<Class*> classes;
        std::vector<Entry*> links;
    };

} // Tangara

#endif //TANGARA_ENTRY_HPP
