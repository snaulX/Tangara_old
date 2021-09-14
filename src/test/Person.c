#include "Person.h"

TgClass *createPersonClass()
{
    TgClass cl = tgInitClass(PUBLIC, DEFAULT, STR("Person"));
    TgField name = tgInitField(PUBLIC, DEFAULT, STR("Name"), strClass, STR("Alexander"));
    TgField surname = tgInitField(PUBLIC, DEFAULT, STR("Surname"), strClass, STR("Gunger"));
    int _age = 16;
    TgField age = tgInitField(PUBLIC, DEFAULT, STR("Age"), intClass, &_age);
    ARR_VAR(TgField, fields)
    ADD(TgField, name, &fields);
    ADD(TgField, surname, &fields);
    ADD(TgField, age, &fields);
    cl.fields = &fields;
    return &cl;
}
