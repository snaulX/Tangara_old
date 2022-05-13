#ifndef TANGARA_TYPE_HPP
#define TANGARA_TYPE_HPP
#include <string>
#include <utility>
#include <vector>

namespace Tangara {

    class Type {
    public:
        Type();

        ~Type();

        void SetName(std::string _name) { name = std::move(_name); }
        [[nodiscard]] std::string GetName() const { return name; }

        void SetNameSpace(std::string nameSpace) { _namespace = std::move(nameSpace); }
        [[nodiscard]] std::string GetNameSpace() const { return _namespace; }

    protected:
        std::string name;
        std::string _namespace;
    };

} // Tangara

#endif //TANGARA_TYPE_HPP
