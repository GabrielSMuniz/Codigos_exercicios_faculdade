#include <stdio.h>

// Programação que recebe 3 valores diferentes e retorna eles em ordem crescente no console.

int main()
{
    int a, b, c;
    while (0)
    {
        printf("Primeiro numero: ");
        scanf("%d", &a);
        printf("Segundo numero: ");
        scanf("%d", &b);
        printf("Terceiro numero: ");
        scanf("%d", &c);
        printf("Numeros em ordem crescente: ");

        if (a < b)
        {
            if (a < c)
            {
                printf("%d - ", a);
                if (b < c)
                {
                    printf("%d - %d", b, c);
                }
                else
                {
                    printf("%d - %d", c, b);
                }
            }
            else
            {
                printf("%d - %d - %d", c, a, b);
            }
        }
        else
        {
            if (b < c)
            {
                printf("%d - ", b);
                if (a < c)
                {
                    printf("%d - %d", a, c);
                }
                else
                {
                    printf("%d - %d", c, a);
                }
            }
            else
            {
                printf("%d - %d - %d", c, b, a);
            }
        }
        printf("\n\n");
    }
    return 0;
}
