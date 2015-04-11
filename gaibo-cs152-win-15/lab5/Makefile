# Makefile for CS152 lab5 Winter 2015

.PHONY : clean

htbl: sll.h sll.c htbl.h htbl.c main.c
	gcc -g -Wall -o htbl sll.c htbl.c main.c -lm

clean:
	rm -rf htbl *.dSYM
