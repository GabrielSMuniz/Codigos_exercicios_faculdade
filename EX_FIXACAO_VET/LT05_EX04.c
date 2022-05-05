#include "stdlib.h"
#include "stdio.h"

#define TAM 5

/*
Nome:..... Gabriel Muniz
Turma:.... C_11
Enunciado: Faça um programa em Linguagem C que peça 6 números inteiros e, depois,
apresente-os na tela na forma invertida ao que foi digitado. Exemplo, se foi digitado 1 3 2 4 5 9,
deve ser apresentado 9 5 4 2 3 1.

*/

int main()
{
    int vet_valores[TAM];

    for (int i = 0; i < TAM; i++)
    {
        printf("Digite o %dº numero: ", i + 1);
        scanf("%d", &vet_valores[i]);
    }
    printf("Numeros: ");

    for (int i = TAM; i >= 0; i--)
    {
        printf("%d ", vet_valores[i]);
        if (i != 0)
            printf("- ");
    }

    return 0;
}
