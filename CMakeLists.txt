cmake_minimum_required(VERSION 3.12)
project(adimnPacMan C)

set(CMAKE_C_STANDARD 99)

add_executable(adimnPacMan main.c client.c client.h cJSON_Utils.h cJSON.h cJSON.c cJSON_Utils.c json_builder.c json_builder.h)