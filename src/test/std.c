#include "std.h"

void init_std()
{
    TgClass str = tgInitClass(PUBLIC, DEFAULT, STR("string"));
    strClass = &str;
    TgClass _int = tgInitClass(PUBLIC, DEFAULT, STR("int"));
    intClass = &_int;
}