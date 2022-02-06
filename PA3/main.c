#include "main.h"

void main()
{
    hashEntry* hashTable = hashInit(16);
    hashFree(hashTable);
}