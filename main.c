#include <stdio.h>
#include <stdlib.h>
#include "Operaciones.h"
#include "Guardado.h"
#include "Lecturas.h"

int main()
{
    int opcionMenu = 0;
    int opcionModificar =0;
    int num_frutas=0;

    struct inventario frutas[100];

    num_frutas=cargarFrutas(frutas);

    printf("\t\t\t\t******* BIENVENIDO AL INVENTARIO DE SARITA *******\n");

    do{

    mostrarMenu();
    opcionMenu = leerEnteroPositivo("Introduzca la opcion que desea realizar: \n");

        switch(opcionMenu){

            case 1:{

                int añadido = anadir(frutas,num_frutas);
                if (añadido == 1){
                num_frutas++;
                }

            }break;

            case 2:{

                int eliminado = eliminar(frutas,num_frutas);
                if(eliminado == 1){
                num_frutas--;
                }

            }break;

            case 3:{
                
                do{
                        
                    menuModificar();
                    opcionModificar=leerEnteroPositivo("Introduzca la opcion que desea realizar: \n");
                    
                    switch (opcionModificar){

                        case 1:{

                            modificarPrecio(frutas, num_frutas);

                        }break;

                        case 2:{

                            modificarCantidad(frutas, num_frutas);
                                
                        }break;

                        case 3:{

                            printf("Regresando al menu principal...........\n");
                            printf("\n");

                        }break;

                        default:{

                            printf("\n");
                            printf("Opción invalida\n");
                            printf("\n");

                        }break;
                    }
                }while(opcionModificar != 3);

            }break;

            case 4:{

                listarFrutas(frutas,num_frutas);

            }break;

            case 5:{
               
                guardarFrutas(frutas, num_frutas);
                printf("\n");
                printf("TODOS SUS DATOS FUERON CORRECTAMENTE GUARDADOS\n");
                printf("\n");

            }break;

            case 6:{
               
                printf("\n");
                printf("USTED HA SALIDO DEL PROGRAMA\n");
                printf("\n");

            }break;

            default:{

                printf("\n");
                printf("Opcion invalida\n");
                printf("\n");

            }break;

        }

    }while(opcionMenu != 6);
    guardarFrutas(frutas, num_frutas);
}
