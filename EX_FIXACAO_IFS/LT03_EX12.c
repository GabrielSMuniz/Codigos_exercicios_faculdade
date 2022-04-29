#include "stdlib.h"
#include "stdio.h"

/*
Faça um programa em linguagem C que peça a idade do usuário e apresente uma mensagem de acordo com sua faixa etária:
a. Se for maior ou igual a 65 anos: “você está na melhor idade”;
b. Se for maior ou igual a 40 anos (e menor que 65): “você está na meia idade”;
c. Se for maior ou igual a 30 anos (e menor que 40): “você e adulto”;
d. Se for maior ou igual a 18 anos (e menor que 30): “você e adulto jovem”;
e. Se for maior ou igual a 12 anos (e menor que 18): “você e adolescente”;
f. Se for maior ou igual a 2 anos (e menor que 12): “você e criança”;
g. Se não for nenhuma das anteriores (menor de 2 anos): “você e bebê”.
*/

int main()
{
    int idade;

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    if (idade >= 65)
        printf("voce esta na melhor idade");
    else if (idade >= 40)
        printf("voce esta na meia idade");
    else if (idade >= 30)
        printf("voce e adulto");
    else if (idade >= 18)
        printf("voce e adulto jovem");
    else if (idade >= 12)
        printf("voce e adolescente");
    else if (idade >= 2)
        printf("voce e criança");
    else
        printf("voce e bebê");

    return 0;
}