//
// Created by nicko on 21/11/18.
//

#include "client.h"

void client(char* msg, int port, char* host_name) {

    struct sockaddr_in my_addr;

    int bytecount;
    int buffer_len = 1024;
    char buffer[buffer_len];
    memset(buffer, '\0', buffer_len);

    int hsock;
    int* p_int;

    hsock = socket(AF_INET, SOCK_STREAM, 0);
    if (hsock == -1) {
        printf("Error al inicializar el socket %d\n", errno);
        goto FIN;
    }

    p_int = (int*)malloc(sizeof(int));
    *p_int = 1;

    if ((setsockopt(hsock, SOL_SOCKET, SO_REUSEADDR, (char*)p_int, sizeof(int)) == -1) ||
            (setsockopt(hsock, SOL_SOCKET, SO_KEEPALIVE, (char*)p_int, sizeof(int)) == -1)) {
        printf("Error al establecer las configuraciones %d\n", errno);
        free(p_int);
        goto FIN;
    }

    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(port);

    memset(&(my_addr.sin_zero), 0, 8);
    my_addr.sin_addr.s_addr = inet_addr(host_name);

    if (connect(hsock, (struct sockaddr*)&my_addr, sizeof(my_addr)) == -1) {
        fprintf(stderr, "Error al conectar al socket %d\n", errno);
        goto FIN;
    }

    strcat(msg,"\0");

    if ((bytecount=send(hsock, msg, strlen(msg),0))== -1) {
        fprintf(stderr, "Error al enviar el mensaje %d\n", errno);
        goto FIN;
    }

    printf("Bytes enviados %d\n", bytecount);

    if((bytecount = recv(hsock, buffer, buffer_len, 0))== -1){
        fprintf(stderr, "Error receiving data %d\n", errno);
        goto FIN;
    }
    printf("Recieved bytes %d\nReceived string \"%s\"\n", bytecount, buffer);
    close(hsock);
    FIN:;
}