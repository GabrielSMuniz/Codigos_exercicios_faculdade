#include "stdlib.h"
#include "stdio.h"

/*
Nome:..... Gabriel Muniz
Turma:.... C_11
Enunciado: Faça um programa em linguagem C que informe se uma determinada pessoa é maior de idade.
*/

int main()
{
    int idade;
    printf("Digite a idade de uma pessoa: ");
    scanf("%d", &idade);
    if(idade >= 18){
    printf("Essa pessoa e maior de idade");
    } else {
       printf("Essa pessoa nao e maior de idade");
    }
        
    return 0;
}