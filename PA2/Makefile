##main build and main object files
main : functions.o main.o
	gcc functions.o main.o -o main

main.o : main.c main.h
	gcc -c main.c -o main.o

functions.o : functions.c main.h
	gcc -c functions.c -o functions.o



##debug build and debug object files
debug : D_functions.o D_main.o
	gcc D_functions.o D_main.o -o debug

D_main.o : main.c main.h
	gcc -g -c main.c -o D_main.o

D_functions.o : functions.c main.h
	gcc -g -c functions.c -o D_functions.o



##cleans up all the object and executible files
clean :
	rm -f functions.o main.o D_functions.o D_main.o main debug