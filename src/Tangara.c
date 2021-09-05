#include "Tangara.h"

TgClassBlock tgInitClassBlock()
{
    TgClassBlock classBlock = {0, NULL};
    return classBlock;
}
TgFuncBlock tgInitFuncBlock()
{
    TgFuncBlock funcBlock = {0, NULL};
    return funcBlock;
}
TgVarBlock tgInitVarBlock()
{
    TgVarBlock varBlock = {0, NULL};
    return varBlock;
}
TgFieldBlock tgInitFieldBlock()
{
    TgFieldBlock fieldBlock = {0, NULL};
    return fieldBlock;
}

TgClass tgInitClass(unsigned visibility, unsigned class_type, char_t* name)
{
    TgFieldBlock fields = tgInitFieldBlock();
    TgFuncBlock methods = tgInitFuncBlock();
    TgClass _class = {visibility, class_type, name, &fields, &methods};
    return _class;
}
TgFunc tgInitFunc(unsigned visibility, unsigned func_type, char_t* name, TgClass* return_type, TgVarBlock* params)
{
    TgFunc func = {visibility, func_type, name, return_type, params};
    return func;
}
TgField tgInitField(unsigned visibility, unsigned field_type, char_t* name, TgClass* type, void* value)
{
    TgField field = {visibility, field_type, name, type, value};
    return field;
}

void tgAddClass(TgClass cl, TgClassBlock* classBlock)
{
    classBlock->classes = realloc(classBlock->classes, ++classBlock->count * CLASS_SIZE);
    classBlock->classes[classBlock->count - 1] = cl;
}
void tgAddFunc(TgFunc func, TgFuncBlock* funcBlock)
{
    funcBlock->functions = realloc(funcBlock->functions, ++funcBlock->count * FUNC_SIZE);
    funcBlock->functions[funcBlock->count - 1] = func;
}
void tgAddVar(TgVar var, TgVarBlock* varBlock)
{
    varBlock->variables = realloc(varBlock->variables, ++varBlock->count * VAR_SIZE);
    varBlock->variables[varBlock->count - 1] = var;
}
void tgAddField(TgField field, TgFieldBlock* fieldBlock)
{
    fieldBlock->fields = realloc(fieldBlock->fields, ++fieldBlock->count * FIELD_SIZE);
    fieldBlock->fields[fieldBlock->count - 1] = field;
}
