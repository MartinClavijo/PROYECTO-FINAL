#include <stdio.h>
#include <stdlib.h>
#include "Operaciones.h"
#include "Lecturas.h"

int comprobarIdentificador(struct inventario frutas[100], int num_frutas, int identificador);

void mostrarMenu(){
   
    printf("\n");
    printf("1- Añadir producto\n");
    printf("2- Eliminar producto\n");
    printf("3- Modificar Producto\n");
    printf("4- Listar productos\n");
    printf("5- Guardar\n");
    printf("6- Salir");
    printf("\n");
}

void menuModificar(){

    printf("\n");
    printf("1-Modificar precio del producto\n");
    printf("2-Modificar cantidad del producto\n");
    printf("3-Salir\n");
    printf("\n");
}

void listarFrutas(struct inventario frutas[100], int num_frutas){
    
    printf("Listando datos del inventario:\n");
    printf("\n");

    for (int i=0; i<num_frutas; i++){
        printf("Identificador: %d\n", frutas[i].identificador);
        printf("Nombre: %s\n", frutas[i].nombre);
        printf("Precio: %.2f\n", frutas[i].precio);
        printf("Cantidad: %d\n", frutas[i].cantidad);
        printf("\n");
    }

}

int anadir(struct inventario frutas[100], int num_frutas){

    int creado = 0;
    struct inventario datos;

    fflush(stdin);
    printf("\n");
    printf("Introduce nombre del producto\n");
    gets(datos.nombre);
    printf("\n");
    datos.identificador=leerEnteroPositivo("Introduce identificador del producto\n");
    printf("\n");
    datos.precio=leerFlotantePositivo("Introduce precio del producto\n");
    printf("\n");
    datos.cantidad=leerEnteroPositivo("Introduce cantidad del producto\n");
    printf("\n");

    int existe = comprobarIdentificador(frutas, num_frutas, datos.identificador);

    if (num_frutas < 100){
        if(existe == 0){
            frutas[num_frutas] = datos;
            creado = 1;
             printf("Producto ingresado\n");
        }
        else{
            printf("No se puede añadir producto. Identificador duplicado\n");
        }
    }
    else{
        printf("No se puede añadir producto. Cupo alcanzado\n");
    }

    return creado;

}

int eliminar(struct inventario frutas[100], int num_frutas){
    int eliminado = 0;
    int identificador, indice;

    identificador=leerEnteroPositivo("Introduce el identificador del producto a eliminar\n");

    int existe = comprobarIdentificador(frutas, num_frutas, identificador);

    if(existe == 1){
        for(int i = 0; i<num_frutas; i++){
            if(frutas[i].identificador == identificador){
                indice = i;
            }
        }
        for(int j = indice; j<num_frutas-1; j++){
            frutas[j] = frutas[j+1];
            struct inventario aux;
            frutas[j+1] = aux;
        }
        eliminado = 1;
        printf("\n");
        printf("Producto eliminado\n");
    }
    else{
        
        printf("No se puede eliminar producto. Identificador no existe\n");
    }

    return eliminado;
}

void modificarPrecio(struct inventario frutas[100], int num_frutas){
    
    int identificador;

    identificador=leerEnteroPositivo("Introduce identificador del producto a modificar\n");
    int existe = comprobarIdentificador(frutas, num_frutas, identificador);

    if(existe == 1){

        float nuevo_precio;
        printf("\n");
        nuevo_precio=leerFlotantePositivo("Introduce el nuevo precio del producto\n");

        for(int i=0; i<num_frutas; i++){
            if(frutas[i].identificador == identificador){
                frutas[i].precio = nuevo_precio;
                printf("\n");
                printf("Precio actualizado\n");
                 printf("\n");
            }
        }
    }
    else{

        printf("\n");
        printf("No se puede modificar el precio del producto. Identificador no existe\n");
        printf("\n");
    }


}

void modificarCantidad(struct inventario frutas[100], int num_frutas){
    
    int identificador;

    identificador=leerEnteroPositivo("Introduce identificador del producto a modificar\n");
    int existe = comprobarIdentificador(frutas, num_frutas, identificador);

    if(existe == 1){
        
        int nueva_cantidad;
        printf("\n");
        nueva_cantidad=leerEnteroPositivo("Introduce la nueva cantidad del producto\n");

        for(int i=0; i<num_frutas; i++){
            if(frutas[i].identificador == identificador){
                frutas[i].cantidad = nueva_cantidad;
                printf("\n");
                printf("Cantidad actualizada\n");
                printf("\n");
            }
        }
    }
    else{
        
        printf("\n");
        printf("No se pueden modificar las horas del empleado. ID no existe\n");
        printf("\n");
    }

}

int comprobarIdentificador(struct inventario frutas[100], int num_frutas, int identificador){

    int resultado = 0;

    for (int i = 0; i<num_frutas; i++){
        if (frutas[i].identificador == identificador){
            resultado = 1;
        }
    }
    return resultado;
}

