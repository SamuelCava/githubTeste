// arquivo responsavel em carregar as coisas quando entrar no jogo
/*
◦ A lista com os dados iniciais para o Pokédex será construída lendo os dados de um
arquivo .csv (valores separados por vírgula) disponibilizado que deve ser lido e
carregado em um vetor de tamanho dinâmico na primeira abertura do programa.
*/

/*
Abrir o arquivo.csv, reconhecer o seu tamanho, alocar memória e salvar em binário
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carrega.h"

void remove_espaco(char* s){
    int indice_espaco = 0;
    for (int i = 0; i < 30; i++){
        if (s[i] == ' '){
            indice_espaco = i;
            break;
        }
    }
    s[indice_espaco] = '\0';
}



void carregar_csv(){ 
    // o problema aqui é que ainda n pega o tamanho do arquivo csv
    // preciso tbm remover os espaços extras das strings
    FILE *arquivo;
    arquivo = fopen("pokedex.csv", "r");
    FILE *arqBinario;
    arqBinario = fopen("pokedex.dat", "wb");
    if (arquivo == NULL || arqBinario == NULL){
        perror("Erro para abrir o arquivo.");      
        exit(1);   
    }
    char campo[30];
    // cada pokemon tem 17 coisas
    int campos = 17;
    int campo_atual = 0;
    int linha = 0;
    int campos_double[2] = {14, 15};
    int campos_str[4] = {1, 2, 3, 13};
    while (fscanf(arquivo, "%[^,\n]%*c", campo)!=EOF){
        //printf("campo%d", campo_atual);
        //printf("%s\n", campo);
        // verifica se é string
        // vamos pular a primeira linha
        //printf("item: %s\n", campo);
        // 1, 2, 3, 13-> string
        // 14, 15 -> double
        // e o resto dos campos são int
        int is_str = 0;
        for (int i = 0; i < 4; i++){
            if (campo_atual == campos_str[i]){
                remove_espaco(&campo);
                printf("-%s-\n", campo);
                fwrite(campo, sizeof(char), 30, arqBinario);
                is_str = 1;
            }
        }
        if (is_str == 0){
            double valor = atof(campo);
            //printf("valor: %f\n", valor);
            if (campo_atual == 14 || campo_atual == 15){
                fwrite(&valor, sizeof(double), 1, arqBinario);

            }else{
                int valor_inteiro = atoi(campo);
                fwrite(&valor_inteiro, sizeof(int), 1, arqBinario);
            }
            
        }
        
        campo_atual++;
        if (campo_atual == campos){
            int prox_ev = 0;
            int pre_ev = 0;
            fwrite(&prox_ev, sizeof(int), 1, arqBinario);
            fwrite(&pre_ev, sizeof(int), 1, arqBinario);
            campo_atual = 0;
            linha++;
        }
        
    }
    fclose(arqBinario);
    fclose(arquivo);
    
}

int main(){
    carregar_csv();
    return 0;
}
