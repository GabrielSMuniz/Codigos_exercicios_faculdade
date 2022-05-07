#include "stdlib.h"
#include "stdio.h"

/*
Nome:..... Gabriel Muniz
Turma:.... C_11
Enunciado: Faça um programa em Linguagem C que apresente os valores de 1 a 10.
*/

int main()
{
    int i=10;

    printf("Numeros de 10 a 1: ");

    while (i >= 1)
    {
        printf("%d", i--);
        if(i!=0)
        printf(" - ");

    }
    return 0;
}