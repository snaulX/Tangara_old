// File was generated using TangaraGen.py
#include "MyClass.hpp"
#include "RuntimeCpp.hpp"

using namespace Tangara;
using namespace Tangara::Runtime::Cpp;
extern "C" TgObj* tg_EnigmaLabs_MyClass_ctor0(TgObj* params[])
{
	return TgPtr((void*) new EnigmaLabs::MyClass(), TgGetClassHash("EnigmaLabs.MyClass"));
}
extern "C" TgObj* tg_EnigmaLabs_MyClass_Greetings(void* obj, TgObj* params[])
{
	auto* cppObj = static_cast<EnigmaLabs::MyClass*>(obj);
	char* arg_name = static_cast<char*>(malloc(params[0]->size));
	memcpy(arg_name, params[0]->data, params[0]->size);
	cppObj->Greetings(arg_name);
	return TgNull();
}
extern "C" TgObj* tg_EnigmaLabs_MyClass_SetNumb(void* obj, TgObj* params[])
{
	auto* cppObj = static_cast<EnigmaLabs::MyClass*>(obj);
	int arg_numb = *(int*)params[0]->data;
	cppObj->SetNumb(arg_numb);
	return TgNull();
}
extern "C" TgObj* tg_EnigmaLabs_MyClass_GetNumb(void* obj, TgObj* params[])
{
	auto* cppObj = static_cast<EnigmaLabs::MyClass*>(obj);
	int result = cppObj->GetNumb();
	int* resultPtr = (int*)malloc(sizeof(int));
	*resultPtr = result;
	TgObj* tgObj = TgPtr(resultPtr, TgGetClassHash("int"));
	return tgObj;
}

extern "C" TANGARA_API void* tgLoadEntry() 
{
	Entry *EnigmaLabs_entry = TgCreateEntry("EnigmaLabs");
	auto *EnigmaLabs_MyClass_class = new Class("EnigmaLabs.MyClass");
	TgParamTypes EnigmaLabs_MyClass_ctor0_paramTypes;
	EnigmaLabs_MyClass_ctor0_paramTypes.length = 0;
	EnigmaLabs_MyClass_ctor0_paramTypes.types = (uint32_t*)calloc(0, sizeof(uint32_t));
	EnigmaLabs_MyClass_ctor0_paramTypes.names = (char**)calloc(0, sizeof(char*));
	EnigmaLabs_MyClass_class->CreateConstructor(tg_EnigmaLabs_MyClass_ctor0, EnigmaLabs_MyClass_ctor0_paramTypes);
	TgParamTypes EnigmaLabs_MyClass_Greetings_paramTypes;
	EnigmaLabs_MyClass_Greetings_paramTypes.length = 1;
	EnigmaLabs_MyClass_Greetings_paramTypes.types = (uint32_t*)calloc(1, sizeof(uint32_t));
	EnigmaLabs_MyClass_Greetings_paramTypes.names = (char**)calloc(1, sizeof(char*));
	EnigmaLabs_MyClass_Greetings_paramTypes.types[0] = TgGetClassHash("char*");
	EnigmaLabs_MyClass_Greetings_paramTypes.names[0] = "name";
	EnigmaLabs_MyClass_class->CreateMethod("Greetings", tg_EnigmaLabs_MyClass_Greetings, TgGetClassHash("void"), EnigmaLabs_MyClass_Greetings_paramTypes);
	TgParamTypes EnigmaLabs_MyClass_SetNumb_paramTypes;
	EnigmaLabs_MyClass_SetNumb_paramTypes.length = 1;
	EnigmaLabs_MyClass_SetNumb_paramTypes.types = (uint32_t*)calloc(1, sizeof(uint32_t));
	EnigmaLabs_MyClass_SetNumb_paramTypes.names = (char**)calloc(1, sizeof(char*));
	EnigmaLabs_MyClass_SetNumb_paramTypes.types[0] = TgGetClassHash("int");
	EnigmaLabs_MyClass_SetNumb_paramTypes.names[0] = "numb";
	EnigmaLabs_MyClass_class->CreateMethod("SetNumb", tg_EnigmaLabs_MyClass_SetNumb, TgGetClassHash("void"), EnigmaLabs_MyClass_SetNumb_paramTypes);
	TgParamTypes EnigmaLabs_MyClass_GetNumb_paramTypes;
	EnigmaLabs_MyClass_GetNumb_paramTypes.length = 0;
	EnigmaLabs_MyClass_GetNumb_paramTypes.types = (uint32_t*)calloc(0, sizeof(uint32_t));
	EnigmaLabs_MyClass_GetNumb_paramTypes.names = (char**)calloc(0, sizeof(char*));
	EnigmaLabs_MyClass_class->CreateMethod("GetNumb", tg_EnigmaLabs_MyClass_GetNumb, TgGetClassHash("int"), EnigmaLabs_MyClass_GetNumb_paramTypes);
	EnigmaLabs_entry->AddClass(EnigmaLabs_MyClass_class);
	return EnigmaLabs_entry;
}