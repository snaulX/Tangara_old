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
