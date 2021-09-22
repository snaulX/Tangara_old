#include "Person.h"

TgClass *createPersonClass()
{
    TgClass cl = tgInitClass(TG_VISIBILITY_PUBLIC, TG_MEMBTYPE_DEFAULT, STR("Person"));
    TgField name = tgInitField(TG_VISIBILITY_PUBLIC, TG_MEMBTYPE_DEFAULT, STR("Name"), strClass, STR("Alexander"));
    TgField surname = tgInitField(TG_VISIBILITY_PUBLIC, TG_MEMBTYPE_DEFAULT, STR("Surname"), strClass, STR("Gunger"));
    int _age = 16;
    TgField age = tgInitField(TG_VISIBILITY_PUBLIC, TG_MEMBTYPE_DEFAULT, STR("Age"), intClass, &_age);
    ARR_VAR(TgField, fields)
    ADD(TgField, name, &fields);
    ADD(TgField, surname, &fields);
    ADD(TgField, age, &fields);
    cl.fields = &fields;
    return &cl;
}
