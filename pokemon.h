#ifndef POKEMON_H
#define POKEMON_H
typedef struct {
    int numero;
    // mudar esse 20
    char nome[30];
    char tipo1[30];
    char tipo2[30];
    int total;
    int hp;
    int ataque;
    int defesa;
    int ataque_especial;
    int defesa_especial;
    int velocidade;
    int geracao;
    int lendario; // na verdade é bool aqui
    char cor[30];
    float altura;
    float peso;
    int taxa_captura;
    int proxima_evolucao;
    int pre_evolucao;

}Pokemon;
#endif