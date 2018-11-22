//
// Created by nicko on 21/11/18.
//

#ifndef ADIMNPACMAN_CLIENT_H
#define ADIMNPACMAN_CLIENT_H

#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <malloc.h>

void client(char* msg, int port, char* host_name);



#endif //ADIMNPACMAN_CLIENT_H
