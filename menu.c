#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "mochila.h"
#include "colecao.h"
#include "pokedex.h"


int intervalo(int a, int b){
    // fica pedindo o inteiro até que a <= x <= b;
    int x;
    scanf("%d", &x);
    while (!(a <= x && x <= b)){
        scanf("%d", &x);
    }
    return x;
}
// verificado
void menu_pokedex(Pokedex* pokedex){
    // (inserir/listar/pesquisar/alterar/exclui
    int qtd_opcoes = 5;
    printf("[1] inserir\n");
    printf("[2] listar\n");
    printf("[3] pesquisar\n");
    printf("[4] alterar\n");
    printf("[5] excluir\n");
    int opcao = intervalo(1, qtd_opcoes);
    int codigo_pokemon;
    

    switch (opcao){
    case 1:
    // preciso pegar o pokemon aqui dentro
        Pokemon pokemon;
        inserir_na_pokedex(&pokemon, pokedex);
        break;
    case 2:
        listar_na_pokedex(pokedex);
        break;
    case 3:
        printf("Digite cógido do pokemon: ");
        scanf("%d", &codigo_pokemon);
        pesquisar_na_pokedex(codigo_pokemon, pokedex);
        break;
    case 4:
        printf("Digite cógido do pokemon: ");
        scanf("%d", &codigo_pokemon);
        alterar_na_pokedex(codigo_pokemon, pokedex);
        break;
    case 5:
        printf("Digite cógido do pokemon: ");
        scanf("%d", &codigo_pokemon);
        excluir_na_pokedex(codigo_pokemon, pokedex);
        break;
    default:
        printf("Opção invalida\n");
        //perror("Opção inválida\n");
        break;
    }//switch

    return;
}

// verificado
void menu_colecao(Colecao* colecao, Pokedex* pokedex){
    int qtd_opcoes = 5;
    // remvoer inserir repetido
    printf("[1] inserir\n");
    printf("[2] listar\n");
    printf("[3] pesquisar\n");
    printf("[4] alterar\n");
    printf("[5] excluir\n");
    int opcao = intervalo(1, qtd_opcoes);
    int codigo_pokemon;

    switch (opcao){
    case 1:
        printf("Digite cógido do pokemon: ");
        scanf("%d", &codigo_pokemon);
        inserir_colecao(codigo_pokemon, colecao);
        break;
    case 2:
        listar_colecao(colecao, pokedex);
        break;
    case 3:
        printf("Digite cógido do pokemon: ");
        scanf("%d", &codigo_pokemon);
        pesquisar_colecao(codigo_pokemon, colecao);
        break;
    case 4:
        printf("Digite cógido do pokemon: ");
        scanf("%d", &codigo_pokemon);
        alterar_colecao(codigo_pokemon, colecao);
        break;
    case 5:
        printf("Digite cógido do pokemon: ");
        scanf("%d", &codigo_pokemon);
        excluir_colecao(codigo_pokemon, colecao);
        break;
    default:
        perror("Opção inválida\n");
        break;
    }//switch

    return;
}

int menu_mochila(Mochila* mochila){
    int qtd_opcoes = 2;
    printf("[1] mudar pokemon\n");
    printf("[2] ver pokemon\n");
    int opcao = intervalo(1, qtd_opcoes);
    return opcao;
}

int menu_principal(){
    int qtd_opcoes = 7;
    printf("[1] pokedex\n");
    printf("[2] colecao\n");
    printf("[3] mochila\n");
    printf("[4] exibir itens\n");
    printf("[5] batalha pokemon\n");
    printf("[6] salvar progresso\n");
    printf("[7] sair\n");
    int opcao = intervalo(1, qtd_opcoes);
    return opcao;
}