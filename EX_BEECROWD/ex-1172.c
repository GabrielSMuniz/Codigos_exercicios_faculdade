#include <stdio.h>

/*
Faça um programa que leia um vetor X[10].
Substitua a seguir, todos os valores nulos e negativos do vetor X por 1.
Em seguida mostre o vetor X.
*/

int main()
{

  int valores[10];

  for (int i = 0; i < 10; i++)
  {
    scanf("%d", &valores[i]);
    valores[i] = valores[i] <= 0 ? 1 : valores[i];
  }

  for (int i = 0; i < 10; i++)
  {
    printf("X[%d] = %d\n", i, valores[i]);
  }

  return 0;
}