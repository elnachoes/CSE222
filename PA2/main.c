#include "main.h"

void main()
{
    myNode* stack = stackInit();

    // printf("%d\n",stackIsEmpty(stack));

    stackPush(stack,5);
    stackPush(stack,6);
    stackPush(stack,7);
    stackPush(stack,8);
    stackPush(stack,9);
    stackPush(stack,10);

    stackPrint(stack);

    stackPop(stack);

    printf("\n");

    stackPrint(stack);
    // printf("%d\n",stackIsEmpty(stack));

    cleanup(stack);

    return;
}