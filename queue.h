#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include "structs-node.h"

typedef struct Queue {
    node *front, *back;
} queue;

void queue_init(queue*);
void queue_enqueue(queue*, void*);
void* queue_dequeue(queue*);
int queue_isEmpty(queue*);

#endif