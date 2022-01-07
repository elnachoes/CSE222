#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct myNode
{
	int data;
	struct myNode* nextNode;
} myNode;

myNode* init();
int add(myNode* list, int number);
int delete(myNode* list, int number);
void print(myNode* list);
void cleanup(myNode* list);