#include "main.h"

void main()
{
    ///---- LINKED LIST TEST CODE ----///

    // node* linkedList = listInit();

    // listAdd(linkedList, "asdf","asdf2","asdf3");
    // listAdd(linkedList, "qwer","qwer2","qwer3");
    // listAdd(linkedList, "zxcv","zxcv2","zxcv3");

    // char* firstname = malloc(sizeof(char*));
    // char* lastname = malloc(sizeof(char*));

    // int parse = listFind(linkedList,"zxcv",firstname,lastname);

    // // printf("%s\n",firstname);
    // // printf("%s\n",lastname);

    // listPrint(linkedList);

    // free(firstname);
    // free(lastname);

    // listFree(linkedList);


    ///---- HASH TABLE TEST CODE ----///

    printf("%d\n", hash("asdf",5));

    hashEntry hashTable[5];

    hashAdd(hashTable,"asdf","penis","head");

    // listPrint(hashTable[4]);

    // printf("%s\n",hashTable[4]->first);

    // int size = sizeof(hashTable) / sizeof(hashTable[0]);
    // printf("%d",size);

    // listPrint(hashEntry[4]);
}