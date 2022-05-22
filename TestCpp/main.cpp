#include <iostream>
#include <vector>
#include "RuntimeCpp.hpp"

using namespace Tangara::Runtime::Cpp;

class MyClass {
public:
    MyClass() = default;

    char* GetName(char* name) {
        char* new_name = (char*)(malloc(sizeof(name) + 5));
        memcpy(new_name, "Hey ", 4);
        strcpy(new_name + 4,  name);
        return new_name;
    }
    void PrintInt(int a) const { std::cout << a + numb << std::endl; }
    void SetNumb(int n) { numb = n; }

private:
    int numb = 0;
};
static CreateClass createClass_MyClass("MyClass");

extern "C" TgObj* tg_MyClass_ctor0(TgObj* params[])
{
    return TgPtr((void *) new MyClass(), "MyClass");
}
static CreateCtor createCtor_MyClass0(tg_MyClass_ctor0);

extern "C" TgObj* tg_MyClass_GetName(void* obj, TgObj* params[]) {
    auto* cppObj = static_cast<MyClass*>(obj);
    char* arg0 = static_cast<char *>(malloc(params[0]->size));
    memcpy(arg0, params[0]->data, params[0]->size);
    auto* tgObj = TgPtr(cppObj->GetName(arg0), "cstring");
    free(arg0);
    char* str = (char*)tgObj->data;
    return tgObj;
}
static CreateMethod createMethod_MyClass_GetName("GetName", tg_MyClass_GetName);

extern "C" TgObj* tg_MyClass_PrintInt(void* obj, TgObj* params[]) {
    auto* cppObj = static_cast<MyClass*>(obj);
    int arg0 = *(int*)params[0]->data;
    cppObj->PrintInt(arg0);
    return TgPtr(nullptr, "void");
}
static CreateMethod createMethod_MyClass_PrintInt("PrintInt", tg_MyClass_PrintInt);

extern "C" TgObj* tg_MyClass_SetNumb(void* obj, TgObj* params[]) {
    auto* cppObj = static_cast<MyClass*>(obj);
    int arg0 = *(int*)params[0]->data;
    cppObj->SetNumb(arg0);
    return TgPtr(nullptr, "void");
}
static CreateMethod createMethod_MyClass_SetNumb("SetNumb", tg_MyClass_SetNumb);

void* DllLoad(const char* name) { return nullptr; }
void* GetEntry(void* dll, const char* name) { return nullptr; }
void* GetClass(void* entry, const char* name) {
    return nullptr;
}
void* GetMethod(void* cl, const char* name) {
    auto* ptr = (TgClass*)cl;
    for (auto* method : ptr->methods) {
        if (strcmp(method->name, name) == 0) return method;
    }
    return nullptr;
}
TgObj* CreateObject(void* cl, TgObj* params[]) {
    return ((TgClass*)cl)->ctor->delegate(params);
}
TgObj* RunMethod(TgObj* obj, void* method, TgObj* params[]) {
    return ((TgMethod*)method)->delegate(obj, params);
}

int main()
{
    auto dll = DllLoad("EnigmaLabs");
    auto entry = GetEntry(dll, "EnigmaLabs");
    auto MyClass = GetClass(entry, "MyClass");
    auto obj = CreateObject(MyClass, nullptr);

    auto GetName = GetMethod(MyClass, "GetName");
    TgObj* params[] = {TgPtr((void *) "kek", "cstring")};
    auto name = (char*)RunMethod(obj, GetName, params)->data;
    std::cout << name << std::endl;

    auto SetNumb = GetMethod(MyClass, "SetNumb");
    TgObj* numbParams[] = {TgInt(10)};
    RunMethod(obj, SetNumb, numbParams);

    auto PrintInt = GetMethod(MyClass, "PrintInt");
    TgObj* intParams[] = {TgInt(5)};
    RunMethod(obj, PrintInt, intParams);
    free(obj);
    //TgDestroy(obj);
}
