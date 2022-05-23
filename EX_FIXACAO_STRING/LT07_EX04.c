#include "stdlib.h"
#include "stdio.h"
#include "string.h"

/*
Nome:..... Gabriel Muniz
Turma:.... C_11
Enunciado: Faça um programa em Linguagem C que receba uma palavra do usuário e retire o hífen se acaso existir.
Não é apenas para imprimir, precisa retirar o hífen da palavra.
*/

int main()
{
    char string[30];

    printf("\nDigite algo: ");
    gets(string);

    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == '-')
            string[i] = ' ';
    }
    printf("%s", string);

    return 0;
}
