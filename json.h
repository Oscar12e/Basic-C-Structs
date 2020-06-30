#ifndef JSON_H_INCLUDED
#define JSON_H_INCLUDED

typedef enum json_types {TYPE_JSON, TYPE_STRING, TYPE_INT, TYPE_ARRAY} JObj_type;
//Type would be the last to be added

//Nodes for the json structs
typedef struct JSON_Object JObject;

typedef struct JSON_Object {
    JObj_type type;
    char key[100];
    void* data;
    JObject* next;
} JObject;

void jsonObj_init(JObject* jobj, char* key, void* data, JObj_type type);

//Now the json structure per se
typedef struct json {
    JObject* start, *end;
} json;


void json_init(json* json);
int json_put(json* json, char* key, void* data, JObj_type type);
JObject* json_get(json* json, char* key);

#endif
