#include "tgstdlib.h"
#include <cstdlib>

tgEntry* tgLoadStdLib() {
    auto *stdEntry = (tgEntry*) malloc(sizeof(tgEntry));
    stdEntry->hash = 2182830100; // "Tangara.Std" hash
    stdEntry->name = "Tangara.Std";
    stdEntry->is_interface = false;
    return stdEntry;
}
