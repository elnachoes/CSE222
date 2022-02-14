plate : main.o BinarySearchTree.o
	gcc main.o BinarySearchTree.o -o plate

main.o : main.c main.h
	gcc -g -c main.c -o main.o

BinarySearchTree.o : BinarySearchTree.c main.h
	gcc -g -c BinarySearchTree.c -o BinarySearchTree.o

clean :
	rm -f plate main.o BinarySearchTree.o