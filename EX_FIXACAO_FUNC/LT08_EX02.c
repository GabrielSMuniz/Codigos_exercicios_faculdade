#include "stdlib.h"
#include "stdio.h"

/*
Nome:..... Gabriel Muniz
Turma:.... C_11
Enunciado: Faça um programa em Linguagem C que escreva uma função para calcular a média aritmética de 3 valores.
A função deve receber os valores como parâmetro, calcular e apresentar o resultado na tela.
*/

float media(float num_1, float num_2, float num_3)
{
    return (num_1 + num_2 + num_3) / 3;
}

int main()
{
    float valor_1 = 13,
        valor_2 = 36,
        valor_3 = 213;

    printf("Valores: %.2f - %.2f - %.2f\nMedia: %.2f", valor_1, valor_2, valor_3, media(valor_1, valor_2, valor_3));
    return 0;
}
