#include "stdlib.h"
#include "stdio.h"

/*
Nome:..... Gabriel Muniz
Turma:.... C_11
Enunciado: Faça um programa em linguagem C que receba uma operação (caracter: + - * / ) e depois,
2 valores reais. Realize apenas a operação escolhida pelo usuário.
*/

int main()
{
    char operador;
    int numero_1;
    int numero_2;
    int resultado;

    printf("Calculadora \n");
    printf("Digite um operador (+ - * /): ");
    scanf("%c", &operador);

    printf("Digite um numero: ");
    scanf("%d", &numero_1);
    printf("Digite outro numero: ");
    scanf("%d", &numero_2);

    switch (operador)
    {
    case '+':
        resultado = numero_1 + numero_2;
        break;
    case '-':
        resultado = numero_1 - numero_2;
        break;
    case '*':
        resultado = numero_1 * numero_2;
        break;
    case '/':
        resultado = numero_1 / numero_2;
        break;
    default:
        printf("Error");
        break;
    }

    printf("Resultado: %d", resultado);

    return 0;
}