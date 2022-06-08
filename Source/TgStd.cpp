#include "TgStd.h"
#include <memory>

using namespace Tangara;
namespace Tangara::Std {
    static Entry* StdEntry;

    static Class* PtrClass;

    static Class* VoidClass;
    static Class* CharClass;
    // Signed numbers
    static Class* SByteClass;
    static Class* ShortClass;
    static Class* IntClass;
    static Class* LongClass;
    // Unsigned numbers
    static Class* ByteClass;
    static Class* UShortClass;
    static Class* UIntClass;
    static Class* ULongClass;
    // Numbers with float point
    static Class* FloatClass;
    static Class* DoubleClass;
    // Strings
    static Class* CStrClass;
    static Class* StrClass;

    Entry *GetEntry() {
        return StdEntry;
    }

    Class *GetPtrClass() {
        return PtrClass;
    }

    Class *GetVoidClass() {
        return VoidClass;
    }

    Class *GetCharClass() {
        return CharClass;
    }

    Class *GetSByteClass() {
        return SByteClass;
    }

    Class *GetShortClass() {
        return ShortClass;
    }

    Class *GetIntClass() {
        return IntClass;
    }

    Class *GetLongClass() {
        return LongClass;
    }

    Class *GetByteClass() {
        return ByteClass;
    }

    Class *GetUShortClass() {
        return UShortClass;
    }

    Class *GetUIntClass() {
        return UIntClass;
    }

    Class *GetULongClass() {
        return ULongClass;
    }

    Class *GetFloatClass() {
        return FloatClass;
    }

    Class *GetDoubleClass() {
        return DoubleClass;
    }

    Class *GetCStrClass() {
        return CStrClass;
    }

    Class *GetStrClass() {
        return StrClass;
    }
}

using namespace Tangara::Std;

static bool isStdInited = false;
void *TgStdInit() {
    if (isStdInited) return StdEntry;

    StdEntry = new Entry("Std");

    PtrClass = new Class("*");

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

    StdEntry->AddClass(PtrClass);
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

    isStdInited = true;
    return StdEntry;
}

void *TgStdEntry() {
    return StdEntry;
}

static TgObj *tgNull;
TgObj *TgNull() {
    if (!tgNull) tgNull = TgPtr(nullptr, VoidClass->GetHashCode());
    return tgNull;
}
TgObj *TgMakePtr(TgObj* data) {
    return TgPtr(&(data->data), data->type_hash + TgPtrHash());
}
TgObj *TgStr(const char* str) {
    auto *tgObj = (TgObj*) malloc(sizeof(TgObj));
    tgObj->type_hash = CStrClass->GetHashCode();
    tgObj->data = (void*)str;
    tgObj->size = sizeof(str) + sizeof(char); // include '\0'
    return tgObj;
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

uint32_t TgPtrHash() {
    return PtrClass->GetHashCode();
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
