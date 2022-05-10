#include "stdlib.h"
#include "stdio.h"
#include "time.h"

#define LIN 3
#define COL 2

/*
Nome:..... Gabriel Muniz
Turma:.... C_11
Enunciado: Faça um programa em Linguagem C que crie uma matriz de 3x2, de números inteiros.
Populacione-a usando laço PARA (FOR) e, por fim, apresente todos os valores,
mas de forma invertida ( o que é linha passa aparecer como coluna e assim por diante).
*/

int main()
{

    // recebe uma seed a partir do tempo, para gerar numeros aleatorios
    srand(time(0));

    int vet_valores[LIN][COL];

    // gera os numeros aleatorios
    for (int i = 0; i < LIN; i++)
    {
        for (int j = 0; j < COL; j++)
            vet_valores[i][j] = rand() % 1000;
    }

    printf("\nMatriz normal: ");
    for (int i = 0; i < LIN; i++)
    {
        printf("\n");
        for (int k = 0; k < COL * 5; k++)
            printf("-");
        printf("\n");

        for (int j = 0; j < COL; j++)
        {

            printf("|%3d|", vet_valores[i][j]);
        }
    }
    printf("\n");
    for (int k = 0; k < COL * 5; k++)
        printf("-");
    printf("\n");



    printf("\nMatriz invertida: ");
    for (int i = 0; i < COL; i++)
    {
        printf("\n");
        for (int k = 0; k < LIN * 5; k++)
            printf("-");
        printf("\n");

        for (int j = 0; j < LIN; j++)
        {

            printf("|%3d|", vet_valores[j][i]);
        }
    }
    printf("\n");
    for (int k = 0; k < LIN * 5; k++)
        printf("-");
    printf("\n");

    return 0;
}
