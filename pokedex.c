
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pokedex.h"



void inicia_pokedex(Pokedex* pokedex){
    pokedex->tamanho = 10;
    pokedex-> qtd_cadastrados = 0;
    pokedex->pokemons = (Pokemon*) calloc(pokedex->tamanho, sizeof(Pokemon));
    if (pokedex->pokemons == NULL){
        printf("memoria insuficiente\n");
        exit(1);
    }
    printf("iniciou\n");
}



void inserir_na_pokedex(Pokemon* pokemon, Pokedex* pokedex){
    for (int i = 0; i < pokedex->qtd_cadastrados; i++){
        if (pokedex->pokemons[i].numero == pokemon->numero){
            return;
            // nesse caso eu já tenho aquele pokemon cadastrado
        }
    }
    // verifico se preciso aumentar o tamanho do meu vetor
    if (pokedex->tamanho <= pokedex->qtd_cadastrados + 1){
        pokedex->tamanho += 10;
        pokedex->pokemons = realloc(pokedex->pokemons, pokedex->tamanho*sizeof(Pokemon));
    }
    pokedex->qtd_cadastrados++;
    // n posso uasr essa linha aqui
    pokedex->pokemons[pokedex->qtd_cadastrados-1].numero = pokemon->numero;
    strcpy(pokedex->pokemons[pokedex->qtd_cadastrados-1].nome, pokemon->nome);
    strcpy(pokedex->pokemons[pokedex->qtd_cadastrados-1].tipo1, pokemon->tipo1);
    strcpy(pokedex->pokemons[pokedex->qtd_cadastrados-1].tipo2, pokemon->tipo2);
    strcpy(pokedex->pokemons[pokedex->qtd_cadastrados-1].cor, pokemon->cor);
    //total ,hp  ,ataque ,defesa ,ataque_especial ,defesa_especial ,velocidade
    // ,geracao ,lendario ,cor     ,altura_m ,peso_kg ,taxa_captura
    //
    pokedex->pokemons[pokedex->qtd_cadastrados-1].total = pokemon->total;
    pokedex->pokemons[pokedex->qtd_cadastrados-1].hp = pokemon->hp;
    pokedex->pokemons[pokedex->qtd_cadastrados-1].ataque = pokemon->ataque;
    pokedex->pokemons[pokedex->qtd_cadastrados-1].defesa = pokemon->defesa;
    pokedex->pokemons[pokedex->qtd_cadastrados-1].ataque_especial = pokemon->ataque_especial;
    pokedex->pokemons[pokedex->qtd_cadastrados-1].defesa_especial = pokemon->defesa_especial;
    pokedex->pokemons[pokedex->qtd_cadastrados-1].velocidade = pokemon->velocidade;
    pokedex->pokemons[pokedex->qtd_cadastrados-1].geracao = pokemon->geracao;
    pokedex->pokemons[pokedex->qtd_cadastrados-1].lendario = pokemon->lendario;
    pokedex->pokemons[pokedex->qtd_cadastrados-1].altura = pokemon->altura;
    pokedex->pokemons[pokedex->qtd_cadastrados-1].peso = pokemon->peso;
    pokedex->pokemons[pokedex->qtd_cadastrados-1].taxa_captura = pokemon->taxa_captura;
    pokedex->pokemons[pokedex->qtd_cadastrados-1].pre_evolucao = pokemon->pre_evolucao;
    pokedex->pokemons[pokedex->qtd_cadastrados-1].proxima_evolucao = pokemon->proxima_evolucao;
    printf("inseriu 1\n");
    printf("pokemon:%s\n", pokemon->nome);
    printf("%d %d", pokedex->qtd_cadastrados, pokedex->tamanho);
}

void listar_na_pokedex(Pokedex* pokedex){
    for (int i = 0; i < pokedex->qtd_cadastrados; i++){
        // acho que eu quero pelo menos o nome do pokemon aqui
        // seria interessante usar outro arquivo pra cuidar dessas buscas, isso tbm é comum ao outro coisa la
        // da mochila
        // quando no ponto eu troco por -> não funciona
        printf("nome: %s", pokedex->pokemons[i].nome);
    }
}

void pesquisar_na_pokedex(int codigo, Pokedex* pokedex){
    for (int i = 0; i < pokedex->qtd_cadastrados; i++){
        if (pokedex->pokemons[i].numero == codigo){
            // achei ele
            printf("achei\n");
            printf("nome: %s\n", pokedex->pokemons[i].nome);
        }
    }
}


void alterar_na_pokedex(int codigo, Pokedex* pokedex){
    for (int i = 0; i < pokedex->qtd_cadastrados; i++){
        if (pokedex->pokemons[i].numero == codigo){
            // achei ele
            printf("achei");
        }
    }
}


void excluir_na_pokedex(int codigo, Pokedex* pokedex){
    for (int i = 0; i < pokedex->qtd_cadastrados; i++){
        if (pokedex->pokemons[i].numero == codigo){
            pokedex->qtd_cadastrados--;
            // seria interssante reescrever aqui os valores
            for (int l = i; l < pokedex->qtd_cadastrados; l++){
                //colecao[l] = colecao[l+1];
            }
            if (pokedex->tamanho - pokedex->qtd_cadastrados > 10){
                pokedex->tamanho -= 10;
                pokedex->pokemons = realloc(pokedex->pokemons, pokedex->tamanho*sizeof(Pokemon));
            }
            return;
        }
    }
    printf("pokemon não encontrado\n");
}