#include "main.h"

void main()
{
    Node tree = NULL;
    // add(tree,"bunghole","ass","hole");
    // add(tree,"bunghole","ass","hole");
    tree = add(tree,"bunghole","ass","hole");
    tree = add(tree,"sbunghole","sass","shole");

    // printf("%s",tree->first);

    treeFree(tree);
}