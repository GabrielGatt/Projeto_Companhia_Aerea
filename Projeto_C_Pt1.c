#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define max 2







/*

///////////////////////////////////////// STRUCTS //////////////////////////////////

*/

struct Piloto{
	int registroPiloto; 
	char dataNasc[10]; 
	int telefones[3]; 
	char nome[50]; 
	char sexo; 
	char cursoEspec[60]; 
	char emails[3][40]; 
};
struct Voo{
	int numero;
	float distancia;
	int tempoMedio;
	char cidadeOrigem[50];
	char cidadeDestino[50];
	char Aeronave[40];
	char Escalas[3][50];
};

struct Viagem{
	int numeroVoo; //FK de Voo
	int horaSaida;
	int horaChegada;
	struct Piloto piloto;
	char dataSaida[10];
	char dataChegada[10];
	char ocorrencias[100];
};


/*
/////////////////////////////////////FUNCOES
*/

int inserirPiloto(struct Piloto vet_piloto[], int *posicao){

	int i;

	printf("Entre com o codigo de registro do piloto:\n");
	scanf("%d", &vet_piloto[*posicao].registroPiloto);

	printf("Entre com o nome do piloto:\n");
	fflush(stdin);
	gets(vet_piloto[*posicao].nome);
	printf("Entre com o sexo do piloto (M ou F):\n");
	scanf("%c", &vet_piloto[*posicao].sexo);
	printf("Entre com a data de nascimento do piloto (dd/mm/aaaa):\n");
	fflush(stdin);
	gets(vet_piloto[*posicao].dataNasc);
	for(i=0; i<3; i++){
		printf("Entre com o telefone %d do piloto:\n", i);
		scanf("%d", &vet_piloto[*posicao].telefones[i]);

	}
	printf("Entre com a formacao especial do piloto:\n");
	fflush(stdin);
	gets(vet_piloto[*posicao].cursoEspec);
	for(i=0; i<3; i++){
		printf("Entre com o email %d do piloto:\n", i);
		gets(vet_piloto[*posicao].emails[i]);
	}
	(*posicao)++;
}

int exibirPilotos(struct Piloto vet_piloto[], int posicao){

	int i;
	
	for(i=0; i<posicao; i++){

		printf("Registro do piloto: %d \n",vet_piloto[i].registroPiloto);
		printf("Data de nascimento: %s \n",vet_piloto[i].dataNasc);
		printf("Telefones.........: %d \n",vet_piloto[i].telefones[0]);
		printf("nome..............: %s \n",vet_piloto[i].nome);
		printf("Sexo..............: %c \n",vet_piloto[i].sexo);
		printf("Especializacao....: %s \n",vet_piloto[i].cursoEspec);
		printf("Emails............: %s \n",vet_piloto[i].emails[0]);
		printf("\n =======================================================\n");

	}
}

main(){
	struct Piloto pilotos[max];
	struct Voo voos[max];
	struct Viagem viagens[max];
	int op, pos=0;
	setlocale(LC_ALL, "Portuguese");
	
	do{
		printf("MENU PRINCIPAL DO PROGRAMA\n");
		printf("Submenu de Pilotos...............1\n");
		printf("Submenu de Voos..................2\n");
		printf("Submenu de Viagens...............3\n");
		printf("Submenu de Relatorios............4\n");
		printf("Sair.............................5\n\n");
		printf("Digite sua opcao ==========> ");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				printf("Acessando submenu de Pilotos\n\n");
				printf("Inserindo Piloto na posicao %d:\n", pos);
				inserirPiloto(pilotos, &pos);
				break;
			case 2:
				printf("Acessando submenu de Voos\n\n");
				exibirPilotos(pilotos, pos);
				break;
			case 3:
				printf("Acessando submenu de Viagens\n\n");
				break;
			case 4:
				printf("Acessando submenu de Relatorios\n\n");
				break;
			default: printf("\nEncerrando o programa...");
		}
	}while(op>0 && op<5);
}
