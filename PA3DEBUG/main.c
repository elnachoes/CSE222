#include "main.h"

void main()
{
    hashEntry* hashTable = hashInit(5);

    FILE* fp = fopen("database.txt","r");
    if (!fp)
    {
        printf("error : file does not exist");
    }

    char chunk[1000];
    char plate[257];
    char first[100];
    char last[100];

    while(fgets(chunk, sizeof(chunk), fp) != NULL)
    {
        sscanf(chunk,"%s%s%s",plate,first,last);
        hashAdd(hashTable, plate, first, last);
    }

    //hashAdd(hashTable, "asdf", "asdf", "asdf");
    //hashAdd(hashTable, "bsdf", "asdf", "asdf");
    //hashAdd(hashTable, "csdf", "asdf", "asdf");
    //hashAdd(hashTable, "dsdf", "asdf", "asdf");
    //hashAdd(hashTable, "esdf", "asdf", "asdf");
    //hashAdd(hashTable, "fsdf", "asdf", "asdf");
    //hashAdd(hashTable, "gsdf", "asdf", "asdf");
    //hashAdd(hashTable, "hsdf", "asdf", "asdf");
    //hashAdd(hashTable, "isdf", "asdf", "asdf");
    //hashAdd(hashTable, "asdf", "asdf", "asdf");
    //hashAdd(hashTable, "asdf", "asdf", "asdf");
    //hashAdd(hashTable, "dsdf", "asdf", "asdf");
    //hashAdd(hashTable, "fsdf", "asdf", "asdf");
    //hashAdd(hashTable, "ssdf", "asdf", "asdf");
    //hashAdd(hashTable, "asdf", "asdf", "asdf");
    //hashAdd(hashTable, "sdf", "asdf", "asdf");
    //hashAdd(hashTable, "fasdf", "asdf", "asdf");
    //hashAdd(hashTable, "asdf", "asdf", "asdf");
    //hashAdd(hashTable, "asdf", "asdf", "asdf");
    //hashAdd(hashTable, "asdf", "asdf", "asdf");


    hashDump(hashTable,1);

    hashFree(hashTable);

    fgetc(stdin);
}