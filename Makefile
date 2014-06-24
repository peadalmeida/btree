all:
		gcc btree.h main.c Functions.c -o btree

mac:
		gcc main.c Functions.c -o btree

clean:
		rm -f *.dat btree
