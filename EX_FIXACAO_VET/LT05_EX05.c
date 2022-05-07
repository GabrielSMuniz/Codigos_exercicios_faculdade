#include "stdlib.h"
#include "stdio.h"

#define TAM 5

/*
Nome:..... Gabriel Muniz
Turma:.... C_11
Enunciado: Faça um programa em Linguagem C que peça 5 números reais.
Depois, o programa deve apresentar a média.
Por último, o programa deve procurar qual número digitado é o mais próximo da média e apresentá-lo na tela.
*/

int main()
{
    float vet_valores[TAM],
        soma = 0,
        media = 0;
    int maior_diferenca = 0;

    for (int i = 0; i < TAM; i++)
    {
        printf("Digite o %dº numero: ", i + 1);
        scanf("%f", &vet_valores[i]);
    }
    for (int i = 0; i < TAM; i++)
    {
        soma += vet_valores[i]; // soma += valores[i];
    }
    media = soma / TAM;

    for (int i = 0; i < TAM; i++)
    {
        maior_diferenca = abs(vet_valores[i] - media) < abs(vet_valores[maior_diferenca] - media) ? i : maior_diferenca; // soma += valores[i];
    }
    printf("A media foi: %.2f\n", media);
    printf("O valor mais proximo da media foi o %dº valor: %.2f", maior_diferenca+1, vet_valores[maior_diferenca]);

    return 0;
}
