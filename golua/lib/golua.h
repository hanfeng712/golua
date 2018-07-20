#ifndef _GOLUA_H_
#define _GOLUA_H_

#include <stdio.h> 
#include <unistd.h> 

#include <lua5.1/lua.h> 
#include <lua5.1/lauxlib.h> 
#include <lua5.1/lualib.h> 

// extern "C"{

//interfaces for golang call.
void *init_lua();
int load_lua_file(void *p_luaCtx, const char *p_pszFilename);
int process_request(void *p_luaCtx, void *p_reqCtx);
void uninit(void *p_luaCtx);
int get_uri_path(lua_State *L);
int read_body_data(lua_State *L);
int write_data(lua_State *L);

// }
#endif