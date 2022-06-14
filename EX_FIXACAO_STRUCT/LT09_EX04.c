#include "stdio.h"

/*
Nome:..... Gabriel Muniz
Turma:.... C_11
Enunciado: Faça um algoritmo de pokèdex.
O pokèdex deve armazenar cinco pokèmons (para isso, crie um vetor de pokèmon de 5 posições).
Cada pokemon deve possuir os campos como o do exercício 3.
O algoritmo deve pedir os dados dos cinco pokèmons (um pokèmon por vez). E, no fim, apresentá-los todos.
*/

#define QNTD 5

typedef struct Pokemon
{
    char nome[50];
    int vida;
    int ataque;
    int defesa;

} Pokemon;

void mostrarPokemon(Pokemon dPokemon)
{
    printf("\nNome do Pokemon: %s\nVida: %d\nAtaque: %d\nDefesa: %d", dPokemon.nome, dPokemon.vida, dPokemon.ataque, dPokemon.defesa);
}

int main()
{
    Pokemon pokemon[QNTD];

    for (int i = 0; i < QNTD; i++)
    {

        printf("Nome do %dº Pokemon: ", i + 1);
        gets(pokemon[i].nome);
        __fpurge(stdin);
        printf("Vida: ");
        scanf("%d", &pokemon[i].vida);
        __fpurge(stdin);
        printf("Ataque: ");
        scanf("%d", &pokemon[i].ataque);
        printf("Defesa: ");
        scanf("%d", &pokemon[i].defesa);
        __fpurge(stdin);
        printf("\n");
    }

    for (int i = 0; i < QNTD; i++)
        mostrarPokemon(pokemon[i]);

    return 0;
}
