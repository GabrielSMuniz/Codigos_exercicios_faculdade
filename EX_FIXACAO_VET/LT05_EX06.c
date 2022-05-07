#include "stdlib.h"
#include "stdio.h"

#define TAM 5

/*
Nome:..... Gabriel Muniz
Turma:.... C_11
Enunciado: Faça um programa em Linguagem C que peça 5 números inteiros.
Após digitados, o programa deve ordenar os valores no vetor e apresentá-los na tela em ordem crescente.
*/

int main()
{
    int vet_valores[TAM],
        menor_valor = 0,
        troca;

    for (int i = 0; i < TAM; i++)
    {
        printf("Digite o %dº numero: ", i + 1);
        scanf("%d", &vet_valores[i]);
    }

    printf("Numeros na ordem original: ");
    for (int i = 0; i < TAM; i++)
    {
        printf("%d", vet_valores[i]);
        if (i != TAM - 1)
            printf("-");
    }

    for (int i = 0; i < TAM; i++)
    {
        menor_valor = i;
        for (int j = i; j < TAM; j++)
        {
            menor_valor = vet_valores[menor_valor] < vet_valores[j] ? menor_valor : j;
        }
        troca = vet_valores[i];
        vet_valores[i] = vet_valores[menor_valor];
        vet_valores[menor_valor] = troca;
    }
    printf("\nNumeros em ordem crescente: ");

    for (int i = 0; i < TAM; i++)
    {
        printf("%d", vet_valores[i]);
        if (i != TAM - 1)
            printf("-");
    }

    return 0;
}
