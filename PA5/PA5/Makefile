knapsack : main.o Inventory.o:
	gcc -o knapsack main.o Inventory.o

main.o : main.c main.h
	gcc -g -c main.c

Inventory.o : Inventory.c main.h
	gcc -g -c Inventory.c

clean :
	rm -f knapsack main.o Inventory.o
