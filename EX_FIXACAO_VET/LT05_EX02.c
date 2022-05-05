#include "stdlib.h"
#include "stdio.h"

#define TAM 8

/*
Nome:..... Gabriel Muniz
Turma:.... C_11
Enunciado: Faça um programa em Linguagem C que peça o salário de 8 salários de uma determinada empresa.
Armazene esses dados em um vetor. Calcule a média salarial da empresa.
Depois, o programa deve apresentar quantos funcionários recebem menos que a média salarial.
*/

int main()
{
    float vet_valores[TAM];
    float soma = 0;

    for (int i = 0; i < TAM; i++)
    {
        printf("Digite o %dº numero: ", i + 1);
        scanf("%f", &vet_valores[i]);
    }
    for (int i = 0; i < TAM; i++)
    {
        soma += vet_valores[i]; // soma += valores[i];
    }
    printf("A media salarial da empresa e %0.2f", soma/TAM);


    return 0;
}
