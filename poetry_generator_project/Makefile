all: generator

generator: sll.c htbl.c generator.c
	gcc -Wall -g -o generator sll.c htbl.c generator.c

clean:
	rm -f *.stackdump generator
