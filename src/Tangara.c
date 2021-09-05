#include "Tangara.h"

ClassBlock init_class_block()
{
    ClassBlock classBlock = {0, NULL};
    return classBlock;
}
FuncBlock init_func_block()
{
    FuncBlock funcBlock = {0, NULL};
    return funcBlock;
}
VarBlock init_var_block()
{
    VarBlock varBlock = {0, NULL};
    return varBlock;
}
FieldBlock init_field_block()
{
    FieldBlock fieldBlock = {0, NULL};
    return fieldBlock;
}

Class init_class(unsigned visibility, unsigned class_type, char* name)
{
    FieldBlock fields = init_field_block();
    FuncBlock methods = init_func_block();
    Class _class = {visibility, class_type, name, &fields, &methods};
    return _class;
}
Func init_func(unsigned visibility, unsigned func_type, char* name, Class* return_type, VarBlock* params)
{
    Func func = {visibility, func_type, name, return_type, params};
    return func;
}
Field init_field(unsigned visibility, unsigned field_type, char* name, Class* type, void* value)
{
    Field field = {visibility, field_type, name, type, value};
    return field;
}

void add_class(Class cl, ClassBlock* classBlock)
{
    classBlock->classes = realloc(classBlock->classes, ++classBlock->count * CLASS_SIZE);
    classBlock->classes[classBlock->count - 1] = cl;
}
void add_func(Func func, FuncBlock* funcBlock)
{
    funcBlock->functions = realloc(funcBlock->functions, ++funcBlock->count * FUNC_SIZE);
    funcBlock->functions[funcBlock->count - 1] = func;
}
void add_var(Var var, VarBlock* varBlock)
{
    varBlock->variables = realloc(varBlock->variables, ++varBlock->count * VAR_SIZE);
    varBlock->variables[varBlock->count - 1] = var;
}
void add_field(Field field, FieldBlock* fieldBlock)
{
    fieldBlock->fields = realloc(fieldBlock->fields, ++fieldBlock->count * FIELD_SIZE);
    fieldBlock->fields[fieldBlock->count - 1] = field;
}
