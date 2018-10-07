//ESTRUTURA
typedef struct contato{
	char nome[50], sobrenome[50], telefone[50], email[50];
	struct contato *prox;
}Contato;

typedef struct inicial{
	char letra;
	struct contato *listaDeContatos;
	struct inicial *prox;
	struct favorito *fav;
}Inicial;

typedef struct favorito{
	struct contato *contato;
	struct favorito *prox;
}Favorito;

//EXIBIR O MENU 
int menu(){
	int opcao;
	printf("1 - INSERIR\n\n");
	printf("2 - REMOVER\n\n");
	printf("3 - MOSTRAR TODOS\n\n");
	printf("4 - MOSTRAR INICIAIS\n\n");
	printf("5 - FAVORITAR\n\n");
	printf("6 - MOSTRAR FAVORITOS\n\n");
	printf("7 - REMOVER FAVORITO\n\n");
	printf("8 - SAIR\n\n> ");
	scanf("%d", &opcao);
	return opcao;
}

//PEDIR OS DADOS AO USER
void pedirDados(Inicial *iniciais, Contato *novo){
	printf("\tAGENDA DE CONTATOS > NOVO CONTATO\n\n");
	//IMPEDE QUE O USUARIO DIGITE 2 NOMES IGUAIS
	do{
		printf("NOME: ");
		fflush(stdin);
		gets(novo->nome);	
	}while(nomeJaExiste(iniciais, novo->nome) == 1);
	printf("SOBRENOME: ");
	gets(novo->sobrenome);
	printf("TELEFONE :");
	gets(novo->telefone);
	printf("E-MAIL: ");
	gets(novo->email);
	
	printf("\n\nDADOS INSERIDOS COM SUCESSO! \n\n");	
	system("pause");
	system("cls");
}

//MOSTRAR UMA LISTA DE CONTATOS
void exibeContatos(Contato *contatos){
	Contato *p;
	for(p=contatos;p!=NULL;p=p->prox){
		printf("\nNOME: ");
		puts(p->nome);
		printf("SOBRENOME: ");
		puts(p->sobrenome);
		printf("TELEFONE: ");
		puts(p->telefone);
		printf("E-MAIL: ");
		puts(p->email);
	}
}

int nomeJaExiste(Inicial *iniciais, char nome[50]){
	char letra = toupper(nome[0]);
	Inicial *p;
	Contato *k;
	for(p=iniciais;p!=NULL;p=p->prox){
		if(letra == p->letra){
			for(k=p->listaDeContatos;k!=NULL;k=k->prox){
				if(strcmp(nome, k->nome) == 0){
					return 1;
				}
			}
		}
	}
	return 0;
}

//PROCURA A INICIAL
void mostrarContato(Inicial *iniciais,char letra){
	Inicial *p;
	int letraExiste = 0;
	printf("\tAGENDA DE CONTATOS > CONTATOS > LETRA %c\n", letra);
	for(p=iniciais;p!=NULL;p=p->prox){
		if(letra == p->letra){
			letraExiste = 1;
			//CHAMA A FUNÇÃO PARA MOSTRAR OS CONTATOS DA INICIAL ENCONTRADA
			exibeContatos(p->listaDeContatos);
		}
	}
	if(letraExiste == 0){
		printf("\nESSA INICIAL NAO EXISTE\n\n");
	}
}

//MOSTRA AS INICIAIS
void mostrarIniciais(Inicial *iniciais){
	Inicial *p;
	char letra;
	printf("\tAGENDA DE CONTATOS > CONTATOS > \nINICIAIAS:\n");
	for(p=iniciais;p!=NULL;p=p->prox){
		printf("%c \n", p->letra);
	}
	printf("\nQUAL LETRA QUER CONFERIR?\n");
	fflush(stdin);
	scanf("%c", &letra);
	system("cls");
	//MOSTRA OS CONTATOS DA INICIAL
	mostrarContato(iniciais, toupper(letra));
	system("pause");
	system("cls");
}

//MOSTRA TODOS OS CONTATOS
void mostrarTodos(Inicial *iniciais){
	Inicial *p;
	Contato *k;
	printf("\tAGENDA DE CONTATOS > MOSTRAR TODOS\n");
	for(p=iniciais;p!=NULL;p=p->prox){
		printf("\n> %c", toupper(p->letra));
		exibeContatos(p->listaDeContatos);
	}
	system("pause");
	system("cls");
}

