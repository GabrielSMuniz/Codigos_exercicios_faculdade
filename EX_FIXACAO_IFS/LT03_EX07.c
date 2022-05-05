#include "stdlib.h"
#include "stdio.h"

/*
Nome:..... Gabriel Muniz
Turma:.... C_11
Enunciado: Criar um algoritmo que leia 2 números. Caso o primeiro número lido seja maior que o segundo,
imprima na tela o primeiro número menos o segundo, caso contrário mostre a soma dos dois números.
*/

int main()
{
    int numero_1, numero_2;

    printf("Digite um numero: ");
    scanf("%d", &numero_1);
    printf("Digite outro numero: ");
    scanf("%d", &numero_2);

    printf("%d", numero_1 > numero_2 ? numero_1 - numero_2 : numero_1 + numero_2);

    return 0;
}