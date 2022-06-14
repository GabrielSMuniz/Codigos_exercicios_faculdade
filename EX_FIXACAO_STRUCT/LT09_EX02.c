#include "stdio.h"

/*
Nome:..... Gabriel Muniz
Turma:.... C_11
Enunciado: Faça um algoritmo que tenha um registro (estrutura) que represente um DVD em uma locadora.
Então, deve ser armazenado o título, gênero, duração e prateleira.
O programa deve pedir os respectivos dados do DVD. Em seguida, deve apresentá-los.
*/

typedef struct DVD
{
    char titulo[50];
    char genero[50];
    int duracao;
    int prateleira;
} DVD;

void mostrarDVD(DVD dDvd)
{
    printf("\nTítulo do filme: %s\nDuração: %d minutos\nGênero: %s\nPrateleira: %d", dDvd.titulo, dDvd.duracao, dDvd.genero, dDvd.prateleira);
}

int main()
{
    DVD dvd1;

    printf("Título do filme: ");
    gets(dvd1.titulo);
    printf("Duração (minutos): ");
    scanf("%d", &dvd1.duracao);
    __fpurge(stdin);
    printf("Gênero: ");
    gets(dvd1.genero);
    printf("Prateleira: ");
    scanf("%d", &dvd1.prateleira);

    mostrarDVD(dvd1);

    return 0;
}