//INSERIR NOVO CONTATO
Contato *inserirNaListaDeContatos(Contato *contatos, Contato *contato){
	Contato *novo;
	Contato *p;
	if(contatos == NULL){
		novo=(Contato*) malloc(sizeof(Contato));
		novo=contato;
		novo->prox=NULL;
		return novo;
	}else{
		for(p=contatos;p->prox!=NULL;p=p->prox);
		novo = (Contato*) malloc(sizeof(Contato));
		novo = contato;
		novo -> prox = NULL;
		p->prox = novo;
		return contatos;
	}
}

//INSERIR UMA INICIAL DE FORMA ORDENADA
Inicial *inserirNaListaDeIniciais(Inicial *iniciais, Contato *contato){
	Inicial *novo, *p, *k, *aux;
	Contato *contatos;
	contatos = NULL;
	char letra = toupper(contato->nome[0]);
	
	//SE A LISTA DE INICIAIS FOR NULA
	if(iniciais == NULL){		
		//ALOCA O ESPACO PARA O CONTATO SER INSERIDO
		novo=(Inicial*) malloc(sizeof(Inicial));
		novo->prox=NULL;
		novo->letra = letra;	
			
		contatos = inserirNaListaDeContatos(contatos, contato);
		novo->listaDeContatos = contatos;
		return novo;
	}
	//SE A LETRA FOR MENOR QUE O CABECA DA LISTA
	else if(letra < iniciais->letra){	
		//ALOCA O ESPACO PARA O CONTATO SER INSERIDO
		novo=(Inicial*) malloc(sizeof(Inicial));
		novo->letra = letra;
		novo->prox = iniciais;
		contatos = inserirNaListaDeContatos(contatos, contato);
		novo->listaDeContatos = contatos;
		return novo;
	}
	
	//PERCORRE A LISTA
	//SE A LETRA JA EXISTIR
	for(p=iniciais;p!=NULL;p=p->prox){
		if(p->letra == letra){
			//ALOCA O ESPACO PARA O CONTATO SER INSERIDO
			novo=(Inicial*) malloc(sizeof(Inicial));
			novo->prox=NULL;
			novo->letra = letra;
	
			//INSERE O CONTATO NA LISTA DA LETRA					
			p->listaDeContatos = inserirNaListaDeContatos(p->listaDeContatos, contato);
			//RETORNA A CABECA
			return iniciais;
		}
	}
	//PERCORRE DENOVO
	//INSERE NO MEIO
	for(p=iniciais;p->prox!= NULL;p=p->prox){
		//VERIFICA
		if(p->prox->letra > letra){
			//ALOCA O ESPACO PARA O CONTATO SER INSERIDO
			novo=(Inicial*) malloc(sizeof(Inicial));
			novo->letra = letra;
			
			//INSERE O CONTATO NA LISTA DA LETRA
			novo->prox = p->prox;
			p->prox = novo;
			contatos = inserirNaListaDeContatos(contatos, contato);
			novo->listaDeContatos = contatos;
			return iniciais;
		}			
	}
	//INSERE NO FINAL
	if(p->prox == NULL){
		//ALOCA O ESPACO PARA O CONTATO SER INSERIDO
		novo=(Inicial*) malloc(sizeof(Inicial));
		novo->letra = letra;
		
		//INSERE O CONTATO NA LISTA DA LETRA
		novo->prox = NULL;
		p->prox = novo;
		contatos = inserirNaListaDeContatos(contatos, contato);
		novo->listaDeContatos = contatos;
		return iniciais;
	}		
}

//REMOVER LETRA
Inicial *removerInicial(Inicial *iniciais, char letra){
	Contato *c;
	Inicial *i;
	Inicial *ant;
	Inicial *rem;
	
	letra = toupper(letra);
	for(i=iniciais;i!=NULL;i=i->prox){
		//verifica o proximo para preservar o anterior
		if(i->prox->letra == letra){
			rem = i->prox;
			ant = i;
			ant->prox = rem->prox;
			free(rem);
			return iniciais;
		}
		
		//so entra na primeira letra
		if(i->letra == letra){
			//se for a primeira letra
			if(i->letra == letra && iniciais->letra == letra){
				Inicial *novaCabeca;
				novaCabeca = i->prox;
				free(i);
				return novaCabeca;
			}
		}
	}
}

