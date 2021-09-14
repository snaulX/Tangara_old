#include "Person.h"
#include "File.h"

int main(void)
{
    init_std();
    TgField name = tgInitField(PUBLIC, DEFAULT, STR("name"), strClass, STR("Alexander"));
    ARR_VAR(TgVar, params)
    TgFunc func = tgInitFunc(PUBLIC, DEFAULT, STR("func"), NULL, &params);
    TgClass main = tgInitClass(PUBLIC, DEFAULT, STR("Main"));
    ARR_VAR(TgField, fields)
    ADD(TgField, name, &fields);
    main.fields = &fields;
    ARR_VAR(TgClass, classes)
    TgClass person = *createPersonClass();
    ADD(TgClass, main, &classes);
    //ADD(TgClass, *strClass, &classes);
    //ADD(TgClass, *intClass, &classes);
    ADD(TgClass, person, &classes);
    FILE *file = tgOpenWrite("test.tgr");
    WRITEARR(file, TgClass, &classes);
    tgCloseFile(file);
    classes = INIT_ARRAY(TgClass); // clear (re-init_std) our array
    file = tgOpenRead("test.tgr");
    READARR(file, TgClass, &classes);
    for (int i = 0; i < classes.count; i++)
        print(GET(TgClass, i, classes)->name);
}