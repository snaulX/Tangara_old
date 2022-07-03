// File was generated using TangaraGen.py
#include "Class.hpp"
#include "Constructor.hpp"
#include "Entry.hpp"
#include "Method.hpp"
#include "RuntimeCpp.hpp"

using namespace Tangara;
using namespace Tangara::Runtime::Cpp;
extern "C" TgObj* tg_Tangara_Entry_ctor0(TgObj* params[])
{
	char* arg_name = static_cast<char*>(malloc(params[0]->size));
	memcpy(arg_name, params[0]->data, params[0]->size);
	return TgPtr((void*) new Tangara::Entry(arg_name), TgGetClassHash("Tangara.Entry"));
}
extern "C" TgObj* tg_Tangara_Entry_AddClass(void* obj, TgObj* params[])
{
	auto* cppObj = static_cast<Tangara::Entry*>(obj);
	Tangara::Class* arg_cl = static_cast<Tangara::Class*>(malloc(params[0]->size));
	memcpy(arg_cl, params[0]->data, params[0]->size);
	cppObj->AddClass(arg_cl);
	return TgNull();
}
extern "C" TgObj* tg_Tangara_Entry_LinkEntry(void* obj, TgObj* params[])
{
	auto* cppObj = static_cast<Tangara::Entry*>(obj);
	Tangara::Entry* arg_e = static_cast<Tangara::Entry*>(malloc(params[0]->size));
	memcpy(arg_e, params[0]->data, params[0]->size);
	cppObj->LinkEntry(arg_e);
	return TgNull();
}
extern "C" TgObj* tg_Tangara_Entry_GetClass(void* obj, TgObj* params[])
{
	auto* cppObj = static_cast<Tangara::Entry*>(obj);
	char* arg_name = static_cast<char*>(malloc(params[0]->size));
	memcpy(arg_name, params[0]->data, params[0]->size);
	TgObj* tgObj = TgPtr((void* )cppObj->GetClass(arg_name), TgGetClassHash("Tangara::Class*"));
	return tgObj;
}
extern "C" TgObj* tg_Tangara_Entry_GetName(void* obj, TgObj* params[])
{
	auto* cppObj = static_cast<Tangara::Entry*>(obj);
	TgObj* tgObj = TgPtr((void* const)cppObj->GetName(), TgGetClassHash("const char*"));
	return tgObj;
}
extern "C" TgObj* tg_Tangara_Entry_GetHashCode(void* obj, TgObj* params[])
{
	auto* cppObj = static_cast<Tangara::Entry*>(obj);
	uint32_t result = cppObj->GetHashCode();
	uint32_t* resultPtr = (uint32_t*)malloc(sizeof(uint32_t));
	*resultPtr = result;
	TgObj* tgObj = TgPtr((void* )resultPtr, TgGetClassHash("uint32_t"));
	return tgObj;
}
extern "C" TgObj* tg_Tangara_Class_ctor0(TgObj* params[])
{
	char* arg_name = static_cast<char*>(malloc(params[0]->size));
	memcpy(arg_name, params[0]->data, params[0]->size);
	return TgPtr((void*) new Tangara::Class(arg_name), TgGetClassHash("Tangara.Class"));
}
extern "C" TgObj* tg_Tangara_Class_New(void* obj, TgObj* params[])
{
	auto* cppObj = static_cast<Tangara::Class*>(obj);
	TgParams arg_params = *(TgParams*)params[0]->data;
	TgObj* tgObj = TgPtr((void* )cppObj->New(arg_params), TgGetClassHash("TgObj*"));
	return tgObj;
}
extern "C" TgObj* tg_Tangara_Class_Run(void* obj, TgObj* params[])
{
	auto* cppObj = static_cast<Tangara::Class*>(obj);
	TgObj* arg_self = static_cast<TgObj*>(malloc(params[0]->size));
	memcpy(arg_self, params[0]->data, params[0]->size);
	char* arg_methodName = static_cast<char*>(malloc(params[1]->size));
	memcpy(arg_methodName, params[1]->data, params[1]->size);
	TgParams arg_params = *(TgParams*)params[2]->data;
	TgObj* tgObj = TgPtr((void* )cppObj->Run(arg_self, arg_methodName, arg_params), TgGetClassHash("TgObj*"));
	return tgObj;
}

