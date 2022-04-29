#include "stdlib.h"
#include "stdio.h"

/*
    Você está jogando um bingo e só faltam as "pedras" 21 e 53.
    Faça um programa em linguagem C que receba 2 valores "cantados" do usuário,
    se os valores "cantados" forem os seus, diga BINGO!!!
    Ao final, ganhando ou não, de uma mensagem de fim da rodada.
*/

int main()
{
    int numero_1, numero_2;

    printf("Digite um numero: ");
    scanf("%d", &numero_1);
    printf("Digite outro numero: ");
    scanf("%d", &numero_2);

    if (numero_1 == 21 && numero_2 == 53 ||
        numero_1 == 53 && numero_2 == 21)
    printf("BINGO!!!\n");      
    printf("Fim da rodada...");
    
    return 0;
}