#include "main.h"

void main()
{
    Node tree = NULL;

    tree = add(tree,"b","ass","hole");
    tree = add(tree,"a","sass","shole");
    tree = add(tree,"c","cass","chole");
    tree = add(tree,"f","cass","chole");
    tree = add(tree,"s","cass","chole");
    tree = add(tree,"d","cass","chole");

    char first[257];
    char last[257];
    int IsInTree = search(tree, "b", first, last);

    printf("");

    treeFree(tree);
}