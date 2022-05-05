#include "stdlib.h"
#include "stdio.h"
#include <string.h>
/*
Nome:..... Gabriel Muniz
Turma:.... C_11
Enunciado: Escreva um programa em linguagem C que leia o conceito anual de um aluno em uma disciplina e informe o desempenho dele. Se for um conceito inválido escreva uma mensagem informando o ocorrido. Exemplo: 'A' - Conhecimento Pleno, 'B' - Conhecimento Parcialmente Pleno, 'C' - Conhecimento Suficiente, 'D' - Conhecimento Insuficiente. '<Qualquer outro caracter>': Conceito Inválido.
*** este exercícios deve ser feito 2x: LT03_EX15a usando apenas Ifs; LT02_EX15b usando switch case.
*/

typedef struct Colors
{
    char HEADER[6], ENDC[6], OKBLUE[6];

    // int OKBLUE, OKCYAN, OKGREEN, WARNING, FAIL, BOLD, UNDERLINE;
} ;
// int HEADER = '\033[95m';
// int OKBLUE = '\033[94m';
// int OKCYAN = '\033[96m';
// int OKGREEN = '\033[92m';
// int WARNING = '\033[93m';
// int FAIL = '\033[91m';
// int ENDC = '\033[0m';
// int BOLD = '\033[1m';
// int UNDERLINE = '\033[4m';
int main()
{
    struct Colors color;
    strcpy(color.HEADER, "\033[95m");
    strcpy(color.ENDC, "\033[0m");
    strcpy(color.OKBLUE, "\033[94m");

    printf("%solaaaaa%s", color.OKBLUE, color.ENDC);
    float total_parafusos, parafusos_defeituosos;

    printf("Digite a quantidade total de parafusos: ");
    scanf("%d", &total_parafusos);
    printf("Digite a quantidade de parafusos com defeito: ");
    scanf("%d", &parafusos_defeituosos);
    printf(parafusos_defeituosos / total_parafusos > 0.1 ? "A produçao esta ruim" : "A produçao esta boa");

    return 0;
}