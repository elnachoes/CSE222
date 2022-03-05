knapsack : main.o KnapsackFunctions.o
	gcc -o knapsack main.o KnapsackFunctions.o

main.o : main.c main.h
	gcc -g -c main.c

KnapsackFunctions.o : KnapsackFunctions.c main.h
	gcc -g -c KnapsackFunctions.c

clean :
	rm -f knapsack main.o KnapsackFunctions.o