#include "stdlib.h"
#include "stdio.h"

/*
Nome:..... Gabriel Muniz
Turma:.... C_11
Enunciado: Faça um programa em linguagem C que informe se um número é PAR.
*/

int main()
{
    int numero;
    printf("Digite um numero: ");
    scanf("%d", &numero);
    if(numero%2 == 0){
    printf("Esse numero e par");
    } else {
       printf("Esse numero nao e par");
    }
    
    return 0;
}