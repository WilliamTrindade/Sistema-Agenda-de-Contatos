#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"agenda.h"

void main(){
	y *iniciais;
	iniciais = NULL;
	while(1){
		printf("\tAGENDA DE CONTATOS\n\n");
		int opcao = menu();
		system("cls");
		switch(opcao){
			case 1:{
				inserirContato();
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
