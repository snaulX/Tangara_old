#include "tgstdlib.h"
#include "EntryBuilder.hpp"
#include "ClassBuilder.hpp"

//#define TYPES_SIZE 3
//#define METHODS_SIZE 0

using namespace Tangara;

static tgEntry* stdEntry;

static tgType* voidType;
static tgType* intType;
static tgType* cstrType;

tgEntry* tgLoadStdLib() {
    /*auto *stdEntry = (tgEntry*) malloc(sizeof(tgEntry));
    stdEntry->name = "Tangara.Std";
    stdEntry->hash = 2182830100;
    stdEntry->is_interface = false;

    stdEntry->types_size = TYPES_SIZE;
    stdEntry->types = (tgType*) calloc(TYPES_SIZE, sizeof(tgType));

    // void
    voidType = &stdEntry->types[0];
    memset(voidType, 0, sizeof(tgType));
    voidType->name = "void";
    voidType->hash = 1605909471;
    voidType->kind = TypeKind_Struct;

    // int
    intType = &stdEntry->types[1];
    memset(intType, 0, sizeof(tgType));
    intType->name = "int";
    intType->hash = 3347085701;
    intType->kind = TypeKind_Struct;

    // cstring
    cstrType = &stdEntry->types[2];
    memset(cstrType, 0, sizeof(tgType));
    cstrType->name = "CString";
    cstrType->hash = 3452386436;
    cstrType->kind = TypeKind_FinalClass;
    return stdEntry;*/
    if (stdEntry) return stdEntry;

    auto rule = EntryRule();
    rule.TypeAccess(AccessModifier_Public);
    auto eb = EntryBuilder("Tangara.Std", &rule);

    // void
    voidType = (tgType*) malloc(sizeof(tgType));
    *voidType = eb.CreateClass("void")
        .Build();

    // int
    intType = (tgType*) malloc(sizeof(tgType));
    *intType = eb.CreateClass("int")
        .Build();

    // CString
    cstrType = (tgType*) malloc(sizeof(tgType));
    *cstrType = eb.CreateClass("CString")
        .Build();

    stdEntry = (tgEntry*) malloc(sizeof(tgEntry));
    *stdEntry = eb.Build();
    return stdEntry;
}

tgType *tgVoidType() {
    return voidType;
}

tgType *tgIntType() {
    return intType;
}

tgType *tgCStrType() {
    return cstrType;
}


