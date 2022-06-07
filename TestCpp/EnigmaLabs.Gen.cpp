// File was generated using TangaraGen.py
#include "Snaulx.hpp"
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
extern "C" TgObj* tg_Snaulx_ctor0(TgObj* params[])
{
	char* arg_name = static_cast<char*>(malloc(params[0]->size));
	memcpy(arg_name, params[0]->data, params[0]->size);
	return TgPtr((void*) new Snaulx(arg_name), TgGetClassHash("Snaulx"));
}
extern "C" TgObj* tg_Snaulx_PrintName(void* obj, TgObj* params[])
{
	auto* cppObj = static_cast<Snaulx*>(obj);
	EnigmaLabs::MyClass* arg_cl = static_cast<EnigmaLabs::MyClass*>(malloc(params[0]->size));
	memcpy(arg_cl, params[0]->data, params[0]->size);
	cppObj->PrintName(arg_cl);
	return TgNull();
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
	auto *Snaulx_class = new Class("Snaulx");
	TgParamTypes Snaulx_ctor0_paramTypes;
	Snaulx_ctor0_paramTypes.length = 1;
	Snaulx_ctor0_paramTypes.types = (uint32_t*)calloc(1, sizeof(uint32_t));
	Snaulx_ctor0_paramTypes.names = (char**)calloc(1, sizeof(char*));
	Snaulx_ctor0_paramTypes.types[0] = TgGetClassHash("char*");
	Snaulx_ctor0_paramTypes.names[0] = "name";
	Snaulx_class->CreateConstructor(tg_Snaulx_ctor0, Snaulx_ctor0_paramTypes);
	TgParamTypes Snaulx_PrintName_paramTypes;
	Snaulx_PrintName_paramTypes.length = 1;
	Snaulx_PrintName_paramTypes.types = (uint32_t*)calloc(1, sizeof(uint32_t));
	Snaulx_PrintName_paramTypes.names = (char**)calloc(1, sizeof(char*));
	Snaulx_PrintName_paramTypes.types[0] = TgGetClassHash("EnigmaLabs.MyClass*");
	Snaulx_PrintName_paramTypes.names[0] = "cl";
	Snaulx_class->CreateMethod("PrintName", tg_Snaulx_PrintName, TgGetClassHash("void"), Snaulx_PrintName_paramTypes);
	EnigmaLabs_entry->AddClass(Snaulx_class);
	return EnigmaLabs_entry;
}