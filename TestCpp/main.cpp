#include <iostream>
#include <vector>
#include "RuntimeCpp.hpp"
#include "Utils.hpp"
#include "TgStd.h"

// Lib code
using namespace Tangara::Runtime::Cpp;

static CreateEntry createEntry_EnigmaLabs("EnigmaLabs");

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
    return TgPtr((void *) new MyClass(), TgGetClassHash("MyClass"));
}
static CreateCtor createCtor_MyClass0(tg_MyClass_ctor0, {}, {}, 0);

extern "C" TgObj* tg_MyClass_GetName(void* obj, TgObj* params[]) {
    auto* cppObj = static_cast<MyClass*>(obj);
    char* arg0 = static_cast<char *>(malloc(params[0]->size));
    memcpy(arg0, params[0]->data, params[0]->size);
    auto* tgObj = TgPtr(cppObj->GetName(arg0), TgGetClassHash("cstring"));
    free(arg0);
    char* str = (char*)tgObj->data;
    return tgObj;
}
static CreateMethod createMethod_MyClass_GetName("GetName", tg_MyClass_GetName, {
    .length = 1,
    .types = {
            TgCStrHash()
    },
    .names = {
            "name"
    }
});

extern "C" TgObj* tg_MyClass_PrintInt(void* obj, TgObj* params[]) {
    auto* cppObj = static_cast<MyClass*>(obj);
    int arg0 = *(int*)params[0]->data;
    cppObj->PrintInt(arg0);
    return TgNull();
}
static CreateMethod createMethod_MyClass_PrintInt("PrintInt", tg_MyClass_PrintInt);

extern "C" TgObj* tg_MyClass_SetNumb(void* obj, TgObj* params[]) {
    auto* cppObj = static_cast<MyClass*>(obj);
    int arg0 = *(int*)params[0]->data;
    cppObj->SetNumb(arg0);
    return TgNull();
}
static CreateMethod createMethod_MyClass_SetNumb("SetNumb", tg_MyClass_SetNumb);

// Main code
using namespace Tangara;

void* DllLoad(const char* name) { return nullptr; }
void* GetEntry(void* dll, const char* name) { return nullptr; }
void* GetClass(void* entry, const char* name) {
    return ((Entry*)entry)->GetClass(name);
}
void* GetMethod(void* cl, const char* name) {
    return ((Class*)cl)->GetMethod(name);
}
TgObj* CreateObject(void* cl, const TgParams &params) {
    return ((Class*)cl)->New(params);
}
TgObj* RunMethod(TgObj* obj, void* method, const TgParams &params) {
    return ((Method*)method)->RunSafe(obj, params);
}

int main()
{
    // EnigmaLabs code
    auto* std = static_cast<Entry *>(TgStdInit());


    // Main code
    auto dll = DllLoad("EnigmaLabs");
    auto entry = GetEntry(dll, "EnigmaLabs");
    auto MyClass = GetClass(entry, "MyClass");
    auto obj = CreateObject(MyClass, Tangara::EmptyParams());

    auto GetName = GetMethod(MyClass, "GetName");
    TgObj* params[] = {TgPtr((void *) "kek", TgCStrHash())};
    auto name = (char*)RunMethod(obj, GetName, {
        .length = 1,
        .params = params
    })->data;
    std::cout << name << std::endl;

    auto SetNumb = GetMethod(MyClass, "SetNumb");
    TgObj* numbParams[] = {TgInt(10)};
    RunMethod(obj, SetNumb, {
        .length = 1,
        .params = numbParams
    });

    auto PrintInt = GetMethod(MyClass, "PrintInt");
    TgObj* intParams[] = {TgInt(5)};
    RunMethod(obj, PrintInt, {
        .length = 1,
        .params = intParams
    });
    free(obj);
    //TgDestroy(obj);
}
