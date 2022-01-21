#include "main.h"

void main()
{
    myNode* stack = stackInit();
    myNode* queue= queueInit();

    int state = STACK_STATE;

    char userInputBuffer[INPUT_BUFFER];
    char invalidInputBuffer[INPUT_BUFFER];
    char userInputOperation;
    int userInputNumber;
    int parseResult;

    while(true)
    {
        printf("> ");
        fgets(userInputBuffer, INPUT_BUFFER, stdin);
        parseResult = sscanf(userInputBuffer, "%d%s",&userInputNumber,invalidInputBuffer);

        if (parseResult == 0)
        {
            parseResult = sscanf(userInputBuffer, "%c%s",&userInputOperation,invalidInputBuffer);

            if(userInputOperation == 's')
            {
                state = STACK_STATE;

                printf("Switching to stack mode\n");

                if(!stackIsEmpty(stack))
                {
                    stackPrint(stack);
                }
                else
                {
                    printf("Stack is empty\n");
                }
            }
            else if(userInputOperation == 'q')
            {
                state = QUEUE_STATE;

                printf("Switching to queue mode\n");

                queuePrint(queue);
            }
            else if(userInputOperation == 'x')
            {
                break;
            }
            else if(userInputOperation == '\n')
            {
                if(state == STACK_STATE)
                {
                    if(stackIsEmpty(stack))
                    {
                        printf("Error: Stack is empty\n");
                    }
                    else
                    {
                        stackPop(stack);
                    }
                }
                else
                {
                    if(queueIsEmpty(queue))
                    {
                        printf("Error: Queue is empty\n");
                    }
                    else
                    {
                        queueRemove(queue);
                    }
                }
            }
            else
            {
                printf(HELP_MESSAGE);
            }
        }
        else
        {
            printf("parse result %d", parseResult);

            if(state = STACK_STATE)
            {
                stackPush(stack,userInputNumber);
            }
            else
            {
                queueAdd(queue,userInputNumber);
            }
        }
    }

    cleanup(queue);
    cleanup(stack);
}