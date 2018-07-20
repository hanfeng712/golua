#ifndef _TEST_H_
#define _TEST_H_

#include <stdio.h> 
#include <unistd.h> 

#include <lua5.2/lua.h> 
#include <lua5.2/lauxlib.h> 
#include <lua5.2/lualib.h> 

// extern "C"{

//interfaces for golang call.
void *init_lua();
int load_lua_file(void *p_luaCtx, const char *p_pszFilename);
void uninit(void *p_luaCtx);
int cAddFuncLua(void *p_luaCtx,int param);
int cAddFuncGo(lua_State *L);
/******************httpclient********************************/
int HttpRequestGet(lua_State *L);
int HttpRequestPost(lua_State *L);
// }
#endif