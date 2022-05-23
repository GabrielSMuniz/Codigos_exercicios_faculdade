#include "stdlib.h"
#include "stdio.h"
#include "string.h"

/*
Nome:..... Gabriel Muniz
Turma:.... C_11
Enunciado: Faça um programa em Linguagem C que receba
o nome completo do usuário e troque o último sobrenome por “XPTO”.
Não é apenas para imprimir, precisa substituir o último sobrenome.
*/

int main()
{
    char nome[50];
    int index;

    printf("\nDigite seu nome completo: ");
    gets(nome);

    for (int i = 0; i < strlen(nome); i++)
        index = nome[i] == ' ' ? i : index;
    nome[index] = '\0';
    strcat(nome, " XPTO");
    printf("Retorno: %s", nome);

    return 0;
}
