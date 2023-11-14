#ifndef MENU_H
#define MENU_H
#include "mochila.h"
#include "colecao.h"
#include "pokedex.h"
int menu_principal();
int menu_mochila(Mochila* mochila);
void menu_colecao(Colecao* colecao, Pokedex* pokedex);
void menu_pokedex(Pokedex* pokedex);
#endif