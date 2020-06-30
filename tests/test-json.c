#include <stdio.h>//Standard input-output
#include <stdlib.h>//Standard library
#include <unistd.h>//Standard symbolic constants and types
#include "json.h"

json jsontest1;

int main(){
    printf("Test\n");
    json_init(&jsontest1);
    char aKey[] = "Hello";
    char bKey[] = "World";
    int a = 5;
    int b = 12;

    char cKey[] = "foo";
    char charValue[] = "bar";

    
    int a1 = json_put(&jsontest1, aKey, &a, TYPE_INT);
    printf("A1-%d\n", a1);
    
    int a2 = json_put(&jsontest1, bKey, &b, TYPE_INT);
    printf("A2-%d\n", a2);
    
    int a3 = json_put(&jsontest1, cKey, charValue, TYPE_STRING);
    printf("A3-%d\n", a3);

    printf("B1\n");
    JObject* aObj = json_get(&jsontest1, aKey);
    printf("B2\n");
    JObject* bObj = json_get(&jsontest1, bKey);
    printf("B3\n");
    JObject* cObj = json_get(&jsontest1, cKey);

    printf("E1\n");
    printf("Value got from the aObj %d\n", jsontest1.start == NULL);

    printf("D1\n");
    printf("Value got from the aObj %d\n", aObj == NULL);
    printf("D2\n");
    printf("Value got from the bObj %d\n", bObj == NULL );
    printf("D3\n");
    printf("Value got from the cObj %d\n", cObj == NULL);

    printf("C1\n");
    printf("Value got from the aObj %d\n", * ((int *) aObj->data));
    printf("C2\n");
    printf("Value got from the bObj %d\n", * ((int *) bObj->data));
    printf("C3\n");
    printf("Value got from the cObj %s\n",  ((char *) cObj->data));
    return 0;
}