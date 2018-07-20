#include "test.h"

int testFunc1() 
{ 
	lua_State *L; 
	if(NULL == (L = luaL_newstate())) 
	{ 
		perror("luaL_newstate failed"); 
		return -1; 
	} 
	luaL_openlibs(L); 
	if(luaL_loadfile(L, "/home/hanfeng/golang/src/golua/testLua/HelloWord.lua")) 
	{	 
		perror("loadfile failed"); 
		return -1; 
	} 
	lua_pcall(L, 0, 0, 0); //一直这样用，但是一直不明白为什么一定要加这一句话 

	lua_getglobal(L, "printmsg"); 
	lua_pcall(L, 0, 0, 0); 

	lua_close(L); 

	return 0; 
} 

int add(int a,int b){
	return a + b;
}