#include <stdio.h>

/*
Faça um programa que leia um valor N. Este N será o tamanho de um vetor X[N].
A seguir, leia cada um dos valores de X, encontre o menor elemento deste vetor e
a sua posição dentro do vetor, mostrando esta informação.
*/

int main()
{

  int num_valores;
  scanf("%d", &num_valores);
  int valores[num_valores],
      menor_valor = 0;

  for (int i = 0; i < num_valores; i++)
  {
    scanf("%d", &valores[i]);
  }
  for (int i = 0; i < num_valores; i++)
  {
    menor_valor = valores[menor_valor] < valores[i] ? menor_valor : i;
  }

  printf("Menor valor: %d\nPosicao: %d\n", valores[menor_valor], menor_valor);

  return 0;
}