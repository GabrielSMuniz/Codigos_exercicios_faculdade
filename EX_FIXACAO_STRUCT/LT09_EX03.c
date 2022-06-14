#include "stdio.h"

/*
Nome:..... Gabriel Muniz
Turma:.... C_11
Enunciado: Faça um algoritmo que tenha um registro (estrutura) que represente um pokemon. 
O usuário deve digitar o nome, vida, ataque e defesa do pokemon. Em seguida, os dados devem ser apresentados.
*/

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
    Pokemon pokemon1;

    printf("Nome do Pokemon: ");
    gets(pokemon1.nome);
    printf("Vida: ");
    scanf("%d", &pokemon1.vida);
    __fpurge(stdin);
    printf("Ataque: ");
    scanf("%d", &pokemon1.ataque);
    printf("Defesa: ");
    scanf("%d", &pokemon1.defesa);

    mostrarPokemon(pokemon1);

    return 0;
}
