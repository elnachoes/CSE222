#include "main.h"

void main()
{
    myNode* stack = stackInit();

    stackPush(stack,5);
    stackPush(stack,10);

    printf("%d",stack->nextNode->data);
    printf("%d",stack->nextNode->nextNode->data);

    return;
}