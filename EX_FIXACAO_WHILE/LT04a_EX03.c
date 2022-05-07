#include "stdlib.h"
#include "stdio.h"

/*
Nome:..... Gabriel Muniz
Turma:.... C_11
Enunciado: Faça um programa em C que imprima todos os múltiplos de 3, entre 1 e 100.
*/

int main()
{
    int i = 3;

    printf("Numeros multiplos de 3 entre 1 e 100: ");

    while (i < 100)
    {
        printf("%d", i);
        if (i != 99)
            printf(" - ");
        i += 3;
    }
    return 0;
}