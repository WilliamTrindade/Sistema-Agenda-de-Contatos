#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"agenda.h"

void main(){
	//crio a lista de Iniciais
	Inicial *iniciais;
	iniciais = NULL;
	
	while(1){
		printf("\tAGENDA DE CONTATOS\n\n");
		int opcao = menu();
		system("cls");
		switch(opcao){
			case 1:{
				Contato *novo;
				novo = (Contato*) malloc(sizeof(Contato));
				novo = pedirDados(novo);
				iniciais = inserirNaListaDeIniciais(novo, iniciais);
				break;
			}
			case 4:{
				mostrarIniciais(iniciais);
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
}
