#ifndef TANGARA_TG_ENUMS_H
#define TANGARA_TG_ENUMS_H

/// Options to find type by reference
enum tgFindType {
    FindType_Name,
    FindType_Hash,
    FindType_Direct,
};
enum tgAccessModifier {
    AccessModifier_Private,
    AccessModifier_Public,
    AccessModifier_Protected,
    AccessModifier_Internal,
};
enum tgTypeKind {
    TypeKind_Class,
    TypeKind_AbstractClass,
    TypeKind_StaticClass,
    TypeKind_FinalClass,
    TypeKind_Struct,
    TypeKind_Interface,
    TypeKind_TypeAlias,
    TypeKind_Singleton,
    TypeKind_Enum,
};
enum tgParamKind {
    ParamKind_Default,
    ParamKind_Out,
    ParamKind_Ref,
    ParamKind_In,
    ParamKind_Params
};
/// Types of possible constant values
enum tgValueType {
    /// Value hasn't anything
    ValueType_Null,
    ValueType_Bool,
    /// Unsigned byte (0-256)
    ValueType_Byte,
    ValueType_Short,
    ValueType_Int,
    ValueType_Long,
    ValueType_Float,
    ValueType_Double,
    /// Signed byte
    ValueType_SByte,
    ValueType_UShort,
    ValueType_UInt,
    ValueType_ULong,
    /// C-style ASCII null-terminated string
    ValueType_CStr,
    /// UTF-8 string
    ValueType_Str,
    ValueType_Array,
    /// Value with lazy initialization
    ValueType_Lazy
};
enum tgMethodKind {
    MethodKind_Default,
    MethodKind_Static,
    MethodKind_Abstract,
    MethodKind_Virtual,
};
enum tgFieldKind {
    FieldKind_Default,
    FieldKind_Const,
    FieldKind_Final,
    FieldKind_Static
};

#endif //TANGARA_TG_ENUMS_H
