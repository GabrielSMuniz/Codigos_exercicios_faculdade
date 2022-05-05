#include "stdlib.h"
#include "stdio.h"

#define TAM 6

/*
Nome:..... Gabriel Muniz
Turma:.... C_11
Enunciado: Faça um programa em Linguagem C que peça 5 números inteiros.
Após digitados, o programa deve ordenar os valores no vetor e apresentá-los na tela em ordem crescente.
*/

int main()
{
    int vet_valores[TAM];
    int vet_valores_crescente[TAM];

    for (int i = 0; i < TAM; i++)
    {
        printf("Digite o %dº numero: ", i + 1);
        scanf("%f", &vet_valores[i]);
    }
    for (int i = 0; i < TAM - 1; i++)
    {
        for (int j = 0; j < TAM - 1; j++){
            printf("%d ", vet_valores[i] < vet_valores[j] ? vet_valores[i] : vet_valores[j]);
        }

    }

    return 0;
}
