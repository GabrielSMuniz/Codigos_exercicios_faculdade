#include "stdlib.h"
#include "stdio.h"

/*
Nome:..... Gabriel Muniz
Turma:.... C_11
Enunciado: Faça um programa em Linguagem C que escreva uma função para receber um número e
retornar o valor absoluto deste número (a função sempre retorna um valor positivo).
*/

int abs(int num)
{
    return num < 0 ? -num : num;
}

int main()
{
    int valor = -10;
    printf("Valor: %d\nValor absoluto: %d", valor, abs(valor));
    return 0;
}
