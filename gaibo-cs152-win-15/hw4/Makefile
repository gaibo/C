all: evidence concat dec2bin bin2dec

evidence: hw4.c hw4_evidence.c
	gcc -Wall -g -o evidence hw4.c hw4_evidence.c -lm

concat: hw4.c concat.c
	gcc -Wall -g -o concat hw4.c concat.c -lm

dec2bin: hw4.c dec2bin.c
	gcc -Wall -g -o dec2bin hw4.c dec2bin.c -lm

bin2dec: hw4.c bin2dec.c
	gcc -Wall -g -o bin2dec hw4.c bin2dec.c -lm

clean:
	rm -f evidence concat dec2bin bin2dec *.stackdump *~
