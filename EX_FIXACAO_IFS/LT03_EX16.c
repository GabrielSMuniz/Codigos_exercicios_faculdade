#include "stdlib.h"
#include "stdio.h"

/*
Nome:..... Gabriel Muniz
Turma:.... C_11
Enunciado: Escreva um programa em linguagem C que leia o conceito anual de um aluno em uma
disciplina e informe o desempenho dele.
Se for um conceito inválido escreva uma mensagem informando o ocorrido.
Exemplo: 'A' - Conhecimento Pleno, 'B' - Conhecimento Parcialmente Pleno,
'C' - Conhecimento Suficiente, 'D' - Conhecimento Insuficiente. '<Qualquer outro caracter>': Conceito Inválido.
*** este exercícios deve ser feito 2x: LT03_EX15a usando apenas Ifs; LT02_EX15b usando switch case.
*/

// char textcolor(char texto, char color){
//     return "\ " + color + texto;
// }

int main()
{
    char conceito_anual;

    printf("Digite o seu conceito anual: ");
    scanf("%c", &conceito_anual);

    switch (conceito_anual)
    {
    case 'A':
        printf("Conhecimento Pleno");
        break;
    case 'B':
        printf("Conhecimento Parcialmente Pleno");

        break;
    case 'C':
        printf("Conhecimento Suficiente");

        break;
    case 'D':
        printf("\033[;32mConhecimento Insuficiente\033[0m");
        break;

    default:
        printf("\033[41;32mBlue text\033[0m");
        break;
    }

    return 0;
}