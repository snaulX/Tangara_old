#ifndef TANGARA_ENTRY_HPP
#define TANGARA_ENTRY_HPP
#include <utility>
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

        void SetName(std::string entryName) { name = std::move(entryName); }
        [[nodiscard]] std::string GetName() const { return name; }
    private:
        std::string name;

        std::vector<Class*> classes;
        std::vector<Function*> functions;
    };

} // Tangara

#endif //TANGARA_ENTRY_HPP
