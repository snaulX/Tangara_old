#ifndef TANGARA_ENTRY_HPP
#define TANGARA_ENTRY_HPP
#include <vector>
#include "Class.hpp"
#include "Function.hpp"

namespace Tangara {

    class Entry {
    public:
        Entry();

        ~Entry();

        void AddClass(Class* cl) { classes.push_back(cl); }
        void AddFunction(Function* func) { functions.push_back(func); }
    private:
        std::vector<Class*> classes;
        std::vector<Function*> functions;
    };

} // Tangara

#endif //TANGARA_ENTRY_HPP
