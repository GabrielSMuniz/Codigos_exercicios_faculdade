#include <stdio.h>

/*
Leia 2 valores inteiros X e Y. A seguir, calcule e mostre a soma dos números impares entre eles.
*/


int main()
{
  int x, y, soma = 0;

  scanf("%d", &x);
  scanf("%d", &y);

  if (x > y)
  {
    int temp;
    temp = x;
    x = y;
    y = temp;
  }

  for (int i = x + 1; i < y; i++)
    soma += i % 2 != 0 ? i : 0;

  printf("%d\n", soma);

  return 0;
}