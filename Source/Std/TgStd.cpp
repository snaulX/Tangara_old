#include "TgStd.h"
#include <memory>

using namespace Tangara;
using namespace Tangara::Std;

void *TgStdInit() {
    StdEntry = new Entry("Std");

    VoidClass = new Class("void");
    CharClass = new Class("char");
    // Signed numbers
    SByteClass = new Class("sbyte");
    ShortClass = new Class("short");
    IntClass = new Class("int");
    LongClass = new Class("long");
    // Unsigned numbers
    ByteClass = new Class("byte");
    UShortClass = new Class("ushort");
    UIntClass = new Class("uint");
    ULongClass = new Class("ulong");
    // Numbers with float point
    FloatClass = new Class("float");
    DoubleClass = new Class("double");
    // Strings
    CStrClass = new Class("cstring");
    StrClass = new Class("string");

    StdEntry->AddClass(VoidClass);
    StdEntry->AddClass(CharClass);
    StdEntry->AddClass(SByteClass);
    StdEntry->AddClass(ShortClass);
    StdEntry->AddClass(IntClass);
    StdEntry->AddClass(LongClass);
    StdEntry->AddClass(ByteClass);
    StdEntry->AddClass(UShortClass);
    StdEntry->AddClass(UIntClass);
    StdEntry->AddClass(ULongClass);
    StdEntry->AddClass(FloatClass);
    StdEntry->AddClass(DoubleClass);
    StdEntry->AddClass(CStrClass);
    StdEntry->AddClass(StrClass);

    return StdEntry;
}

TgObj *TgNull() {
    return TgPtr(nullptr, VoidClass->GetHashCode());
}
TgObj *TgInt(int data) {
    auto *dataPtr = (int *) malloc(sizeof(int));
    *dataPtr = data;
    auto *tgObj = (TgObj *) malloc(sizeof(TgObj));
    tgObj->type_hash = IntClass->GetHashCode();
    tgObj->data = dataPtr;
    tgObj->size = sizeof(int);
    return tgObj;
}
TgObj *TgFloat(float data) {
    auto *dataPtr = (float *) malloc(sizeof(float));
    *dataPtr = data;
    auto *tgObj = (TgObj *) malloc(sizeof(TgObj));
    tgObj->type_hash = FloatClass->GetHashCode();
    tgObj->data = dataPtr;
    tgObj->size = sizeof(float);
    return tgObj;
}

uint32_t TgVoidHash() {
    return VoidClass->GetHashCode();
}

uint32_t TgIntHash() {
    return IntClass->GetHashCode();
}

uint32_t TgFloatHash() {
    return FloatClass->GetHashCode();
}

uint32_t TgCStrHash() {
    return CStrClass->GetHashCode();
}

uint32_t TgStrHash() {
    return StrClass->GetHashCode();
}
