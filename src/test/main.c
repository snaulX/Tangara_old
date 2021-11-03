#include "Person.h"
#include "File.h"

int main(void)
{
    init_std();
    printf("%u\n", sizeof(TgVisibility));
    TgField name = tgInitField(TG_VISIBILITY_PUBLIC, TG_MEMBTYPE_DEFAULT, STR("name"), strClass, STR("Alexander"));
    ARR_VAR(TgVar, params)
    TgFunc func = tgInitFunc(TG_VISIBILITY_PUBLIC, TG_MEMBTYPE_DEFAULT, STR("func"), NULL, &params);
    TgClass main = tgInitClass(TG_VISIBILITY_PUBLIC, TG_MEMBTYPE_DEFAULT, STR("Main"));
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
    classes = INIT_ARRAY(TgClass); // clear (re-init) our array
    file = tgOpenRead("test.tgr");
    READARR(file, TgClass, &classes);
    for (int i = 0; i < classes.count; i++)
    {
        TgClass *cl = GET(TgClass, i, classes);
        print(cl->name);
        if (cl->fields->count > 0)
        {
            for (int j = 0; j < cl->fields->count; j++)
            {
                print(GET(TgField, j, *cl->fields)->var.name);
            }
        }
    }
}