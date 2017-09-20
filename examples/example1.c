#include <happiness.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FLAGSTRING "adminstring"

int chalEncrypt(lua_State * L){
	char * arg1;
	arg1 = strdup(hap_getString(L, 1));
	int i;
	char t = 1;

	if(!strcmp(arg1, FLAGSTRING)){
		printf("Hah! you thought it would be that easy?\n");
		free(arg1);
		return 0;
	}

	int slen = 0;
	slen = strlen(arg1);

	for(i=0; i < strlen(arg1); i++){
		arg1[i] = arg1[i] ^ t;
		t *= 13;
	}

	printf("=> ");
	for(i=0; i < slen; i++){
		printf("%02hhx ", arg1[i]);
	}
	printf("\n");

	free(arg1);
	return 0;
}

int chalDecrypt(lua_State * L){
	char * arg1;
	arg1 = strdup(hap_getString(L, 1));
	int i;
	char t = 1;

	for(i=0; i < strlen(arg1); i++){
		arg1[i] = arg1[i] ^ t;
		t *= 13;
	}
	if(strlen(arg1) == strlen(FLAGSTRING) && !strcmp(arg1, FLAGSTRING)){
		printf("You get a flag\n");
		exit(0);
	}

	printf("=> %s\n", arg1);

	free(arg1);
	return 0;
};

void main(){
	lua_State *L;

	hap_Init(L);

	hap_Reg(L, "decrypt", chalDecrypt);
	hap_Reg(L, "encrypt", chalEncrypt);

	hap_Repl(L);
}
