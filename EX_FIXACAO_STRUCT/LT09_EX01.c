#include "stdio.h"

/*
Nome:..... Gabriel Muniz
Turma:.... C_11
Enunciado: Faça um algoritmo que tenha um registro (estrutura) que represente um aluno.
O usuário deve digitar o RA, nome e endereço do aluno.
Em seguida, o algoritmo deve apresentar os dados do aluno.
*/

typedef struct Aluno
{
    char nome[50];
    int ra;
    char endereco[50];
} Aluno;

void mostrarAluno(Aluno dAluno)
{
    printf("\nNome: %s\nRA: %d\nEndereço: %s", dAluno.nome, dAluno.ra, dAluno.endereco);
}

int main()
{
    Aluno aluno1;

    printf("Digite seu nome: ");
    gets(aluno1.nome);
    printf("Digite seu RA: ");
    scanf("%d", &aluno1.ra);
    __fpurge(stdin);
    printf("Digite seu endereço: ");
    gets(aluno1.endereco);

    mostrarAluno(aluno1);

    return 0;
}
