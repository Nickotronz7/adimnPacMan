//
// Created by nicko on 22/11/18.
//

#ifndef ADIMNPACMAN_JSON_BUILDER_H
#define ADIMNPACMAN_JSON_BUILDER_H

#include "cJSON.h"

cJSON* crearEntidad(char* code, int row, int col);
cJSON* fantasmaSpeed(char* code, int speed);

#endif //ADIMNPACMAN_JSON_BUILDER_H
