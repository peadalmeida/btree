all:
		gcc main.c Functions.c -o btree

clean:
		rm -f *.dat btree
