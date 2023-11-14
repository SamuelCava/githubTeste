/*
Nesta atividade os alunos deverão desenvolver um sistema que permita a um Mestre Pokémon
gerenciar: uma Pokédex contendo o catálogo de todos os pokémons conhecidos; uma coleção
contendo todos os pokémons que você possui e; sua mochila que possui os 6 pokémons que
ele pode carregar em uma batalha. O sistema deve ser desenvolvido utilizando a linguagem C e
os conceitos visto em sala de aula. A atividade deverá ser desenvolvida em trios
impreterivelmente.

◦ Deverá permitir visualizar os pokemons por Geração e tipo, navegando entre elas. Para
isso utilize cores, sons e sua criatividade.
◦ Deverá apresentar um menu inicial com as opções disponíveis. Caso necessário,
submenus. A interface deverá ser fácil e intuitiva, seja criativo, utilize cores e beeps :) .
Trate erros do usuário com mensagens e alertas;

◦ Caso os arquivos não existam, eles devem ser
criados e uma mensagem de boas vindas deve ser apresentada ao usuário;

◦ O sistema deverá exibir no menu uma opção de exportar ao dados das estruturas em
um arquivo texto no formato .CSV (separados por vírgula);


Observações sobre o código:
◦ O programa deverá acompanhar um arquivo makefile que permita as operações básicas
de make (compilação), clean (limpeza) e run (execução);


◦ Como parte do critério de avaliação, a qualidade do código-fonte do sistema será
avaliada. Organize seu programa em arquivos .c e .h, funções. Evite o uso de variáveis
globais. O código deverá estar comentado, edentado e com bons nomes de variáveis e
funções. Siga o padrão de documentação apresentado na disciplina (Doxygen).

*/




/*
◦
// string formatada

fscanf depois tudo fread fwrite
// deixar para fazer as alterações no hd no final
feito: struct pokemon
Deverá permitir cadastrar
(inserir/listar/pesquisar/alterar/excluir) os Pokémons disponíveis para serem capturados.
Essa relação deve aumentar e diminuir dinamicamente.

◦ Deverá apresentar um menu inicial com as opções disponíveis. Caso necessário,
submenus. A interface deverá ser fácil e intuitiva, seja criativo, utilize cores e beeps :) .
Trate erros do usuário com mensagens e alertas;


◦ 
◦ O sistema deverá exibir no menu uma opção de exportar ao dados das estruturas em
um arquivo texto no formato .CSV (separados por v

*/
// pokedex e colecao estão com nomes iguais
// escrever a chamada das funções dedpendendo do que foi escolhido no menu
// fclose(arq);
// free()
// pesquisar por geração
// exportar para csv no menu


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "menu.h"
#include "carrega.h"
#include "colecao.h"
#include "mochila.h"
#include "pokemon.h"
#include "sair.h"
#include "abre_arquivo.h"

int main(){
	Pokedex pokedex;
	Mochila mochila;
	Colecao colecao;
	// verifica se já existe o arquivo e se n existir cria a pokedex em binario
	carregar_csv();
	
	abre_colecao(&colecao);
	abre_mochila(&mochila);
	abre_pokedex(&pokedex);
	bool gameloop = true;
	while (gameloop){
		int opcao = menu_principal();
		switch (opcao){
		case 1:
			menu_pokedex(&pokedex);
			break;
		case 2:
			menu_colecao(&colecao, &pokedex);
			break;
		case 3:
			menu_mochila(&mochila);
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			// aqui salva o progresso
			
			break;
		case 7:
			gameloop = false;
			break;
		
	}
	salva(&mochila, &colecao, &pokedex);

    return 0;
}
