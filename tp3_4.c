#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 5

int main()
{
    char **nombres, *buff;
    int cant;

    printf("Ingrese la cantidad de nombres que desea ingresar: ");
    scanf("%d", &cant);
    fflush(stdin);
    nombres = (char**)malloc(cant*sizeof(char*));   //Reservo memoria para la cantidad de filas que tendra la matriz
    buff = (char*)malloc(sizeof(char)*100); //Reservo memoria en la variable auxiliar con la cantidad de columnas que tendra la matriz

    printf("======INGRESO DE NOMBRES=====\n\n");
    for (int i = 0; i < cant; i++)
    {
        printf("Ingrese un nombre: ");
        gets(buff);
        fflush(stdin);
        nombres[i] = (char*)malloc((strlen(buff)+1)*sizeof(char)); //Por cada fila le asigno la cantidad de columnas + 1 del espacio que tendra el nombre
        strcpy(nombres[i], buff);
    }
    
    for (int i = 0; i < 5; i++)
    {
        printf("\n%s", nombres[i]);
    }
    for (int i = 0; i < cant; i++)
    {
        free(nombres);
    } 
    free(buff);
    return 0;
}