#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
#include <stdio.h>//Standard input-output
#include <stdlib.h>//Standard library
//Header part
typedef struct Node node;
typedef struct Node {
    void* data;
    node* next;
} node;

node* node_create(void*);
#endif

