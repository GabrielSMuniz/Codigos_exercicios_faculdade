#include "stdlib.h"
#include "stdio.h"

/*
Nome:..... Gabriel Muniz
Turma:.... C_11
Enunciado: Faça um programa em linguagem C que leia uma valor do usuário e diga se ele
 é um valor igual a zero.
*/

int main()
{
    int numero;
    printf("Digite um numero: ");
    scanf("%d", &numero);
    if (numero == 0)
    {
        printf("Seu numero e igual a zero");
    }
    else
    {
        printf("Seu numero nao e igual a zero");
    }

    return 0;
}
