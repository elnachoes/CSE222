#include "main.h"

void main()
{
    myNode* stack = stackInit();
    myNode* queue= queueInit();


    queueAdd(queue, 5);

    // printf("%d\n",queueRemove(queue));
    // printf("%d\n",queueRemove(queue));

    // printf("%d\n", stackIsEmpty(stack));

    // queuePrint(queue);

    // queueRemove(queue);

    // queuePrint(queue);

    cleanup(queue);
    cleanup(stack);
}