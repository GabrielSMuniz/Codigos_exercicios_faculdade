#include "stdlib.h"
#include "stdio.h"
#include "string.h"

/*
Nome:..... Gabriel Muniz
Turma:.... C_11
Enunciado: Faça um programa em Linguagem C receba uma string
e um caractere, e apague todas as ocorrências desse caractere
na string.
*/

int main()
{
    char string[50],
        string_crgd[50],
        carac;
    int index = 0;

    printf("\nDigite algo: ");
    gets(string);
    printf("Digite um caractere: ");
    scanf("%c", &carac);

    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] != carac)
        {
            string_crgd[index] = string[i];
            string_crgd[index + 1] = '\0';
            index++;
        }
    }

    printf("Retorno: %s", string_crgd);

    return 0;
}
