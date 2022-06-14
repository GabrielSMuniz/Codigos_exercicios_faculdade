#include <stdio.h>
#include <string.h>

/*
João quer montar um painel de leds contendo diversos números.
Ele não possui muitos leds, e não tem certeza se conseguirá montar o número desejado.
Considerando a configuração dos leds dos números abaixo, faça um algoritmo que ajude João
a descobrir a quantidade de leds necessário para montar o valor.

*/

int main()
{
  int num_linhas, num_leds;
  char qnt_leds[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6},
       valor[100];

  scanf("%d", &num_linhas);

  for (int i = 0; i < num_linhas; ++i)
  {
    scanf("%s", &valor);

    num_leds = 0;
    for (int j = 0; j < strlen(valor); ++j)
    {
      num_leds += qnt_leds[valor[j] - '0'];
    }
    printf("%d leds\n", num_leds);
  }
  return 0;
}