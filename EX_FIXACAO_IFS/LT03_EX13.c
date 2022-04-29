#include "stdlib.h"
#include "stdio.h"

/*
Em uma indústria de parafusos, um algoritmo determina se a produção está boa ou ruim.
Uma produção é ruim quando o número de parafusos com defeito for maior do que 10% do total produzido.
Faça um programa em linguagem C que peça o número total de parafusos produzidos e,
em seguida, peça o número de parafusos com defeito.
O programa, então, deve calcular o limite de peças com defeito permitidas
(com base no total de peças produzidas e a porcentagem limite) e apresentar se a produção está boa ou ruim.
*/

int main()
{
    float total_parafusos, parafusos_defeituosos;

    printf("Digite a quantidade total de parafusos: ");
    scanf("%d", &total_parafusos);
    printf("Digite a quantidade de parafusos com defeito: ");
    scanf("%d", &parafusos_defeituosos);
    printf(parafusos_defeituosos / total_parafusos > 0.1 ? "A produçao esta ruim" : "A produçao esta boa");

    return 0;
}