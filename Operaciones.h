struct inventario{
    char nombre[50];
    float precio;
    int cantidad;
    int identificador;
};

void mostrarMenu();
void menuModificar();
void listarFrutas(struct inventario frutas[100], int num_frutas);
int anadir(struct inventario frutas[100], int num_frutas);
int eliminar(struct inventario frutas[100], int num_frutas);
void modificarPrecio(struct inventario frutas[100], int num_frutas);
void modificarCantidad(struct inventario frutas[100], int num_frutas);
int comprobarIdentificador(struct inventario frutas[100], int num_frutas, int identificador);

