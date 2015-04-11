all: sl_evidence huff_evidence huffman

sl_evidence: string_list.c sl_evidence.c
	gcc -Wall -g -o sl_evidence string_list.c sl_evidence.c

huff_evidence: huff.c huff_evidence.c
	gcc -Wall -g -o huff_evidence huff.c huff_evidence.c

huffman: huff.c huffman.c
	gcc -Wall -g -o huffman huff.c huffman.c

clean:
	rm -f sl_evidence huff_evidence huffman *.stackdump *~
