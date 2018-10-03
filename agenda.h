typedef struct x{
	char nome[50], sobrenome[50], telefone[50], email[50];
	struct x *prox;
}x;

typedef struct y{
	char letra;
	struct x *listaDeContatos;
	struct y *prox;
}y;

void inserirContato(){
	//crio um novo contato
	x *novo;
	novo = (x*) malloc(sizeof(x));
	
	//peço os dados ao usuario
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
	
	//inserir elemento na lista da Inicial
	iniciais = insereInicial(iniciais, novo->nome[0]);
	
	system("pause");
	system("cls");
}

//INSERIR NO INICIO
y *insereInicial(y *listaDeIniciais, char letra){
	y *novo;
	novo = (y*) malloc(sizeof(y));
	novo->letra = letra;
	novo->prox = listaDeIniciais;
	return novo;
}

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
