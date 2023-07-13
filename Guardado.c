#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Operaciones.h"
#include "Lecturas.h"

int cargarFrutas(struct inventario frutas[100]){

    int n_frutas=0;

    FILE *f;
    f = fopen("Inventario.txt","r");
    char cadena[255];
    char delimitador[] = ";";

    while (feof(f) == 0){

        struct inventario frutas1;
        fgets(cadena, 255, f);
        char *token = strtok(cadena, delimitador);

        if(token != NULL){
            int campo = 1;
            while (token != NULL){
                if (campo == 1){
                    strcpy(frutas1.nombre, token);
                }
                else if(campo == 2){
                    frutas1.identificador = atoi(token);
                }
                else if(campo == 3){
                    frutas1.precio = atof(token);
                }
                else if(campo == 4){
                    frutas1.cantidad = atoi(token);
                }
                campo++;
                token = strtok(NULL, delimitador);
            }
        }
        frutas[n_frutas] = frutas1;
        n_frutas++;

    }
    fclose(f);
    return n_frutas;
}

void guardarFrutas(struct inventario frutas[100], int num_frutas){
    FILE *f;
    f = fopen("Inventario.txt","w");

    for(int i=0; i<num_frutas-1; i++){
        fprintf(f, "%s;%d;%.2f;%d\n", frutas[i].nombre,frutas[i].identificador, frutas[i].precio, frutas[i].cantidad);
    }
    fprintf(f, "%s;%d;%.2f;%d", frutas[num_frutas-1].nombre,frutas[num_frutas-1].identificador, frutas[num_frutas-1].precio, frutas[num_frutas-1].cantidad);

    fclose(f);
}

