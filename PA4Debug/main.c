#include "main.h"

void main()
{
    Node tree = NULL;


    // a b c d e f g h i
    //tree = add(tree,"c","asdf","asdf");
    //tree = add(tree,"b","asdf","asdf");
    //tree = add(tree,"d","asdf","asdf");
    //tree = add(tree,"e","asdf","asdf");
    //tree = add(tree,"a","asdf","asdf");
    //tree = add(tree,"f","asdf","asdf");
    //tree = add(tree,"i","asdf","asdf");
    //tree = add(tree,"h","asdf","asdf");
    //tree = add(tree,"g","asdf","asdf");

    tree = LoadDatabase("database.txt");

    height(tree);
    printf("\r\n");
    LNR(tree);
    printf("\r\n");
    NLR(tree);
    printf("\r\n");
    LRN(tree);
    printf("\r\n");


    treeFree(tree);
}