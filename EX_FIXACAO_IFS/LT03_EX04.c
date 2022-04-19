#include "stdlib.h"
#include "stdio.h"

// Faça um programa em linguagem C que receba o valor do salário de um funcionário, se ele ganhar menos que 2 salários mínimos, acresça um bônus de 10% ao salário a receber.

int main()
{
    const int salario_min = 1212;
    int salario;
    
    printf("Digite um salario: R$");
    scanf("%d", &salario);
    salario = salario < 2*salario_min? salario*1.1: salario;
    
    printf("Salario corrigido: R$%d",salario);
    
    return 0;
}