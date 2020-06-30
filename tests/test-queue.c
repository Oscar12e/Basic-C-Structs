#include <stdio.h>//Standard input-output
#include <stdlib.h>//Standard library
#include <unistd.h>//Standard symbolic constants and types
#include "Queue.h"

queue q1;

int main(){
    printf("Test\n");
    queue_init(&q1);
    int a = 5;
    int b = 12;
    queue_enqueue(&q1, &a);
    queue_enqueue(&q1, &b);

    int* c = queue_dequeue(&q1);
    
    printf("%d\n", *c);
    return 0;
}