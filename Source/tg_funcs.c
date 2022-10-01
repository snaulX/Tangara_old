#include "tg_funcs.h"
#include <stdlib.h>
#include <string.h>

const tgType *tgFindTypeByName(const char *type_name, tgEntry *in_entry) {
    for (int i = 0; i < in_entry->types_size; ++i) {
        if (strcmp(in_entry->types[i].name, type_name) == 0) {
            return &in_entry->types[i];
        }
    }
    return NULL;
}

const tgType *tgFindTypeByHash(uint type_hash, tgEntry *in_entry) {
    for (int i = 0; i < in_entry->types_size; ++i) {
        if (in_entry->types[i].hash == type_hash) {
            return &in_entry->types[i];
        }
    }
    return NULL;
}

tgTypeRef tgCreateNameTypeRef(const char *type_name) {
    tgTypeRef result = {NULL, type_name, FindType_Name};
    return result;
}

tgTypeRef tgCreateHashTypeRef(uint type_hash) {
    uint* hashptr = (uint*)malloc(sizeof(uint));
    *hashptr = type_hash;
    tgTypeRef result = {NULL, hashptr, FindType_Hash};
    return result;
}

tgTypeRef tgCreateDirectTypeRef(tgType *type) {
    tgTypeRef result = {type, type, FindType_Direct};
    return result;
}

const tgType *tgResolveTypeRef(tgTypeRef *type_ref, tgEntry* in_entry) {
    if (type_ref->cached_type) {
        return type_ref->cached_type;
    } else {
        const tgType *result;
        switch (type_ref->find_type) {
            case FindType_Direct:
                result = (tgType*)type_ref->ref_data;
                break;
            case FindType_Hash:
                result = tgFindTypeByHash(*((uint*) type_ref->ref_data), in_entry);
                break;
            case FindType_Name:
                result = tgFindTypeByName((const char*) type_ref->ref_data, in_entry);
                break;
        }
        type_ref->cached_type = result;
        return result;
    }
}

static tgObject *defaultEmptyCtorValue(void *ctor_ptr) {
    tgCtor *ctor = (tgCtor*)ctor_ptr;
    tgCtorFuncPtr ctor_func = ctor->ctorptr;
    return ctor_func(0, NULL, ctor->userptr);
}

static tgObject *getStaticPropValue(void *prop_ptr) {
    tgProp *prop = (tgProp*)prop_ptr;
    return prop->getfuncptr(NULL, prop->userptr);
}

tgConstValue tgDefaultValue(tgType* type) {
    tgConstValue result = {};
    switch (type->kind) {
        case TypeKind_Interface:
        case TypeKind_FinalClass:
        case TypeKind_Class:
        case TypeKind_AbstractClass:
            result.type = ValueType_Null;
            result.value = NULL;
            break;
        case TypeKind_Struct:
            result.type = ValueType_Lazy;
            for (int i = type->ctors_size-1; i >= 0; --i) {
                tgCtor* ctor = &type->ctors[i];
                if (ctor->params.params_count == 0) {
                    tgLazyObject *lazyStructInit = (tgLazyObject*) malloc(sizeof(tgLazyObject));
                    lazyStructInit->lazyPtr = defaultEmptyCtorValue;
                    lazyStructInit->funcPtr = ctor;
                }
            }
            break;
        case TypeKind_StaticClass:
            break;
        case TypeKind_TypeAlias:
            break;
        case TypeKind_Singleton:
            result.type = ValueType_Lazy;
            tgLazyObject *lazySingleton = (tgLazyObject*) malloc(sizeof(tgLazyObject));
            lazySingleton->lazyPtr = getStaticPropValue;
            /*tgProp *instanceProp;
            for (int i = type->props_size-1; i >= 0; --i) {
                if (strcmp("Instance", type->props[i].name) == 0) {
                    instanceProp = &type->props[i];
                }
            }*/
            lazySingleton->funcPtr = &type->props[type->props_size-1]; // get instance property
            break;
        case TypeKind_Enum:
            result.type = ValueType_Enum;
            result.value = &type->fields[0].default_value;
            break;
    }
    return result;
}
