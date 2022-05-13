#ifndef TANGARA_CLASS_HPP
#define TANGARA_CLASS_HPP
#include "Type.hpp"
#include "Method.hpp"

namespace Tangara {

    class Class : public Type {
    public:
        Class();

        ~Class();

        Method* CreateMethod(const char* name);
        Method* GetMethod(const std::string& name);
    private:
        std::vector<Method*> methods;
    };

} // Tangara

#endif //TANGARA_CLASS_HPP
