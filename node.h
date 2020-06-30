#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

typedef struct Nodes node;

typedef struct Nodes {
    void* data;
    node* prev, *next;
} node;

node* node_create(void*);

#endif

