#include <stdlib.h>
#include "dlload.h"
#include "lua_tgbuild.h"

int tgbuild_include(lua_State *L) {
    size_t modname_size = 0;
    const char *modname = luaL_checklstring(L, 1, &modname_size);
    modname_size += 11 /* "tgbuild.lua" */ + 2 /* '/'x2 */ + 7 /* "Modules" */ + 1 /*'\0'*/;
    char *fpath = (char*)malloc(modname_size);
    sprintf_s(fpath, modname_size, "Modules\\%s\\tgbuild.lua", modname);
    if (luaL_dofile(L, fpath) != LUA_OK) {
        lua_error(L);
    }
    free(fpath);
    return 1;
}

static const struct luaL_Reg tgbuildlib[] = {
        {"Include", tgbuild_include},
        {NULL, NULL}
};

int luaopen_tgbuild(lua_State *L) {
    lua_newtable(L);
    luaL_setfuncs(L, tgbuildlib, 0);
    lua_setglobal(L, "TgBuild");
    return 1;
}
