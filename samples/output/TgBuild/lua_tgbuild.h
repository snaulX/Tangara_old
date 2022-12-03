#ifndef TGBUILD_LUA_TGBUILD_H
#define TGBUILD_LUA_TGBUILD_H
#include "lauxlib.h"

int tgbuild_include(lua_State *L);

int luaopen_tgbuild(lua_State *L);

#endif //TGBUILD_LUA_TGBUILD_H
