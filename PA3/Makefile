main : main.o LinkedList.o
	gcc main.o LinkedList.o -o main

main.o : main.c main.h
	gcc -c main.c -o main.o

LinkedList.o : LinkedList.c main.h
	gcc -c LinkedList.c -o LinkedList.o

clean :
	rm -f main main.o LinkedList.o