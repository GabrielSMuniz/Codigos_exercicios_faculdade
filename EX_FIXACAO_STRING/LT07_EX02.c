#include "stdlib.h"
#include "stdio.h"
#include "string.h"

/*
Nome:..... Gabriel Muniz
Turma:.... C_11
Enunciado: Faça um programa em Linguagem C que receba uma string e depois um caractere,
e retorne o número de vezes que esse caractere aparece na string.
*/

int main()
{
    char nome[50];
    char carac;
    int cont;

    printf("\nEscreva alguma coisa: ");
    gets(nome);
    printf("Digite uma letra: ");
    scanf("%c", &carac);

    for (int i = 0; i < strlen(nome); i++)
        cont = nome[i] == carac ? cont + 1 : cont;

    printf("A letra \"%c\" letra aparece %d vezes em: \"%s\" ", carac, cont, nome);

    return 0;
}
