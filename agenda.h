//---------------------controller(estrutura)------------------------------
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
	struct contatos *contato;
	struct favoritos *prox;
}Favoritos;

//-------------------------------view----------------------------------------
int menu(){
	int opcao;
	printf("1 - Inserir Contato\n\n");
	printf("2 - Remover Contato\n\n");
	printf("3 - Favoritar Contato\n\n");
	printf("4 - Mostrar Contatos\n\n");
	printf("Digite a opcao: ");
	scanf("%d", &opcao);
	return opcao;
}


Contato *pedirDados(Contato *novo){	
	printf("\tAGENDA DE CONTATOS > INSERIR NOVO CONTATO\n\n");
	printf("Nome: ");
	fflush(stdin);
	gets(novo->nome);
	printf("Sobrenome: ");
	gets(novo->sobrenome);
	printf("Telefone :");
	gets(novo->telefone);
	printf("E-mail: ");
	gets(novo->email);
	
	printf("\nDados Inseridos com sucesso\n");	
	system("pause");
	system("cls");
	
	return novo;
}
void mostrarIniciais(Inicial *iniciais){
	Inicial *p;
	char letra;
	printf("\tAGENDA DE CONTATOS\n");
	for(p=iniciais;p!=NULL;p=p->prox){
		printf("%c \n", p->letra);
	}
	printf("\n\n");
	printf("\nQUAL LETRA QUER CONFERIR?\n");
	scanf("%c", &letra);
	mostrarContato(iniciais, letra);
	system("pause");
}
void mostrarContato(Inicial *iniciais, char letra){
	Inicial *p;
	printf("%c", letra);
	for(p=iniciais;p->prox!=NULL;p=p->prox){
		if(p->letra == letra){
			exibeContatos(p->listaDeContatos);
		}
	}
}
void exibeContatos(Contato *contatos){
	Contato *p;
	for(p=contatos;p->prox!=NULL;p=p->prox){
		printf("Nome: ");
		puts(p->nome);
		printf("Sobrenome: ");
		puts(p->sobrenome);
		printf("Telefone: ");
		puts(p->telefone);
		printf("E-mail: ");
		puts(p->email);
	}
}
//-----------------------------------------------------------------
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
	char letra = contato->nome[0];
	if(iniciais == NULL){
		novo=(Inicial*) malloc(sizeof(Inicial));
		novo->prox=NULL;
		novo->letra = letra;
				
		contatos = inserirNaListaDeContatos(contatos, contato);
		novo->listaDeContatos = contatos;
		return novo;
	}else{
		for(p=iniciais;p->prox!=NULL;p=p->prox){
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
