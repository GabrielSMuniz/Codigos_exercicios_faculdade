#include "stdlib.h"
#include "stdio.h"
#include "string.h"

/*
Nome:..... Gabriel Muniz
Turma:.... C_11
Enunciado: Faça um programa em Linguagem C que receba o nome de usuário e sua senha de acesso a um sistema.
Se o usuário for “joao“ e a senha “123“, permita o acesso. Caso contrário, dê uma mensagem de ACESSO NEGADO.
*/

int main()
{
    char nome[30],
        senha[30];

    printf("\nDigite o nome do usuario: ");
    gets(nome);
    printf("Digite a senha: ");
    gets(senha);

    if (strcmp(nome, "joao") == 0 && strcmp(senha, "123") == 0)
        printf("ACESSO PERMITIDO!");
    else
        printf("ACESSO NEGADO!");

    return 0;
}
