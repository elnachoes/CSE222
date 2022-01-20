main : functions.o main.o
	gcc functions.o main.o -o main

debug : functions.c main.c
	gcc -g functions.c main.c -o debug

main.o : main.c main.h
	gcc -c main.c

functions.o : functions.c main.h
	gcc -c functions.c

clean :
	rm functions.o main.o main debug