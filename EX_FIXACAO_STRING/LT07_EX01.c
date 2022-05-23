#include "stdlib.h"
#include "stdio.h"

/*
Nome:..... Gabriel Muniz
Turma:.... C_11
Enunciado: Faça um programa em Linguagem C que receba o nome completo do usuário
e apresente-o com uma mensagem de boas vindas. 
*/

int main()
{
    char nome[50];
    printf("Escreva seu nome: ");
    gets(nome);
    printf("Seja muito bem vindo, %s!", nome);

    return 0;
}
