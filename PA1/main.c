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

    if (search(myList, 190))
    {
        printf("is in list\n");
    }



    return;
}
