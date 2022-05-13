#ifndef TANGARA_MYCLASS_HPP
#define TANGARA_MYCLASS_HPP

#include "TangaraDefines.hpp"

class MyClass {
public:
    MyClass();

    ~MyClass();

    void MyMethod() { }
private:
TANGARA_CLASS(MyClass)
    TANGARA_METHOD(MyMethod)
TANGARA_END()
};


#endif //TANGARA_MYCLASS_HPP
