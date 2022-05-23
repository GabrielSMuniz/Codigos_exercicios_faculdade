#include "stdlib.h"
#include "stdio.h"
#include "time.h"

#define LIN 2
#define COL 3

/*
Nome:..... Gabriel Muniz
Turma:.... C_11
Enunciado: Faça um programa em Linguagem C que crie três matrizes de 3 x 3 de inteiros: mat1, mat2 e mult.
Em seguida, peça para o usuário digitar os valores para mat1 e mat2.
Em seguida, o algoritmo deverá preencher a matriz mult com a multiplicação
das respectivas posições das matrizes anteriores.
*/

int main()
{

    // recebe uma seed a partir do tempo, para gerar numeros aleatorios
    srand(time(0));

    int mat1[LIN][COL],
        mat2[LIN][COL],
        mult[LIN][COL],
        soma_linha = 0;

    // gera os numeros aleatorios para mat1 e mat2
    for (int i = 0; i < LIN; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            mat2[i][j] = rand() % 100;
            mat1[i][j] = rand() % 100;
        }
    }

    printf("\nMatriz 1: ");
    for (int i = 0; i < LIN; i++)
    {
        printf("\n");
        for (int k = 0; k < COL * 5; k++)
            printf("-");
        printf("\n");

        for (int j = 0; j < COL; j++)
        {

            printf("|%3d|", mat1[i][j]);
        }
    }
    printf("\n");
    for (int k = 0; k < COL * 5; k++)
        printf("-");
    printf("\n");

    printf("\nMatriz 2: ");
    for (int i = 0; i < LIN; i++)
    {
        printf("\n");
        for (int k = 0; k < COL * 5; k++)
            printf("-");
        printf("\n");

        for (int j = 0; j < COL; j++)
        {

            printf("|%3d|", mat2[i][j]);
        }
    }
    printf("\n");
    for (int k = 0; k < COL * 5; k++)
        printf("-");
    printf("\n");

    for (int i = 0; i < LIN; i++)
        for (int j = 0; j < COL; j++)
            mult[i][j] = mat1[i][j] * mat2[i][j];

    printf("\nMatriz de multiplicacao: ");
    for (int i = 0; i < LIN; i++)
    {
        printf("\n");
        for (int k = 0; k < COL * 6; k++)
            printf("-");
        printf("\n");

        for (int j = 0; j < COL; j++)
        {

            printf("|%4d|", mult[i][j]);
        }
    }
    printf("\n");
    for (int k = 0; k < COL * 6; k++)
        printf("-");
    printf("\n");

    return 0;
}
