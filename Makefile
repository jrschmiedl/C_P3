CC = gcc
CFLAGS = -Wall -std=c99 -g -c

all: encrypt decrypt

encrypt: encrypt.o operations.o text.o
	gcc encrypt.o operations.o text.o -o encrypt

encrypt.o: encrypt.c text.h operations.h
	gcc -Wall -std=c99 -g -c encrypt.c operations.c text.c

decrypt: decrypt.o operations.o text.o
	gcc decrypt.o operations.o text.o -o decrypt

decrypt.o: decrypt.c text.h operations.h
	gcc -Wall -std=c99 -g -c decrypt.c operations.c text.c

clean:
	rm -f *.o
	rm -f decrypt
	rm -f encrypt
	rm -f text
	rm -f operations
	rm -f output.*