//Author : Corbin Martin
//Program Description : this is a program that allows you to store numbers in a linked list structure in a stack mode or a que mode
//where you an print out the stack or queue, remove items from the stack or queue, and switch modes from stack mode and queue mode


#include "main.h"

void main()
{
    //print the welcome message and the help message to welcome the user and show the program works
    printf(WELCOME_MESSAGE);
    printf(HELP_MESSAGE);

    //these are the stack and queue variables
    myNode* stack = stackInit();
    myNode* queue= queueInit();

    //this variable stores the state of the program on weather it is in stack or queue mode
    int state = STACK_STATE;

    //these are the variables for getting user input
    char userInputBuffer[INPUT_BUFFER];
    char invalidInputBuffer[INPUT_BUFFER];
    int userInputNumber;
    int parseResult;

    //main terminal loop
    while(true)
    {
        //get the user input
        printf("> ");
        fgets(userInputBuffer, INPUT_BUFFER, stdin);

        //this switches the mode to stack mode and prints the stack
        if(userInputBuffer[0] == 's')
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

        //this switches the mode to queue mode and prints the queue
        else if(userInputBuffer[0] == 'q')
        {
            state = QUEUE_STATE;

            printf("Switching to queue mode\n");

            queuePrint(queue);

            printf("\n");
        }

        //this breaks the loop and exits the program
        else if(userInputBuffer[0] == 'x')
        {
            break;
        }

        //this either removes the head of the queue or pops the top of the stack depeding on the mode of the program
        else if(userInputBuffer[0] == '\n')
        {
            if(state == STACK_STATE)
            {
                if(stackIsEmpty(stack))
                {
                    printf("Error: Stack is empty\n");
                }
                else
                {
                    printf("%d\n",stackPop(stack));
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
                    printf("%d\n",queueRemove(queue));
                }
            }
        }

        //this checks weather the user put in a number, if they did store it either in the que or the stack depending on the mode of the prgram
        else if(userInputBuffer[0] >= '0' && userInputBuffer[0] <= '9')
        {
            parseResult = sscanf(userInputBuffer, "%d%s",&userInputNumber,invalidInputBuffer);

            if(parseResult == 1)
            {
                if(state == STACK_STATE)
                {
                    stackPush(stack,userInputNumber);
                }
                else
                {
                    queueAdd(queue,userInputNumber);
                }
            }
            else
            {
                printf(HELP_MESSAGE);
            }
        }

        //if the user put in nonsense or needs help this will print the help message
        else
        {
            printf(HELP_MESSAGE);
        }
    }

    //freeing the stack and que variables
    cleanup(queue);
    cleanup(stack);
}