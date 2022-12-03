#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include "tgbuild_util.h"
#include "lua_tgbuild.h"

int main(int argc, char** argv) {
    if (argc == 1) perror("Cannot run `tgbuild` without arguments");

    // Lua loading
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    luaopen_tgbuild(L);
    const size_t fpath_len = strlen(argv[1]) + 11 /* "tgbuild.lua" */ + 1 /* for '\'*/ + 1 /*'\0'*/;
    char *fpath = (char*)malloc(fpath_len);
    sprintf_s(fpath, fpath_len, "%s\\tgbuild.lua", argv[1]);
    if (luaL_dofile(L, fpath) != LUA_OK) {
        perror(lua_tostring(L, -1));
    }
    free(fpath);
    lua_close(L);

    return 0;
}
