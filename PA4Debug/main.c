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

    NLR(tree);

    printf("");

    treeFree(tree);
}