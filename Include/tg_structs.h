#ifndef TANGARA_TG_STRUCTS_H
#define TANGARA_TG_STRUCTS_H
#include "tg_enums.h"

typedef unsigned int uint;

#ifdef __cplusplus
struct tgEntry;
struct tgType;
struct tgMethod;
struct tgObject;
struct tgParams;
struct tgConstValue;
struct tgCtor;
struct tgField;
struct tgProp;
struct tgEvent;
struct tgEvent;
struct tgTypeRef;
#else
#include <stdbool.h>

typedef struct tgEntry tgEntry;
typedef struct tgType tgType;
typedef struct tgMethod tgMethod;
typedef struct tgObject tgObject;
typedef struct tgParams tgParams;
typedef struct tgConstValue tgConstValue;
typedef struct tgCtor tgCtor;
typedef struct tgField tgField;
typedef struct tgProp tgProp;
typedef struct tgEvent tgEvent;
typedef struct tgTypeRef tgTypeRef;
#endif

typedef tgObject*(*tgMethodFuncPtr)(tgObject*, size_t, tgObject*, void*);
typedef tgObject*(*tgCtorFuncPtr)(size_t, tgObject*, void*);
typedef tgObject*(*tgPropGetFuncPtr)(tgObject*, void*);
typedef void(*tgPropSetFuncPtr)(tgObject*, tgObject*, void*);
typedef tgObject*(*tgLazyValueFuncPtr)(void*);

struct tgConstValue {
    enum tgValueType type;
    void *value;
};

struct tgTypeRef {
    tgType *cached_type;
    void* ref_data;
    enum tgFindType find_type;
};

struct tgParams {
    size_t params_count;
    tgTypeRef *types;
    const char **names;
    enum tgParamKind *kinds;
    tgConstValue *default_values;
};

struct tgMethod {
    const char *name;
    enum tgAccessModifier access;
    enum tgMethodKind kind;
    tgTypeRef return_type;
    tgParams params;
    size_t overrides_size;
    tgMethod *overrides;

    void *userptr;
    tgMethodFuncPtr methodptr;
};

struct tgCtor {
    tgParams params;
    enum tgAccessModifier access;

    void *userptr;
    tgCtorFuncPtr ctorptr;
};

struct tgField {
    const char *name;
    tgTypeRef type;
    enum tgAccessModifier access;
    enum tgFieldKind kind;
    tgConstValue default_value;
};

struct tgProp {
    const char *name;
    tgTypeRef type;
    enum tgMethodKind kind;

    void *userptr;

    enum tgAccessModifier access_get;
    tgPropGetFuncPtr getfuncptr;

    enum tgAccessModifier access_set;
    tgPropSetFuncPtr setfuncptr;
    bool is_final; // 'init' instead of 'set' if we're looking on C#
};

struct tgEvent {
    const char *name;
};

struct tgType {
    uint hash;
    const char *name;
    enum tgAccessModifier access;
    enum tgTypeKind kind;
    size_t parents_size;
    tgTypeRef *parents;
    size_t methods_size;
    tgMethod *methods;
    size_t ctors_size;
    tgCtor *ctors;
    size_t fields_size;
    tgField *fields;
    size_t props_size;
    tgProp *props;
    size_t events_size;
    tgEvent *events;
};

struct tgObject {
    tgType *type;
    size_t data_size;
    void *data;
};

struct tgEntry {
    uint hash;
    const char *name;
    bool is_interface;
    size_t types_size;
    tgType *types;
    size_t fields_size;
    tgField *fields;
    size_t props_size;
    tgProp *props;
    size_t methods_size;
    tgMethod *methods;
    size_t events_size;
    tgEvent *events;
    size_t ctors_size;
    tgCtor *ctors;
};

#endif //TANGARA_TG_STRUCTS_H