//INSERE FAVORITOS
Favorito *inserirNosFavoritos(Favorito *favoritos, Contato *contato){
	Favorito *novo;
	Favorito *p;
	
	novo=(Favorito*) malloc(sizeof(Favorito));
	novo->prox=NULL;
	novo->contato =  contato;
		
	if(favoritos==NULL){		
		//mensagem de sucesso
		printf("\nCONTATO ADICIONADO COM SUCESSO! ");
		printf("\nNOME: ");
		puts(novo->contato->nome);
		printf("SOBRENOME: ");
		puts(novo->contato->sobrenome);
		printf("TELEFONE: ");
		puts(novo->contato->telefone);
		printf("E-MAIL: ");
		puts(novo->contato->email);
		printf("\n");
		system("pause");
		system("cls");
		return novo;
	}
	
	for(p=favoritos;p->prox!=NULL;p=p->prox);
	
	p->prox = novo;
	
	//mensagem de sucesso
	printf("\nCONTATO ADICIONADO COM SUCESSO! ");
	printf("\nNOME: ");
	puts(novo->contato->nome);
	printf("SOBRENOME: ");
	puts(novo->contato->sobrenome);
	printf("TELEFONE: ");
	puts(novo->contato->telefone);
	printf("E-MAIL: ");
	puts(novo->contato->email);
	printf("\n");
	system("pause");
	system("cls");
	return favoritos;
}

//VERIFICA SE O NOME EXISTE
Contato *verificaNome(Inicial *iniciais, char nome[50]){
	char letra = toupper(nome[0]);
	Inicial *p;
	Contato *k;
	for(p=iniciais;p!=NULL;p=p->prox){
		if(letra == p->letra){
			for(k=p->listaDeContatos;k!=NULL;k=k->prox){
				if(strcmp(nome, k->nome) == 0){
					return k;
				}
			}
		}
	}
	printf("\nNOME NAO EXISTE! \n");
	system("pause");
	system("cls");
	return NULL;
}

//FAVORITAR UM CONTATO
Favorito *favoritar(Inicial *iniciais, Favorito *favoritos){
	char nome[50];
	Contato *nomeExiste;
	while(1){
		printf("\tAGENDA DE CONTATOS > FAVORITAR\n\n");
		printf("QUAL O NOME DO CONTATO QUE DESEJA FAVORITAR: \n> ");
		fflush(stdin);
		gets(nome);
		if(favoritoExiste(favoritos, nome) == 1){
			printf("\nESSE CONTATO JA ESTA NA LISTA SORRY!\n\n");
			system("pause");
			system("cls");
			return favoritos;
		}
		nomeExiste = verificaNome(iniciais, nome);
		if(nomeExiste != NULL){
			favoritos = inserirNosFavoritos(favoritos, nomeExiste);
			return favoritos;
		}else{
			return favoritos;
		}
	}	
}

//MOSTRA OS FAVORITOS
void mostrarFavoritos(Favorito *favoritos){
	Favorito *f;
	printf("\tAGENDA DE CONTATOS > MOSTRAR FAVORITOS\n\n");
	if(favoritos == NULL){
		printf("A LISTA DE FAVORITOS ESTA VAZIA\n\n");
		system("pause");
		system("cls");
		return;
	}else{
		f = favoritos;
		if(f->prox == NULL){
			printf("\nNOME: ");
			puts(f->contato->nome);
			printf("SOBRENOME: ");
			puts(f->contato->sobrenome);
			printf("TELEFONE: ");
			puts(f->contato->telefone);
			printf("E-MAIL: ");
			puts(f->contato->email);
		}else{
			for(f=favoritos;f!=NULL;f=f->prox){
				printf("\nNOME: ");
				puts(f->contato->nome);
				printf("SOBRENOME: ");
				puts(f->contato->sobrenome);
				printf("TELEFONE: ");
				puts(f->contato->telefone);
				printf("E-MAIL: ");
				puts(f->contato->email);
			}
		}
		
	}
	printf("\n\n");
	system("pause");
	system("cls");
}

//VERIFICA SE O NOME CONSTA NO FAVORITOS
int favoritoExiste(Favorito *favoritos, char nome[50]){
	Favorito *f;
	for(f=favoritos;f!=NULL;f=f->prox){
		if(strcmp(f->contato->nome, nome) == 0){
			return 1;
		}
	}
	return 0;
}

