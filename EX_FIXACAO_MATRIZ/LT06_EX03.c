#include "stdlib.h"
#include "stdio.h"
#include "time.h"

#define LIN 2
#define COL 3

/*
Nome:..... Gabriel Muniz
Turma:.... C_11
Enunciado: Faça um programa em Linguagem C que crie uma matriz de 2x3, de números inteiros
e a populacione usando laço PARA (FOR).
Por fim, calcule e apresente a soma de cada linha.
*/

int main()
{

    // recebe uma seed a partir do tempo, para gerar numeros aleatorios
    srand(time(0));

    int vet_valores[LIN][COL],
        soma_linha = 0;

    // gera os numeros aleatorios
    for (int i = 0; i < LIN; i++)
    {
        for (int j = 0; j < COL; j++)
            vet_valores[i][j] = rand() % 1000;
    }

    printf("\nMatriz: ");
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

    for (int i = 0; i < LIN; i++)
    {
        for (int j = 0; j < COL; j++)
            soma_linha += vet_valores[i][j];
        printf("Soma da linha %d: %d\n", i + 1, soma_linha);
        soma_linha = 0;
    }

    return 0;
}
