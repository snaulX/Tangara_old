#ifndef TANGARA_CLASS_HPP
#define TANGARA_CLASS_HPP
#include <string>
#include <utility>

namespace Tangara {

    class Class {
    public:
        Class();

        ~Class();

        void SetName(std::string _name) { name = std::move(_name); }
        [[nodiscard]] std::string GetName() const { return name; }

        void SetNameSpace(std::string nameSpace) { _namespace = std::move(nameSpace); }
        [[nodiscard]] std::string GetNameSpace() const { return _namespace; }
    private:
        std::string name;
        std::string _namespace;
    };

} // Tangara

#endif //TANGARA_CLASS_HPP
