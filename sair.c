// programa que cuida das coisas que precisam ser feitas quando fecho o programa
/*

Ao sair do programa, todos os dados devem ser salvos em arquivos binários no HD e
1
recarregados novamente ao iniciar. Caso os arquivos não existam, eles devem ser
criados e uma mensagem de boas vindas deve ser apresentada ao usuário;

*/
#include <stdio.h>
#include <stdlib.h>
#include "mochila.h"
#include "pokedex.h"
#include "colecao.h"


void salva(Mochila* mochila, Colecao* colecao, Pokedex* pokedex){
    FILE *arq = fopen("mochila.dat","wb");
    if(arq == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);// 1 significa erro
    }// if
    fwrite(&mochila->pokemons_mochila, sizeof(int), 1, arq);
    fwrite(mochila->codigos_pokemon, sizeof(int), mochila->pokemons_mochila, arq);
    fclose(arq);

    arq = fopen("colecao.dat", "wb");
    if (arq == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);// 1 significa erro
    }
    fwrite(&colecao->capturados, sizeof(int), 1, arq);
    fwrite(colecao->codigo_capturados, sizeof(int), colecao->capturados, arq);
    fclose(arq);
    
    arq = fopen("pokedex.dat", "wb");
    if (arq == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);// 1 significa erro
    }
    for (int i = 0; i < pokedex->qtd_cadastrados; i++){
        fwrite(&pokedex->pokemons[i].numero, sizeof(int), 1, arq);
        fwrite(pokedex->pokemons[i].nome, sizeof(char), 30, arq);
        fwrite(pokedex->pokemons[i].tipo1, sizeof(char), 30, arq);
        fwrite(pokedex->pokemons[i].tipo2, sizeof(char), 30, arq);
        fwrite(&pokedex->pokemons[i].total, sizeof(int), 1, arq);
        fwrite(&pokedex->pokemons[i].hp, sizeof(int), 1, arq);
        fwrite(&pokedex->pokemons[i].ataque, sizeof(int), 1, arq);
        fwrite(&pokedex->pokemons[i].defesa, sizeof(int), 1, arq);
        fwrite(&pokedex->pokemons[i].ataque_especial, sizeof(int), 1, arq);
        fwrite(&pokedex->pokemons[i].defesa_especial, sizeof(int), 1, arq);
        fwrite(&pokedex->pokemons[i].velocidade, sizeof(int), 1, arq);
        fwrite(&pokedex->pokemons[i].geracao, sizeof(int), 1, arq);
        fwrite(&pokedex->pokemons[i].lendario, sizeof(int), 1, arq);
        fwrite(pokedex->pokemons[i].cor, sizeof(char), 30, arq);
        fwrite(&pokedex->pokemons[i].altura, sizeof(double), 1, arq);
        fwrite(&pokedex->pokemons[i].peso, sizeof(double), 1, arq);
        fwrite(&pokedex->pokemons[i].taxa_captura, sizeof(int), 1, arq);
        fwrite(&pokedex->pokemons[i].pre_evolucao, sizeof(int), 1, arq);
        fwrite(&pokedex->pokemons[i].proxima_evolucao, sizeof(int), 1, arq);
    }
    fclose(arq);
    // escrever aqui para salvar o arquivo da pokedex em binario

}
