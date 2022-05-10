#include "stdlib.h"
#include "stdio.h"
#include "time.h"

#define TAM 2

/*
Nome:..... Gabriel Muniz
Turma:.... C_11
Enunciado: Faça um programa em Linguagem C que crie uma matriz de 2x2, de números inteiros.
Populacione-a usando laço PARA (FOR) e, por fim, apresente todos os valores na tela.
*/

int main()
{

    // recebe uma seed a partir do tempo, para gerar numeros aleatorios
    srand(time(0));

    int vet_valores[TAM][TAM];

    // gera os numeros aleatorios
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
            vet_valores[i][j] = rand() % 1000;
    }

    printf("\nMatriz: ");

    for (int i = 0; i < TAM; i++)
    {
        printf("\n");
        for (int k = 0; k < TAM * 5; k++)
            printf("-");
        printf("\n");

        for (int j = 0; j < TAM; j++)
        {

            printf("|%3d|", vet_valores[i][j]);
        }
    }
    printf("\n");
        for (int k = 0; k < TAM * 5; k++)
            printf("-");
    printf("\n");

    return 0;
}