extern "C" TANGARA_API void* tgLoadEntry() 
{
	Entry *Tangara_entry = TgCreateEntry("Tangara");
	auto *Tangara_Entry_class = new Class("Tangara.Entry");
	TgParamTypes Tangara_Entry_ctor0_paramTypes;
	Tangara_Entry_ctor0_paramTypes.length = 1;
	Tangara_Entry_ctor0_paramTypes.types = (uint32_t*)calloc(1, sizeof(uint32_t));
	Tangara_Entry_ctor0_paramTypes.names = (char**)calloc(1, sizeof(char*));
	Tangara_Entry_ctor0_paramTypes.types[0] = TgGetClassHash("char*");
	Tangara_Entry_ctor0_paramTypes.names[0] = "name";
	Tangara_Entry_class->CreateConstructor(tg_Tangara_Entry_ctor0, Tangara_Entry_ctor0_paramTypes);
	TgParamTypes Tangara_Entry_AddClass_paramTypes;
	Tangara_Entry_AddClass_paramTypes.length = 1;
	Tangara_Entry_AddClass_paramTypes.types = (uint32_t*)calloc(1, sizeof(uint32_t));
	Tangara_Entry_AddClass_paramTypes.names = (char**)calloc(1, sizeof(char*));
	Tangara_Entry_AddClass_paramTypes.types[0] = TgGetClassHash("Tangara.Class*");
	Tangara_Entry_AddClass_paramTypes.names[0] = "cl";
	Tangara_Entry_class->CreateMethod("AddClass", tg_Tangara_Entry_AddClass, TgGetClassHash("void"), Tangara_Entry_AddClass_paramTypes);
	TgParamTypes Tangara_Entry_LinkEntry_paramTypes;
	Tangara_Entry_LinkEntry_paramTypes.length = 1;
	Tangara_Entry_LinkEntry_paramTypes.types = (uint32_t*)calloc(1, sizeof(uint32_t));
	Tangara_Entry_LinkEntry_paramTypes.names = (char**)calloc(1, sizeof(char*));
	Tangara_Entry_LinkEntry_paramTypes.types[0] = TgGetClassHash("Tangara.Entry*");
	Tangara_Entry_LinkEntry_paramTypes.names[0] = "e";
	Tangara_Entry_class->CreateMethod("LinkEntry", tg_Tangara_Entry_LinkEntry, TgGetClassHash("void"), Tangara_Entry_LinkEntry_paramTypes);
	TgParamTypes Tangara_Entry_GetClass_paramTypes;
	Tangara_Entry_GetClass_paramTypes.length = 1;
	Tangara_Entry_GetClass_paramTypes.types = (uint32_t*)calloc(1, sizeof(uint32_t));
	Tangara_Entry_GetClass_paramTypes.names = (char**)calloc(1, sizeof(char*));
	Tangara_Entry_GetClass_paramTypes.types[0] = TgGetClassHash("char*");
	Tangara_Entry_GetClass_paramTypes.names[0] = "name";
	Tangara_Entry_class->CreateMethod("GetClass", tg_Tangara_Entry_GetClass, TgGetClassHash("Tangara::Class*"), Tangara_Entry_GetClass_paramTypes);
	TgParamTypes Tangara_Entry_GetName_paramTypes;
	Tangara_Entry_GetName_paramTypes.length = 0;
	Tangara_Entry_GetName_paramTypes.types = (uint32_t*)calloc(0, sizeof(uint32_t));
	Tangara_Entry_GetName_paramTypes.names = (char**)calloc(0, sizeof(char*));
	Tangara_Entry_class->CreateMethod("GetName", tg_Tangara_Entry_GetName, TgGetClassHash("const char*"), Tangara_Entry_GetName_paramTypes);
	TgParamTypes Tangara_Entry_GetHashCode_paramTypes;
	Tangara_Entry_GetHashCode_paramTypes.length = 0;
	Tangara_Entry_GetHashCode_paramTypes.types = (uint32_t*)calloc(0, sizeof(uint32_t));
	Tangara_Entry_GetHashCode_paramTypes.names = (char**)calloc(0, sizeof(char*));
	Tangara_Entry_class->CreateMethod("GetHashCode", tg_Tangara_Entry_GetHashCode, TgGetClassHash("uint32_t"), Tangara_Entry_GetHashCode_paramTypes);
	Tangara_entry->AddClass(Tangara_Entry_class);
	auto *Tangara_Class_class = new Class("Tangara.Class");
	TgParamTypes Tangara_Class_ctor0_paramTypes;
	Tangara_Class_ctor0_paramTypes.length = 1;
	Tangara_Class_ctor0_paramTypes.types = (uint32_t*)calloc(1, sizeof(uint32_t));
	Tangara_Class_ctor0_paramTypes.names = (char**)calloc(1, sizeof(char*));
	Tangara_Class_ctor0_paramTypes.types[0] = TgGetClassHash("char*");
	Tangara_Class_ctor0_paramTypes.names[0] = "name";
	Tangara_Class_class->CreateConstructor(tg_Tangara_Class_ctor0, Tangara_Class_ctor0_paramTypes);
	TgParamTypes Tangara_Class_New_paramTypes;
	Tangara_Class_New_paramTypes.length = 1;
	Tangara_Class_New_paramTypes.types = (uint32_t*)calloc(1, sizeof(uint32_t));
	Tangara_Class_New_paramTypes.names = (char**)calloc(1, sizeof(char*));
	Tangara_Class_New_paramTypes.types[0] = TgGetClassHash("TgParams");
	Tangara_Class_New_paramTypes.names[0] = "params";
	Tangara_Class_class->CreateMethod("New", tg_Tangara_Class_New, TgGetClassHash("TgObj*"), Tangara_Class_New_paramTypes);
	TgParamTypes Tangara_Class_Run_paramTypes;
	Tangara_Class_Run_paramTypes.length = 3;
	Tangara_Class_Run_paramTypes.types = (uint32_t*)calloc(3, sizeof(uint32_t));
	Tangara_Class_Run_paramTypes.names = (char**)calloc(3, sizeof(char*));
	Tangara_Class_Run_paramTypes.types[0] = TgGetClassHash("TgObj*");
	Tangara_Class_Run_paramTypes.names[0] = "self";
	Tangara_Class_Run_paramTypes.types[1] = TgGetClassHash("char*");
	Tangara_Class_Run_paramTypes.names[1] = "methodName";
	Tangara_Class_Run_paramTypes.types[2] = TgGetClassHash("TgParams");
	Tangara_Class_Run_paramTypes.names[2] = "params";
	Tangara_Class_class->CreateMethod("Run", tg_Tangara_Class_Run, TgGetClassHash("TgObj*"), Tangara_Class_Run_paramTypes);
	Tangara_entry->AddClass(Tangara_Class_class);
	return Tangara_entry;
}