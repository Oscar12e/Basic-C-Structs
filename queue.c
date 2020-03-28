#include <stdio.h> //Standard input-output
#include <stdlib.h>//Standard library
#include "Queue.h" //Header
#include "structs-node.c"

/* qeue_init
Initilize the structs with the desire values
--------------------------------------------
Q: Queue structure
*/
void queue_init(queue* q){
    q->back = NULL;
    q->front = NULL;
}

/*queue_enqueue
Add a value into the queue
--------------------------
q: Queue structure
data: Value to be stored
*/
void queue_enqueue(queue* q, void* data){
    node* newNode = node_create(data);
    if (q->front == NULL){ //In case the queue is empty
        q->front = newNode;
        q->back = newNode;
    } else { //In any other case
        node* prevBack = q->back;
        prevBack->next = newNode;
        q->back = newNode;
    }
}

/*queue_dequeue
Takes the first vale stored into the queue
--------------------------
q: Queue structure

returns: the value in front
*/
void* queue_dequeue(queue* q){
    node* prevFront = q->front; //Previous front
    void* data = prevFront->data;
    q->front = prevFront->next;
    free(prevFront);

    return data;
}
