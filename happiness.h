#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <stdlib.h>

#define hap_Reg(l, st, func) lua_register(l, st, func)
#define hap_Init(l) \
	setvbuf(stdin, NULL, _IONBF, 0);\
	setvbuf(stdout, NULL, _IONBF, 0);\
	l = luaL_newstate()

#define hap_Repl(l) \
	char * hap_inbuf;\
	size_t hap_buflen;\
	int hap_ret; \
	while(1){ \
		hap_inbuf = NULL; \
		hap_buflen = 0; \
		getline(&hap_inbuf, &hap_buflen, stdin); \
		hap_inbuf[hap_buflen-1] = '\0'; \
		hap_ret = luaL_loadstring(l, hap_inbuf); \
		if(hap_ret){ \
			printf("Failed to compile:%s\n", lua_tostring(l, -1)); \
			continue; \
		} \
		hap_ret = lua_pcall(l, 0, LUA_MULTRET, 0); \
		if(hap_ret){ \
			printf("Failed to run:%s\n", lua_tostring(l, -1)); \
		} \
		free(hap_inbuf); \
	}

#define hap_getString(l, i) \
	luaL_checkstring(l, i)



/*
 * TODO:
 *
 * hap_getInt
 *
 * hap_retInt
 * hap_retString
 *
 * hap_getUserData
 * hap_retUserData
 *
 * All the class stuff
 */
