#include "stdio.h"

#define LIN 12
#define COL 12

/*
Neste problema você deve ler um número que indica uma coluna de uma matriz
na qual uma operação deve ser realizada,
um caractere maiúsculo, indicando a operação que será realizada,
e todos os elementos de uma matriz M[12][12].
Em seguida, calcule e mostre a soma ou a média dos elementos que
estão na área verde da matriz, conforme for o caso.
A imagem abaixo ilustra o caso da entrada do valor 5 para a coluna da matriz,
demonstrando os elementos que deverão
ser considerados na operação.
*/

int main()
{
    double vet_valores[LIN][COL],
        soma_coluna = 0;
    int num_coluna;
    char operacao;

    scanf("%d ", &num_coluna);
    scanf("%c", &operacao);

    // gera os numeros aleatorios
    for (int i = 0; i < LIN; i++)
    {
        for (int j = 0; j < COL; j++)
            scanf("%lf", &vet_valores[i][j]);
    }

    for (int i = 0; i < COL; i++)
        soma_coluna += vet_valores[i][num_coluna];

    printf("%.1lf\n", operacao == 'S' ? soma_coluna : operacao == 'M' ? (soma_coluna / 12)
                                                                    : -1);
    return 0;
}
