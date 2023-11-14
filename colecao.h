#ifndef COLECAO_H
#define COLECAO_H
#include "pokedex.h"
typedef struct{
    int capturados;
    // tamanho representa o espaço de quantos int tenho pra usar
    int tamanho;
    int *codigo_capturados;
}Colecao;


void inicia_colecao(Colecao* colecao);
void inserir_colecao(int codigo, Colecao* colecao);
void listar_colecao(Colecao* colecao, Pokedex* pokedex);
void pesquisar_colecao(int codigo, Colecao* colecao);
void alterar_colecao(int codigo, Colecao* colecao);
void excluir_colecao(int codigo, Colecao* colecao);
#endif