#include <stdio.h>      //Standard input-output
#include <stdlib.h>     //Standard library
#include "json.h"       //header for the json header 
#include <string.h>
/*
typedef struct JSON_Object {
    JObj_type type;
    char key[100];
    void* data;
    JObject* next;
} JObject;
*/
void jsonObj_init(JObject* jobj, char* key, void* data, JObj_type type){
    strcpy(jobj->key, key);
    jobj->data = data;
    jobj->type = type;
}

/*
//Now the json structure per se
typedef struct Json {
    JObject* start, *end;
} Json;*/
void json_init(json* json){
    json->start = NULL; //The start set as NULL to avoid issues
    json->end = NULL;   //Same with the end
}

/** function json_put
 * @param json struct
 * @param key char pointer to identify each obj
 * @param data pointer to data 
 * @param type type for printing reasons 
 */
//Overwrites and creates
int json_put(json* json, char* key, void* data, JObj_type type){
    JObject* jobj2 = json_get(json, key);
    //If the obj is already here, overwrite
    if (jobj2 != NULL){ 
        jobj2->data = data;
        jobj2->type = type;
        return 2;
    }
    JObject* jobj = malloc(sizeof(JObject));;
    printf("Z1-%d\n", jobj == NULL);
    //Else allocate a new json object and set jobj as it
    jsonObj_init(jobj, key, data, type);
    printf("Z2-%d\n", jobj == NULL);
    //Then check if the start is null to set it
    if (json->start == NULL) {
        printf("Z3-%d\n", json->start == NULL);
        json->start = jobj;
        json->end = json->start;
        printf("Z4-%d\n", json->start == NULL);
        return 1;
    }
    //If is a totally new obj
    JObject* prevEnd = json->end;   //Record to the end
    prevEnd->next = jobj;           //Set the new obj as next to the end
    json->end = jobj;               //Set the end as the obj
    return 0;
}

/** function json_get
 * @param json: json struct
 * @param key: the key to indentify the obj
 * 
 * This function returns a pointer to the node so it can be modified or
 * simply to access the data hold on it
 */
JObject* json_get(json* json, char* key){
    //Typical temporal to iterate the list
    JObject* temp = json->start;
    //And iterate till the end
    while(temp != NULL){
        //Just compare the keys and return if found
        if (strcmp(temp->key, key) == 0) return temp;
        temp = temp->next;
    }

    return NULL;
}