#include "TangaraCore.h"
#include "File.h"

GEN_ARRAY(TgField)

int main(void)
{
    TgClass string = tgInitClass(PUBLIC, DEFAULT, STR("string"));
    TgField name = tgInitField(PUBLIC, DEFAULT, STR("name"), &string, STR("Alexander"));
    TgVarBlock params = tgInitVarBlock();
    TgFunc func = tgInitFunc(PUBLIC, DEFAULT, STR("func"), NULL, &params);
    TgClass main = tgInitClass(PUBLIC, DEFAULT, STR("Main"));
    TgFieldBlock fb = tgInitFieldBlock();
    ARR_VAR(TgField, fields)
    ADD(TgField, name, fields);
    print(GET(TgField, 0, fields)->var.name);
    main.fields = &fb;
    TgFuncBlock funcBlock = tgInitFuncBlock();
    main.methods = &funcBlock;
    tgAddField(name, &fb);
    tgAddFunc(func, &funcBlock);
    TgClassBlock clb = tgInitClassBlock();
    tgAddClass(main, &clb);
    tgAddClass(string, &clb);
    print(clb.classes[0].name);
    FILE* file = tgOpenWrite("test.tgr");
    tgWriteClassBlock(file, &clb);
    tgCloseFile(file);
    file = tgOpenRead("test.tgr");
    tgReadClassBlock(file, &clb);
    printf("Class block contains:\n");
    for (int i = 0; i < clb.count; i++)
        wprintf(L"\tClass: %s\n", clb.classes[i].name);
}