//REMOVER FAVORITO
Favorito *removerFavorito(Favorito *favoritos){
	Favorito *f;
	Favorito *retirar;
	Favorito *anterior;
	char nome[50];
	printf("\tAGENDA DE CONTATOS > REMOVER FAVORITO\n\n");
	if(favoritos == NULL){
		printf("\nA LISTA DE FAVORITOS ESTA VAZIA!\n\n");
		system("pause");
		system("cls");
		return favoritos;
	}else{
		printf("DIGITE O NOME: ");
		fflush(stdin);
		gets(nome);	
		if(favoritoExiste(favoritos, nome) == 1){		
			//SE QUISER REMOVER A CABECA DA LISTA
			f = favoritos;
			if(strcmp(f->contato->nome, nome) == 0){
				Favorito *novoCabeca;
				novoCabeca = f->prox;
				free(f);
				printf("\nFAVORITO REMOVIDO COM SUCESSO\n\n");
				system("pause");
				system("cls");
				return novoCabeca;
			}
			//SE SO EXISTE UM VALOR NA LISTA
			f = favoritos;
			if(f->prox==NULL){
				printf("\nFAVORITO REMOVIDO COM SUCESSO\n\n");
				system("pause");
				system("cls");
				return NULL;
			}else{
				//ECNCONTRO O INDICE A SER RETIRADO
				for(f=favoritos;f->prox!=NULL;f=f->prox){
					if(strcmp(f->prox->contato->nome, nome) == 0){
						retirar = f->prox;
						anterior = f;
						anterior->prox = retirar->prox;
						free(retirar);
						printf("\nFAVORITO REMOVIDO COM SUCESSO\n\n");
						system("pause");
						system("cls");
						return favoritos;
					}
				}
			}
		}
		//SE O NOME NAO EXISTE NA LISTA
		else{
			printf("\nNOME NAO EXISTE! \n");
			system("pause");
			system("cls");
			return favoritos;	
		}
	}
}

//REMOVER FAVORITO DOS CONTATOS
Favorito *removerFavoritoDosContatos(Favorito *favoritos, char nome[50]){
	Favorito *f;
	Favorito *retirar;
	Favorito *anterior;
	if(favoritos == NULL){
		printf("\nA LISTA DE FAVORITOS ESTA VAZIA!\n\n");
		return favoritos;
	}else{
		if(favoritoExiste(favoritos, nome) == 1){		
			//SE QUISER REMOVER A CABECA DA LISTA
			f = favoritos;
			if(strcmp(f->contato->nome, nome) == 0){
				Favorito *novoCabeca;
				novoCabeca = f->prox;
				free(f);
				printf("\nFAVORITO REMOVIDO COM SUCESSO\n\n");
				return novoCabeca;
			}
			//SE SO EXISTE UM VALOR NA LISTA
			f = favoritos;
			if(f->prox==NULL){
				printf("\nFAVORITO REMOVIDO COM SUCESSO\n\n");
				return NULL;
			}else{
				//ECNCONTRO O INDICE A SER RETIRADO
				for(f=favoritos;f->prox!=NULL;f=f->prox){
					if(strcmp(f->prox->contato->nome, nome) == 0){
						retirar = f->prox;
						anterior = f;
						anterior->prox = retirar->prox;
						free(retirar);
						printf("\nFAVORITO REMOVIDO COM SUCESSO\n\n");
						return favoritos;
					}
				}
			}
		}
		//SE O NOME NAO EXISTE NA LISTA
		else{
			return favoritos;	
		}
	}
}

//REMOVER CONTATO
Inicial *remover(Inicial *iniciais, Favorito *favoritos, char nome[50]){
	Inicial *i;
	i = iniciais;
	Contato *c;
	Inicial *iAnt;
	Inicial *iRem;
	Contato *cAnt;
	Contato *cRem;
	char letra;
	if(iniciais == NULL){
		printf("\nPRIMEIRO INSIRA CONTATOS! \n");
		system("pause");
		system("cls");
		return NULL;
	}else{
		letra = toupper(nome[0]);
		
		//se so existe uma inicial e um contato
		if(iniciais->listaDeContatos->prox == NULL && iniciais->prox == NULL){
			printf("\nAGORA A LISTA DE LETRAS ESTA VAZIA \nCONTATO REMOVIDO COM SUCESSO! \n");
			system("pause");
			system("cls");
			return NULL;
		}
		
		//procura a inicial
		while(i != NULL && i->letra != letra){
			iAnt = i;
			i = i -> prox;
		}
		 
		//se so existe um contato na lista da inicial apaga apenas uma inicial
		if(i->listaDeContatos->prox == NULL){
			printf("\nNAO EXISTEM MAIS CONTATOS NA LETRA %c\nCONTATO REMOVIDO COM SUCESSO! \n", letra);
			system("pause");
			system("cls");
			iniciais = removerInicial(iniciais, letra);
			return iniciais;
		}
		
		//procura o contato na lista
		c = i->listaDeContatos;
		while(c != NULL && strcmp(c->nome, nome) != 0){
			cAnt = c;
			c=c->prox;
		}
		printf("\nCONTATO REMOVIDO COM SUCESSO! \n");
		system("pause");
		system("cls");
		cAnt->prox = c->prox;
		free(c);
		return iniciais;
	}
}

