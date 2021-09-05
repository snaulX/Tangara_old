#include "Tangara.h"
#include "File.h"

int main(void)
{
    TgClass string = tgInitClass(PUBLIC, DEFAULT, STR("string"));
    TgField name = tgInitField(PUBLIC, DEFAULT, STR("name"), &string, STR("Alexander"));
    TgVarBlock params = tgInitVarBlock();
    TgFunc func = tgInitFunc(PUBLIC, DEFAULT, STR("func"), NULL, &params);
    TgClass main = tgInitClass(PUBLIC, DEFAULT, STR("Main"));
    TgFieldBlock fb = tgInitFieldBlock();
    main.fields = &fb;
    tgAddField(name, &fb /*main.fields*/);
    //tgAddFunc(func, main.methods);
    TgClassBlock clb = tgInitClassBlock();
    tgAddClass(main, &clb);
    print(clb.classes[0].name);
    FILE* file = tgOpenWrite("test.tgr");
    tgWriteClassBlock(file, &clb);
    tgCloseFile(file);
    file = tgOpenRead("test.tgr");
    tgReadClassBlock(file, &clb);
    print(clb.classes[0].fields->fields[0].var.value);
}