#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
}Producto;


typedef struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable  // “CantidadProductosAPedir”
}Cliente;

void cargarDatos(Cliente *clientes, int cant);
void mostrarDatos(Cliente *clientes, int cant);

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

int main()
{

    int cant;
    printf("Ingrese la cantidad de clientes que se registraran: ");
    scanf("%d", &cant);

    Cliente *clientes;

    clientes = (Cliente*)malloc(sizeof(Cliente)*cant);

    cargarDatos(clientes, cant);
    mostrarDatos(clientes, cant);

    free(clientes->NombreCliente);
    free(clientes->Productos);
    free(clientes);
    return 0;
}

void cargarDatos(Cliente *clientes, int cant)
{
    char *buff;
    int tipo;
    buff = (char*)malloc(sizeof(char)*50);
    printf("=====CARGA DE DATOS=====\n\n");
    for (int i = 0; i < cant; i++)
    {
        srand((int)time(NULL));
        printf("DATOS CLIENTE %d\n", i+1);
        clientes[i].ClienteID = i;
        printf("Ingrese el nombre del cliente: ");
        scanf(" %s", buff);
        clientes[i].NombreCliente = (char*)malloc(sizeof(char)*strlen(buff+1));
        strcpy(clientes[i].NombreCliente, buff);
        clientes[i].CantidadProductosAPedir = rand()%5 + 1;
        printf("CARGA DE DATOS DE LOS PRODUCTOS\n");
        clientes[i].Productos = (Producto*)malloc(sizeof(Producto)*clientes[i].CantidadProductosAPedir);
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            printf("PRODUCTO %d\n", j+1);
            clientes[i].Productos[j].ProductoID = j;
            printf("Ingrese la cantidad de este tipo de producto: ");
            scanf("%d", &clientes[i].Productos[j].Cantidad);
            printf("Ingrese el tipo de producto que pedira: ");
            scanf("%d", &tipo);
            clientes[i].Productos[j].TipoProducto = TiposProductos[tipo];
            printf("\nIngrese el precio por unidad del producto: ");
            scanf("%f", &clientes[i].Productos[j].PrecioUnitario);
        }   
    }
    free(buff);
}

void mostrarDatos(Cliente *clientes, int cant)
{
    printf("\nMUESTRA DE DATOS\n\n");
    for (int i = 0; i < cant; i++)
    {
        printf("\nCLIENTE %i", i+1);
        printf("\nID del cliente: %d", clientes[i].ClienteID);
        printf("\nNombre del cliente: %s", clientes[i].NombreCliente);
        printf("\nCantidad de productos a pedir: %d", clientes[i].CantidadProductosAPedir);
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            printf("\n\nPRODUCTO %d", j+1);
            printf("\nCantidad de el producto: %d", clientes[i].Productos[j].Cantidad);
            printf("\nTipo de producto: %s", clientes[i].Productos[j].TipoProducto);
            printf("\nPrecio por unidad del producto: %.2f", clientes[i].Productos[j].PrecioUnitario);
        }        
    }
}