typedef struct contato{
	char nome[50], sobrenome[50], telefone[50], email[50];
	struct contato *prox;
}Contato;

typedef struct inicial{
	char letra;
	struct contato *listaDeContatos;
	struct inicial *prox;
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
void pedirDados(Contato *novo){
	printf("\tAGENDA DE CONTATOS > NOVO CONTATO\n\n");
	printf("NOME: ");
	fflush(stdin);
	gets(novo->nome);	
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
	mostrarContato(iniciais, toupper(letra));
	system("pause");
	system("cls");
}

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

//---------------------------------------------------------------------
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

Inicial *inserirNaListaDeIniciais(Contato *contato, Inicial *iniciais){
	Inicial *novo, *p, *k, *aux;
	Contato *contatos;
	contatos = NULL;
	char letra = toupper(contato->nome[0]);
	if(iniciais == NULL){
		novo=(Inicial*) malloc(sizeof(Inicial));
		novo->prox=NULL;
		novo->letra = letra;
				
		contatos = inserirNaListaDeContatos(contatos, contato);
		novo->listaDeContatos = contatos;
		return novo;
	}else{
		for(p=iniciais;p!=NULL;p=p->prox){
			if(letra == p->letra){
				contatos = inserirNaListaDeContatos(p->listaDeContatos, contato);
				return iniciais;
			}
		}
		for(k=iniciais;k->prox!=NULL;k=k->prox);
		novo = (Inicial*) malloc(sizeof(Inicial));
		novo->letra = letra;
		novo->prox= NULL;
		
		contatos = inserirNaListaDeContatos(contatos, contato);
		novo->listaDeContatos = contatos;
		
		k->prox = novo;
		return iniciais;
		/*
		for(p=iniciais;p->prox!=NULL;p=p->prox){
			if(letra == p->letra){
				contatos = inserirNaListaDeContatos(p->listaDeContatos, contato);
				return iniciais;
			}
		}
		for(k=iniciais;k->prox!=NULL;k=k->prox){
			if((letra) - (k->letra) == 1){
				novo=(Inicial*) malloc(sizeof(Inicial));
				novo->letra = letra;
				Contato *contatos;
				contatos = NULL;
				contatos = inserirNaListaDeContatos(contatos, contato);
				novo->listaDeContatos = contatos;
				
				novo->prox = k->prox;
				k->prox = novo;				
				return iniciais;
			}
		}
		*/
	}
}

remover(){
	
}
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

Favorito *favoritar(Inicial *iniciais, Favorito *favoritos){
	char nome[50];
	Contato *nomeExiste;
	while(1){
		printf("\tAGENDA DE CONTATOS > FAVORITAR\n\n");
		printf("QUAL O NOME DO CONTATO QUE DESEJA FAVORITAR: \n> ");
		fflush(stdin);
		gets(nome);
		nomeExiste = verificaNome(iniciais, nome);
		if(nomeExiste != NULL){
			favoritos = inserirNosFavoritos(favoritos, nomeExiste);
			return favoritos;
		}else{
			return favoritos;
		}
	}	
}

void mostrarFavoritos(Favorito *favoritos){
	printf("\tAGENDA DE CONTATOS > MOSTRAR FAVORITOS\n\n");
	if(favoritos == NULL){
		printf("A LISTA DE FAVORITOS ESTA VAZIA\n");
	}else{
		for(favoritos;favoritos!=NULL;favoritos=favoritos->prox){
			printf("\nNOME: ");
			puts(favoritos->contato->nome);
			printf("SOBRENOME: ");
			puts(favoritos->contato->sobrenome);
			printf("TELEFONE: ");
			puts(favoritos->contato->telefone);
			printf("E-MAIL: ");
			puts(favoritos->contato->email);
		}
	}
	printf("\n\n");
	system("pause");
	system("cls");
}
