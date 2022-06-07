#include <iostream>
#include "MyClass.hpp"

namespace EnigmaLabs {
    MyClass::MyClass() = default;

    MyClass::~MyClass() = default;

    void MyClass::Greetings(char *name) {
        std::cout << "Hello, " << name << std::endl;
    }

    void MyClass::SetNumb(int numb) {
        n = numb;
    }

    int MyClass::GetNumb() {
        return n;
    }
}