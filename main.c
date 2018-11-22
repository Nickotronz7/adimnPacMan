#include <stdio.h>
#include "client.h"
#include "json_builder.h"


char* itoa(int value, char* result, int base) {
    // check that the base if valid
    if (base < 2 || base > 36) { *result = '\0'; return result; }

    char* ptr = result, *ptr1 = result, tmp_char;
    int tmp_value;

    do {
        tmp_value = value;
        value /= base;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
    } while ( value );

    // Apply negative sign
    if (tmp_value < 0) *ptr++ = '-';
    *ptr-- = '\0';
    while(ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr--= *ptr1;
        *ptr1++ = tmp_char;
    }
    return result;
}

char* cleanner(char* resp) {
    int respuestaLen = 59;
    int x = 0;
    int espChars = 0;
    char* cResp = (char*)malloc(respuestaLen+1 * sizeof(char));

    while (*(resp+x) != '\0') {
        if (!((*(resp+x) == '\n') || (*(resp+x) == '\t') || (*(resp+x) == ' '))) {
            *(cResp+espChars) = *(resp+x);
            espChars += 1;
        }
        x+=1;
    }
    return cResp;
}

int main() {

    printf("Que desea hacer?\n");
    printf("1. Crear fantasma\n");
    printf("2. Crear pastilla\n");
    printf("3. Crear fruta\n");
    printf("4. Modificar velocidad de los fantasmas\n\n");

    int option;
    printf("Opcion: ");
    scanf("%d",&option);
    int row;
    int col;
    char* buffer = (char*)malloc(sizeof(char));
    char* respuesta = NULL;

    switch (option) {
        case 1:
            printf("Ingrese la fila en la que quiere crear el fantasma\n");
            printf("Fila: ");
            scanf("%d",&row);
            printf("Ingrese la columna en la que desea crear el fantasma\n");
            printf("Columna: ");
            scanf("%d",&col);
            itoa(option, buffer, 10);
            respuesta = cJSON_Print(crearEntidad(buffer, row, col));
            break;

        case 2:
            printf("Ingrese la fila en la que quiere crear el la pastilla\n");
            printf("Fila: ");
            scanf("%d",&row);
            printf("Ingrese la columna en la que desea crear el pastilla\n");
            printf("Columna: ");
            scanf("%d",&col);
            itoa(option, buffer, 10);
            respuesta = cJSON_Print(crearEntidad(buffer, row, col));
            break;

        case 3:
            printf("Ingrese la fila en la que quiere crear el la fruta\n");
            printf("Fila: ");
            scanf("%d",&row);
            printf("Ingrese la columna en la que desea crear el fruta\n");
            printf("Columna: ");
            scanf("%d",&col);
            itoa(option, buffer, 10);
            respuesta = cJSON_Print(crearEntidad(buffer, row, col));
            break;

        case 4:
            printf("Ingrese la nueva velocidad de los fantasmaas\n");
            int velocidad;
            printf("Nueva velocidad: ");
            scanf("%d",&velocidad);
            itoa(option, buffer, 10);
            respuesta = cJSON_Print(fantasmaSpeed(buffer, velocidad));
            break;


        default:
            printf("Ingrese una opcion valida porfavor\n");
            break;
    }

    client(cleanner(respuesta), 8080,"127.0.0.1");
    main();

    return 0;
}