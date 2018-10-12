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
				printf("\tAGENDA DE CONTATOS > REMOVER\n");
				if(iniciais == NULL){
					printf("\nPRIMEIRO INSIRA CONTATOS! \n");
				}else{
					char nome[50];
					do{
						printf("DIGITE UM NOME : ");
						fflush(stdin);
						gets(nome);	
					}while(nomeJaExiste(iniciais, nome) != 1);
				
					//removo o contato da lista 
					//e removo dos favoritos caso existir
					iniciais = remover(iniciais, favoritos, nome);
					favoritos = removerFavoritoDosContatos(favoritos, nome);
				}
				system("pause");
				system("cls");
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
				favoritos = removerFavorito(favoritos);
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
