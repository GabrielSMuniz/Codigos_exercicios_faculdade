#include "stdlib.h"
#include "stdio.h"

#define TAM 6

/*
Nome:..... Gabriel Muniz
Turma:.... C_11
Enunciado: Faça um programa em Linguagem C que peça 5 números reais ao usuário.
Armazene esses números em um vetor.
Depois, o programa deve apresentar o número maior.
*/

int main()
{
    int vet_valores[TAM];
    int numero_maior = 0;

    for (int i = 0; i < TAM; i++)
    {
        printf("Digite o %dº numero: ", i + 1);
        scanf("%d", &vet_valores[i]);
        numero_maior = numero_maior < vet_valores[i] ? vet_valores[i] : numero_maior;
    }
    printf("Esse foi o maior numero digitado: %d", numero_maior);
    return 0;
}