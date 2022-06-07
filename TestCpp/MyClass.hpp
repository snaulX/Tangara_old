#ifndef TANGARA_MYCLASS_HPP
#define TANGARA_MYCLASS_HPP

namespace EnigmaLabs {

    class MyClass {
    public:
        MyClass();

        ~MyClass();

        void Greetings(char *name);

        void SetNumb(int numb);

        int GetNumb();

    private:
        int n = 0;
    };

} // EnigmaLabs

extern "C" void* tgLoadEntry();

#endif //TANGARA_MYCLASS_HPP
