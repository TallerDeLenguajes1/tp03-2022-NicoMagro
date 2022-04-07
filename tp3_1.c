#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 5

int main()
{
    char *nombres[5], *buff;
    
    nombres[5] = (char*)malloc(20*sizeof(char));
    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese un nombre: ");
        gets(buff);
        fflush(stdin);
        nombres[i] = (char*)malloc((strlen(buff)+1)*sizeof(char));
        strcpy(nombres[i], buff);
    }
    
    for (int i = 0; i < 5; i++)
    {
        printf("\n%s", nombres[i]);
        nombres[i]++;
    }
    
    free(nombres);
    free(buff);
    return 0;
}