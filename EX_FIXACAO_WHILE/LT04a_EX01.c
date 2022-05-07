#include "stdlib.h"
#include "stdio.h"

/*
Nome:..... Gabriel Muniz
Turma:.... C_11
Enunciado: Faça um programa em Linguagem C que apresente os valores de 1 a 10.
*/

int main()
{
    int i=1;

    printf("Numeros de 1 a 10: ");

    while (i <= 10)
    {
        printf("%d", i++);
        if(i!=11)
        printf(" - ");

    }
    return 0;
}
