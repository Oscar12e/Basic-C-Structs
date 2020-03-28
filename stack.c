#include <stdio.h> //Standard input-output
#include <stdlib.h>//Standard library
#include "stack.h" //Header

/*stack_init
Initilize the stack with the default values
-------------------------------------------

s: stack to be initilize
*/
void stack_init(stack* s){
    s->top = NULL;
}

/** stack_push
 * Push a value into the stack
 * ---------------------------
 * 
 * s: stack sructure
 * data: data to be pushed
 */
void stack_push(stack* s, void* data){
    node* newNode = node_create(data);
    if (s->top != NULL){ //I case the top ain't null
        newNode->next = s->top;
    } 
    s->top = newNode; //The new nodes always takes de top place
}

/** stack_pop 
 * Returns the top and removes it from the stack
 * ---------------------------------------------
 * 
 * s: stack structure
 * 
 * Returns the top value
 */
void* stack_pop(stack* s){
    node* prevTop = s->top;
    void * data = prevTop->data;
    s->top = prevTop->next;
    free(prevTop);
    return data;
}

/** stack_peak
 * Returns the top without removing it from the stack
 * ---------------------------------------------
 * 
 * s: stack structure
 * 
 * Returns the top value
 */
void* stack_peak(stack* s){
    return s->top->data;
}

/** stack_isEmpty
 *  Just to know if the given stack is empty
 */
int stack_isEmpty(stack* s){
    return s->top == NULL;
}