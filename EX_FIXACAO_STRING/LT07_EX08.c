#include "stdlib.h"
#include "stdio.h"
#include "string.h"

/*
Nome:..... Gabriel Muniz
Turma:.... C_11
Enunciado: Faça um programa em Linguagem C que receba 3 nomes completos
(até 30 caracteres) e imprima-os em ordem crescente.
*/

int main()
{
    char nome_1[30],
        nome_2[30],
        nome_3[30];

    printf("\nDigite um nome: ");
    gets(nome_1);
    printf("Digite um outro nome: ");
    gets(nome_2);
    printf("Digite mais um nome: ");
    gets(nome_3);

    printf("Nomes em ordem crescente: ");

    if (strcmp(nome_1, nome_2) < 0)
    {
        if (strcmp(nome_1, nome_3) < 0)
        {
            printf("%s - ", nome_1);
            if (strcmp(nome_2, nome_3) < 0)
            {
                printf("%s - ", nome_2);
                printf("%s", nome_3);
            }
            else
            {
                printf("%s - ", nome_3);
                printf("%s", nome_2);
            }
        }
        else
        {
            printf("%s - ", nome_3);
            printf("%s - ", nome_1);
            printf("%s", nome_2);
        }
    }
    else
    {
        if (strcmp(nome_2, nome_3) < 0)
        {
            printf("%s - ", nome_2);
            if (strcmp(nome_1, nome_3) < 0)
            {
                printf("%s - ", nome_1);
                printf("%s", nome_3);
            }
            else
            {
                printf("%s - ", nome_3);
                printf("%s", nome_1);
            }
        }
        else
        {
            printf("%s - ", nome_3);
            printf("%s - ", nome_2);
            printf("%s", nome_1);
        }
    }

    return 0;
}
