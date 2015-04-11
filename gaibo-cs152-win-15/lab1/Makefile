# Gaibo Zhang, gaibo
# CS152, Winter 2015
# Lab 1

all: evidence_expt raise

evidence_expt: expt.c evidence_expt.c
	gcc -Wall -o evidence_expt expt.c evidence_expt.c

raise: expt.c raise.c
	gcc -Wall -o raise expt.c raise.c

clean:
	rm evidence_expt raise
