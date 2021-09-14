#include "TangaraCore.h"

TgClass tgInitClass(unsigned visibility, unsigned class_type, char_t* name)
{
    ARR_VAR(TgField, fields)
    ARR_VAR(TgFunc, methods)
    TgClass _class = {visibility, class_type, name, &fields, &methods};
    return _class;
}
TgFunc tgInitFunc(unsigned visibility, unsigned func_type, char_t* name, TgClass* return_type, ARRNAME(TgVar) *params)
{
    TgFunc func = {visibility, func_type, name, return_type, params};
    return func;
}
TgField tgInitField(unsigned visibility, unsigned field_type, char_t* name, TgClass* type, void* value)
{
    TgField field = {visibility, field_type, name, type, value};
    return field;
}
