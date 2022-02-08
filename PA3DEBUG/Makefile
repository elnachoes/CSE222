main : main.o LinkedList.o HashTable.o
	gcc main.o LinkedList.o HashTable.o -o main

main.o : main.c main.h
	gcc -g -c main.c -o main.o

LinkedList.o : LinkedList.c main.h
	gcc -g -c LinkedList.c -o LinkedList.o

HashTable.o : HashTable.c main.h
	gcc -g -c HashTable.c -o HashTable.o

clean :
	rm -f main main.o LinkedList.o HashTable.o