#ifndef TANGARA_SNAULX_HPP
#define TANGARA_SNAULX_HPP
#include "MyClass.hpp"

class Snaulx {
public:
    explicit Snaulx(char* name);

    ~Snaulx();

    void PrintName(EnigmaLabs::MyClass* cl);
private:
    char* name;
};


#endif //TANGARA_SNAULX_HPP
