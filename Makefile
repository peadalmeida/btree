all:
	gcc btree.h main.c Functions.c -o btree

clean:
	rm -r btree index.dat data.dat
