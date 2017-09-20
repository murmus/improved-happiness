CC=gcc

LUALIB=-I.. -I../lua-5.3.4/src -L../lua-5.3.4/src
OUTPUT=-o example1

example1: example1.c
	$(CC) $(LUALIB) example1.c -llua -lm -ldl $(OUTPUT)
