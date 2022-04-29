#include "stdlib.h"
#include "stdio.h"

/*
Faça um programa em linguagem C que peça um número inteiro.
Em seguida, o programa deve apresentar uma mensagem conforme a seguinte regra: 
a. Se o valor for positivo: “Valor positivo”; 
b. Se o valor for negativo: “Valor negativo”; 
c. Se não for nenhuma das opções (se for 0): “Valor neutro”.
*/

int main()
{
    int numero;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    if (numero > 0)
    {
        printf("Valor positivo");
    }
    else  if (numero < 0)
    {
        printf("Valor negativo");
    } else if (numero == 0){
        printf("Valor neutro");
    }
    return 0;
}