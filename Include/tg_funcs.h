#ifndef TANGARA_TG_FUNCS_H
#define TANGARA_TG_FUNCS_H
#include "tg_structs.h"

#ifdef __cplusplus
extern "C"
{
#else
#include <stdbool.h>
#endif

const tgType* tgFindTypeByName(const char* type_name, tgEntry* in_entry);
const tgType* tgFindTypeByHash(uint type_hash, tgEntry* in_entry);

tgTypeRef tgCreateNameTypeRef(const char* type_name);
tgTypeRef tgCreateHashTypeRef(uint type_hash);
tgTypeRef tgCreateDirectTypeRef(tgType *type);
const tgType* tgResolveTypeRef(tgTypeRef* type_ref, tgEntry* in_entry);

inline bool tgCompareTypes(tgType lhs, tgType rhs) {
    return lhs.hash < rhs.hash;
}
inline bool tgCompareEntries(tgEntry lhs, tgEntry rhs) {
    return lhs.hash < rhs.hash;
}

tgConstValue tgDefaultValue(tgType* type);

tgObject* tgConvertValToObj(tgConstValue value);

#ifdef __cplusplus
}
#endif
#endif //TANGARA_TG_FUNCS_H
