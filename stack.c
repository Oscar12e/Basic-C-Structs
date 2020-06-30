#include <stdio.h> //Standard input-output
#include <stdlib.h>//Standard library
#include "stack.h" //Header

/** function stack_init
 * Initilize the stack with the default values
 * 
 * @param s: stack to be initilize
 **/
void stack_init(stack* s){
    s->top = NULL;
}

/** function stack_push
 * Push a value into the stack
 * 
 * @param s: stack sructure
 * @param data: data to be pushed
 */
void stack_push(stack* s, void* data){
    node* newNode = node_create(data);
    if (s->top != NULL){        //In case the top ain't null
        newNode->next = s->top; //the new node is first, the top next
    } 
    s->top = newNode; //The new nodes always takes de top place
}

/** function stack_pop 
 * Returns the top and removes it from the stack
 * 
 * @param s: stack structure
 * 
 * @returns the top value
 */
void* stack_pop(stack* s){
    node* prevTop = s->top;
    void * data = prevTop->data;
    s->top = prevTop->next;
    free(prevTop);
    return data;
}

/** function stack_peak
 * Returns the top without removing it from the stack
 * 
 * @param s: stack structure
 * 
 * @return the top value
 */
void* stack_peak(stack* s){
    return s->top->data;
}

/** function stack_isEmpty
 * Just to know if the given stack is empty
 *  
 * @param s: stack structure
 */
int stack_isEmpty(stack* s){
    return s->top == NULL;
}