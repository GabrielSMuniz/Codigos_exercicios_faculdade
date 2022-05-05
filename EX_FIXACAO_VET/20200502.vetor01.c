/*
Nome...: Francisco Pereira Junior
Turma..: EC31A - C11
Data...: 02/05/2022
Enunciado.: manipulação de vetor com inicialização.

*/

#include <stdio.h>

int main()
{
    float salario = 1500, 
          soma = 0,
          media = 0;
    float valores[] = {100, 200, 350.50, 400, 500.10};
    int i = 0;
    
    printf("\n- mostrando os valores na ordem da inicialização -");
    for(i = 0; i < 5; i++) {
        printf("\n%.2f", valores[i]);    
    }
    
    printf("\n- mostrando os valores na ordem INVERSA da inicialização -");
    for(i = 4; i >= 0; i--) {
        printf("\n%.2f", valores[i]);    
    }
    
    printf("\n- calculando a média de valores -");
    for(i = 0; i < 5; i++) {
        soma = soma + valores[i];    // soma += valores[i];
    }
    media = soma / 5;
    printf("\nMedia = %.2f", media);
    
    printf("\n- valores que estão ACIMA da média -");
    for(i = 0; i < 5; i++) {
        if(valores[i] > media) {
            printf("\nvalores[%d] = %.2f", i, valores[i]);   
        }
    }

    return 0;
}
