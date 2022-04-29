#include "stdlib.h"
#include "stdio.h"

/*
Faça um programa em linguagem C que leia o gênero de uma pessoa
(‘F’ para feminino ou ‘M’ para masculino - deve ser UM caractere em maiúsculo) e a sua idade.
Se o usuário for do sexo Feminino, apresentar a mensagem “Olá senhora, você tem ??? anos.“.
Do contrário, apresentar a mensagem “Olá senhor, você tem ??? anos. “ Trocar ??? pela idade digitada pelo usuário.
*/

int main()
{
    char genero;
    int idade;

    printf("Digite seu genero (M - masculino, F - feminino): ");
    scanf("%c", &genero);
    printf("Digite sua idade: ");
    scanf("%d", &idade);

    if (genero == 'M')
    {
        printf("Ola senhor, voce tem %d anos.", idade);
    }
    else if (genero == 'F')
    {
        printf("Ola senhora, voce tem %d anos.", idade);
    }
    return 0;
}