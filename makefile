# Arquivo para compilar o projeto em ordem decrescente de dependências

main: main.o abre_arquivo.o carrega.o colecao.o menu.o mochila.o pokedex.o pokemon.o sair.o
	@echo "Gerando arquivo executável"
	gcc main.o abre_arquivo.o carrega.o colecao.o menu.o mochila.o pokedex.o pokemon.o sair.o -o main

main.o: main.c abre_arquivo.c menu.c sair.c colecao.c mochila.c pokedex.c carrega.c 
	@echo "Compilando e gerando objeto main"
	gcc -c main.c abre_arquivo.c menu.c sair.c colecao.c mochila.c pokedex.c carrega.c 

abre_arquivo.o: abre_arquivo.c colecao.c mochila.c pokedex.c carrega.c pokemon.c
	@echo "Compilando e gerando objeto abre_arquivo"
	gcc -c abre_arquivo.c colecao.c mochila.c pokedex.c carrega.c pokemon.c

menu.o: menu.c colecao.c mochila.c pokedex.c 
	@echo "Compilando e gerando objeto menu"
	gcc -c menu.c colecao.c mochila.c pokedex.c
	
sair.o: sair.c colecao.c mochila.c pokedex.c 
	@echo "Compilando e gerando objeto sair"
	gcc -c sair.c colecao.c mochila.c pokedex.c
	
colecao.o: colecao.c pokedex.c
	@echo "Compilando e gerando objeto colecao"
	gcc -c colecao.c pokedex.c

mochila.o: mochila.c
	@echo "Compilando e gerando objeto mochila"
	gcc -c mochila.c
	
pokedex.o: pokedex.c
	@echo "Compilando e gerando objeto pokedex"
	gcc -c pokedex.c
		
carrega.o: carrega.c
	@echo "Compilando e gerando objeto carrega"
	gcc -c carrega.c

pokemon.o: pokemon.c
	@echo "Compilando e gerando objeto pokemon"
	gcc -c pokemon.c
	
clean:
	@echo "Apagando os objetos antigos EXCETO os que salvam os dados registrados."
	rm -f main.o abre_arquivo.o carrega.o menu.o  main
#colecao.o mochila.o pokedex.o pokemon.o sair.o ENDEREÇAMENTO DE ARQUIVOS BINÁRIOS QUE NÃO PODEM SER APAGADOS

run:
	./main