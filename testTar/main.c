//Author : Corbin Martin
//Program Description : this is a program that allows you to store numbers in a linked list as well as print out the list, remove
//items, and search items

#include "main.h"

//this is the main program that allows you to add, delete, search, and print items from a linked list
void main()
{
    myNode* myList = init();

    char userInputBuffer[INPUT_BUFFER];
    char invalidInputBuffer[INPUT_BUFFER];
    char userInputOperation;
    int userInputNumber;
    int parseResult;

    while (true)
    {
        //
        printf("> ");
        fgets(userInputBuffer, INPUT_BUFFER, stdin);
        parseResult = sscanf(userInputBuffer, "%c%d%s",&userInputOperation, &userInputNumber,invalidInputBuffer);

        // if there is only 1 argument for the opperation it is either printing the list or exiting the program
        if (parseResult == 1)
        {
            if (userInputOperation == 'p')
            {
                print(myList);
            }
            
            else if (userInputOperation == 'x')
            {
                break;
            }

            else
            {
                //error message defined in main.h because it is quite large
                printf(ERROR_MESSAGE_UDEFINED);
            }
        }

        if (parseResult == 2)
        {
            if (userInputOperation == 'i')
            {
                //this adds an item to the list if it IS NOT already in the list by searching the list
                if (!search(myList,userInputNumber))
                {
                    int result = add(myList, userInputNumber);

                    //if add returns 0 it cannot allocate enough memory on the heap so throw this error
                    if (result = 0)
                    {
                        printf("OUT OF MEMORY\n");
                    }
                }
                else
                {
                    printf("NODE ALREADY IN LIST\n");
                }
            }

            else if (userInputOperation == 's')
            {
                if (search(myList,userInputNumber))
                {
                    printf("FOUND\n");
                }
                else
                {
                    printf("NOT FOUND\n");
                }
            }

            else if (userInputOperation == 'd')
            {
                if (search(myList,userInputNumber))
                {
                    delete(myList, userInputNumber);
                    printf("SUCCESS\n");
                }
                else
                {
                    printf("NODE NOT FOUND\n");
                }
            }

            else
            {
                //error message defined in main.h because it is quite large
                printf(ERROR_MESSAGE_UDEFINED);
            }
        }

        if (parseResult >= 3)
        {
            //error message defined in main.h because it is quite large
            printf(ERROR_MESSAGE_UDEFINED);
        }
    }

    cleanup(myList);
    return;
}
