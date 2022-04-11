#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

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
    Producto *Productos //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
}Cliente;


int main()
{
    int cantidad;
    Cliente *cliente;

    cliente = (Cliente*)malloc(cantidad*sizeof(Cliente));
    cliente->NombreCliente = (char*)malloc(20*sizeof(char));

    int tipo;

    srand(time(NULL));


    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cantidad);

    printf("INGRESE LOS DATOS DE LOS CLIENTES\n\n");
    for (int i = 0; i < cantidad; i++)
    {
        printf("Datos del cliente %d", i+1);
        printf("\nID del cliente: ");
        scanf("%d",&cliente->ClienteID);
        printf("Nombre del cliente: ");
        gets(cliente->NombreCliente);
        fflush(stdin);
        cliente->CantidadProductosAPedir = rand() % 10;
        for (int j = 0; j < cliente->CantidadProductosAPedir; j++)
        {
            
        }  
        
    }
    
}