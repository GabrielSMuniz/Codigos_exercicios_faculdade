#include "stdlib.h"
#include "stdio.h"

/*
Faça um programa em linguagem C que peça um número inteiro e apresente a mensagem “é par” ou “é ímpar”.
Dica: use o operador % (resto da divisão de inteiros). Por exemplo: 5 % 2 retornará o resto da divisão de 5 por 2.
Então, 5 % 2 = 1 (porque 5 dividido por 2 é igual a 2 e resta 1).
Por outro lado, 6 % 2 = 0, porque 6 dividido por 2 é igual a 3 e resta 0
*/

int main()
{
    int numero;
    printf("Digite um numero: ");
    scanf("%d", &numero);
    printf("%d ", numero);
    if(numero%2 == 0){

    printf("e par");
    } else {
       printf("e impar");
    }
    
    return 0;
}