//Author : Corbin Martin
//TODO : ^^^^^^ fill the rest of this in later ^^^^^^


#include "main.h"

void main()
{
    myNode* myList = init();

    add(myList, 98);
    add(myList, 2);
    add(myList, 7);
    add(myList, 7);
    add(myList, 190);
    add(myList, 5);

    print(myList);

    if (!delete(myList,8))
    {
        printf("8 does not exist in the list\n");
    }


    return;
}
