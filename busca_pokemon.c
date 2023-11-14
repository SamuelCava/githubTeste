/*
◦ Deverá permitir visualizar os pokemons por Geração e tipo, navegando entre elas. 
Para isso utilize cores, sons e sua criatividade.
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "busca_pokemon.h"

void busca_geracao(int geracao, Pokedex* pokedex){
    for (int i = 0; i < pokedex->qtd_cadastrados; i++){
        if (pokedex->pokemons[i].geracao == geracao){
            printf("%s é da %dº geração\n", pokedex->pokemons[i].nome, geracao);
        }
    }
}

void busca_tipo(char tipo[30], Pokedex* pokedex){
    // pra essa função funcionar eu preciso garantir que 
    // os espaços já foram retirados;
    for (int i = 0; i < pokedex->qtd_cadastrados; i++){
        if (strcmp(pokedex->pokemons[i].tipo1, tipo) == 0 || strcmp(pokedex->pokemons[i].tipo2, tipo) == 0){
            printf("%s é do tipo %s\n", pokedex->pokemons[i].nome, tipo);
        }
    }
}