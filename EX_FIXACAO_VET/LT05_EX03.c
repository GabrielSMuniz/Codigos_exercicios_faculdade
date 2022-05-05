#include "stdlib.h"
#include "stdio.h"

#define TAM 5

/*
Nome:..... Gabriel Muniz
Turma:.... C_11
Enunciado: Faça um programa em Linguagem C que peça 5 números inteiros e, no final,
troque a ordem do primeiro número com a do último número digitado.
Apresente os dados originais e os dados alterados na tela.
*/

int main()
{
    int vet_valores[TAM];

    for (int i = 0; i < TAM; i++)
    {
        printf("Digite o %dº numero: ", i + 1);
        scanf("%d", &vet_valores[i]);
    }
    printf("Numeros: %d", vet_valores[TAM-1]);
     for (int i = 1; i < TAM-1; i++)
    {
           printf(", %d", vet_valores[i]);

    }
    printf(", %d", vet_valores[0]);



    return 0;
}
