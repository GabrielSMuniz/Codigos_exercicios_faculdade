#include "stdlib.h"
#include "stdio.h"

/*
Nome:..... Gabriel Muniz
Turma:.... C_11
Enunciado: Faça um programa em Linguagem C para obter do usuário uma temperatura em
graus Fahrenheit e retornar o valor correspondente em graus Celsius.
O cálculo deve ser realizado por uma função que vai receber por parâmetro o valor
em Fahrenheit e vai retornar o valor em Celsius.
Fórmula para conversão: C = ((F - 32) / 9) * 5
Casos de teste:
        32 graus Fahrenheit é igual a 0 grau Celsius;
        212 graus Fahrenheit é igual a 100 graus Celsius;
        86 graus Fahrenheit é igual a 30 graus Celsius.
*/

float fahrenheitToCelsius(float temp)
{
    return ((temp - 32) / 9) * 5;
}

int main()
{
    float temperatura_1 = 32,
          temperatura_2 = 212,
          temperatura_3 = 86;

    printf("Fahrenheit: %.2f - Celsius: %.2f\n", temperatura_1, fahrenheitToCelsius(temperatura_1));
    printf("Fahrenheit: %.2f - Celsius: %.2f\n", temperatura_2, fahrenheitToCelsius(temperatura_2));
    printf("Fahrenheit: %.2f -  Celsius: %.2f", temperatura_3, fahrenheitToCelsius(temperatura_3));

    return 0;
}
