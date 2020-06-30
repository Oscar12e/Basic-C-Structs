#ifndef NODE_C_INCLUDED
#define NODE_C_INCLUDED
#include <stdio.h>//Standard input-output
#include <stdlib.h>//Standard library

#include "node.h"

//Source part
node* node_create(void* data){
    node* nodePtr = (node*) malloc(sizeof(node));
    nodePtr->data = data;
    nodePtr->next = NULL;
    nodePtr->prev = NULL;
}

#endif

