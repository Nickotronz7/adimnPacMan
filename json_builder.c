//
// Created by nicko on 22/11/18.
//

#include "json_builder.h"

cJSON* crearEntidad(char* code, int row, int col) {
    cJSON* root = cJSON_CreateObject();
    cJSON* jCode = cJSON_CreateString(code);
    cJSON* jRow = cJSON_CreateNumber(row);
    cJSON* jCol = cJSON_CreateNumber(col);

    cJSON_AddItemToObject(root, "message_type", jCode);
    cJSON_AddItemToObject(root, "row", jRow);
    cJSON_AddItemToObject(root, "col", jCol);

    return root;
}

cJSON* fantasmaSpeed(char* code, int speed) {
    cJSON* root = cJSON_CreateObject();
    cJSON* jCode = cJSON_CreateString(code);
    cJSON* jSpeed = cJSON_CreateNumber(speed);

    cJSON_AddItemToObject(root, "message_type", jCode);
    cJSON_AddItemToObject(root, "speed", jSpeed);

    return root;
}