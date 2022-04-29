#include "stdlib.h"
#include "math.h"
#include "stdio.h"

/*
Faça um programa em Linguagem C que apresente um menu e pergunte ao usuário se ele deseja calcular:

1) a área de um triângulo (base vezes altura dividido por 2
2) a área de um círculo (pi multiplicado pelo raio ao quadrado)
3) a área de um cubo (6 vezes a área do quadrado)
Depois, solicitar os dados necessários para calcular a área escolhida, e mostrar o resultado na tela.
*/

int main()
{
    float raio, base, altura, area;
    int calculo;

    printf("1) a area de um triangulo (base vezes altura dividido por 2\n");
    printf("2) a area de um circulo (pi multiplicado pelo raio ao quadrado)\n");
    printf("3) a area de um cubo (6 vezes a area do quadrado)');\n");

    printf("Digite o numero do calculo desejado: ");
    scanf("%d", &calculo);
    switch (calculo)
    {
    case 1:
        printf("Digite o valor da base do triangulo: ");
        scanf("%f", &base);
        printf("Digite o valor da altura do triangulo: ");
        scanf("%f", &altura);
        printf("A area do triangulo é %f", base * altura / 2);
        break;
    case 2:
        printf("Digite o valor do raio da circunferencia: ");
        scanf("%f", &raio);
        printf("A area do circulo é %f", 3.14 * raio * raio);
        break;
    case 3:
        printf("Digite o valor da area da face do cubo: ");
        scanf("%f", &area);
        printf("A area do cubo é %f", 6 * area);
        break;
    default:
        printf("ERROR");
        break;
    }
    printf("\n");

    return 0;
}