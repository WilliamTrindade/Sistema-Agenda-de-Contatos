#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"agenda.h"

int main(){
	Inicial *iniciais;
	iniciais = NULL;
	
	Favorito *favoritos;
	favoritos = NULL;
	while(1){
		printf("\tAGENDA DE CONTATOS\n\n");
		int opcao = menu();
		system("cls");
		switch(opcao){
			case 1:{
				Contato *novo;
				novo = (Contato*) malloc(sizeof(Contato));
				pedirDados(iniciais, novo);
				iniciais = inserirNaListaDeIniciais(iniciais, novo);
				break;
			}
			case 2:{
				//remover();
				break;
			}
			case 3:{
				mostrarTodos(iniciais);
				break;
			}
			case 4:{
				mostrarIniciais(iniciais);
				break;
			}
			case 5:{
				favoritos = favoritar(iniciais, favoritos);
				break;
			}
			case 6:{
				mostrarFavoritos(favoritos);
				break;
			}
			case 7:{
				//emoverFavoritos();
				break;
			}
			case 8:{
				return 0;
				break;
			}
			default:{
				printf (" \nValor invalido! \n\n");
				system("pause");
				system("cls");
				break;
			}
		}
	}
	return 0;	
}
