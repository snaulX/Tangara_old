#include "TangaraCore.h"
#include "File.h"

int main(void)
{
    TgClass string = tgInitClass(PUBLIC, DEFAULT, STR("string"));
    TgField name = tgInitField(PUBLIC, DEFAULT, STR("name"), &string, STR("Alexander"));
    ARR_VAR(TgVar, params)
    TgFunc func = tgInitFunc(PUBLIC, DEFAULT, STR("func"), NULL, &params);
    TgClass main = tgInitClass(PUBLIC, DEFAULT, STR("Main"));
    ARR_VAR(TgField, fields)
    ADD(TgField, name, &fields);
    main.fields = &fields;
    ARR_VAR(TgClass, classes)
    ADD(TgClass, main, &classes);
    ADD(TgClass, string, &classes);
    FILE *file = tgOpenWrite("test.tgr");
    WRITEARR(file, TgClass, &classes);
    tgCloseFile(file);
    file = tgOpenRead("test.tgr");
    READARR(file, TgClass, &classes);
    for (int i = 0; i < classes.count; i++)
        print(GET(TgClass, i, classes)->name);
}