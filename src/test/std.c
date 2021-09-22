#include "std.h"

void init_std()
{
    TgClass str = tgInitClass(TG_VISIBILITY_PUBLIC, TG_MEMBTYPE_DEFAULT, STR("string"));
    strClass = &str;
    TgClass _int = tgInitClass(TG_VISIBILITY_PUBLIC, TG_MEMBTYPE_DEFAULT, STR("int"));
    intClass = &_int;
}