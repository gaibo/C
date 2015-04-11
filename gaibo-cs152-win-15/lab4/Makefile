# Makefile for CS152 2015 Lab 4

.PHONY: clean

adrbook: adrbook.h bst.c vcard.c main.c
	gcc -g -o adrbook -Wall vcard.c bst.c main.c -lm

# type 'make clean' to remove the executable and debug information
clean:
	rm -rf adrbook *.dSYM

