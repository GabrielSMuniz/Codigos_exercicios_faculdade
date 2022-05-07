#include "stdlib.h"
#include "stdio.h"
#include "time.h"

#define TAM 25
/*
Nome:..... Gabriel Muniz
Turma:.... C_11
Enunciado: Faça um programa em Linguagem C que receba (ou gere aleatoriamente) 25 valores.
Após digitados, o programa deve ordenar os valores no vetor e apresentá-los na tela em ordem decrescente.
*/

int main()
{
    printf("\n");

    // recebe uma seed a partir do tempo, para gerar numeros aleatorios
    srand(time(0));
    int vet_valores[TAM],
        maior_valor = 0,
        troca = 0;
    // gera os numeros aleatorios
    for (int i = 0; i < TAM; i++)
    {
        vet_valores[i] = rand() % 1000;
    }

    printf("Numeros na ordem original: ");
    for(int i = 0; i < TAM; i++)
    {
        printf("%d", vet_valores[i]);
        if(i!=TAM-1)
        printf("-");
    }

    // organiza os numeros em ordem decrescente
    for (int i = 0; i < TAM; i++)
    {
        maior_valor = i;
        for (int j = i; j < TAM; j++)
        {
            maior_valor = vet_valores[maior_valor] > vet_valores[j] ? maior_valor : j;
        }
        troca = vet_valores[i];
        vet_valores[i] = vet_valores[maior_valor];
        vet_valores[maior_valor] = troca;
    }

    printf("\nNumeros em ordem decrescente: ");

    for (int i = 0; i < TAM; i++)
    {
        printf("%d", vet_valores[i]);
        if(i!=TAM-1)
        printf("-");
    }
    printf("\n");

    return 0;
}
