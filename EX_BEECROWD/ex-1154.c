#include <stdio.h>

/*
Faça um algoritmo para ler um número indeterminado de dados,
contendo cada um, a idade de um indivíduo.
O último dado, que não entrará nos cálculos, contém o valor de idade negativa.
Calcular e imprimir a idade média deste grupo de indivíduos.
*/

int main()
{
  int valor;
  float soma;

  for (int i = 0; 1; i++)
  {
    scanf("%d", &valor);
    if (valor < 0)
    {
      printf("%.2f\n", soma / i);
      break;
    }
    soma += valor;
  }

  return 0;
}