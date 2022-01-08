#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INPUT_BUFFER 1024

#define BEGIN_CMD_LINE "</> "

//I made a macro just for this message for the sake of being a little bit cleaner
#define ERROR_MESSAGE \
"Please enter one of the following comands:\n\
i number    insert number into the list\n\
p           print the list in order\n\
s number    search for number in the list\n\
d number    delete number from the list\n\
x           exit the program\n"

//linked list node
typedef struct myNode
{
	int data;
	struct myNode* nextNode;
} myNode;

//function prototypes
myNode* init();
int add(myNode* list, int number);
int delete(myNode* list, int number);
int search(myNode* list, int number);
void print(myNode* list);
void cleanup(myNode* list);
