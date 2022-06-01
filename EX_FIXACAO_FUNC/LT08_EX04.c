#include "stdlib.h"
#include "stdio.h"

/*
Nome:..... Gabriel Muniz
Turma:.... C_11
Enunciado: Faça um programa em Linguagem C para simular uma calculadora
simples com as seguintes operações possíveis: adição, subtração,
multiplicação e divisão.
O programa inicia com a apresentação ao usuário do menu de opções:

**********
Calculadora
1. Adição
2. Subtração
3. Multiplicação
4. Divisão
5. Sair
**********
Entre com a opção:

Utilize uma função para apresentar o menu inicial e uma função de cada tipo para resolver as operações.
Cada operações (adição; subtração; multiplicação; divisão) deve usar um tipo de função
(sem retorno e sem parâmetro; sem retorno e com parâmetro; com retorno e sem parâmetro;
com retorno e com parâmetro;) - não vale repetir o uso.
*/

int num_1 = 0, num_2 = 0, resultado, opcao, on = 1;

void menuCalculadora()
{
    while (on)
    {
        printf("**********\n");
        printf("Calculadora\n");
        printf("1. Adição\n");
        printf("2. Subtração\n");
        printf("3. Multiplicação\n");
        printf("4. Divisão\n");
        printf("5. Sair\n");
        printf("**********\n");
        printf("Entre com a opção: ");

        scanf("%d", &opcao);
        if(opcao==5){
            break;
        }
        printf("\nNumero 1: ");
        scanf("%d", &num_1);
        printf("Numero 2: ");
        scanf("%d", &num_2);
        switch (opcao)
        {
        case 1:
            printf("\nResultado da soma: ");
            soma();
            break;
        case 2:
            printf("\nResultado da subtração: ");
            subtracao(num_1, num_2);
            break;
        case 3:
            printf("\nResultado da multiplicação: ");
            resultado = multiplicacao();
            break;
        case 4:
            printf("\nResultado da divisão: ");
            resultado = divisao(num_1, num_2);
            break;
        default:
            break;
        }
        printf("%d\n\n", resultado);
    }
}

void soma()
{
    resultado = num_1 + num_2;
}
int subtracao(int n1, int n2)
{
    resultado = n1 - n2;
}
int multiplicacao()
{
    return num_1 * num_2;
}
int divisao(int n1, int n2)
{
    return n1 / n2;
}

int main()
{
    menuCalculadora();
    return 0;
}
