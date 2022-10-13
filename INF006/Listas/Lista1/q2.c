/*Considere uma aplicação para armazenar os seguintes dados de uma pessoa em uma agenda de endereços:
nome, endereço e telefone. Especifique um TAD para armazenar os dados das pessoas e as operações
necessárias para inserir, consultar e excluir os dados das pessoas.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define tam 100

typedef struct{
	char nome[52];
	char endereco[52];
	char telefone[52]; // formato "9 9999 9999" sem os espaços
	int cadastrado;
}person;

int incluirPessoa(person pessoas[], int qtd);
int excluirPessoa(person pessoas[], int qtd);
void consultarPessoa(person pessoas[], int qtd);
int trueIndex(person pessoas[], int qtd);
void limparString(char string[]);

int main(){
	person pessoas[tam];
	int op, qtd = 0;
	
	do{
		system("clear");
		printf("%d\n\n", qtd);
		printf("1. Inserir\n2. Excluir\n3. Consultar\n");
		printf("(Digite 0 para fechar o programa)\n");
		scanf("%d", &op);
		getchar();

		switch(op){
			case 0: printf("\n\nFECHANDO O PROGRAMA"); return 0; break;
			case 1: qtd = incluirPessoa(pessoas, qtd); break;
			case 2: qtd = excluirPessoa(pessoas, qtd); break;
			case 3: consultarPessoa(pessoas, qtd); break;
			default: printf("\nOPCAO INVALIDA\n\n");
		}
	}while(op);
}

int incluirPessoa(person pessoas[], int qtd){
	system("clear");
	int index = trueIndex(pessoas, qtd);
	int i, count;
	
	printf("Digite o nome da pessoa: ");
	fgets(pessoas[index].nome, 52, stdin);
	limparString(pessoas[index].nome);

	printf("Digite o endereco da pessoa: ");
	fgets(pessoas[index].endereco, 52, stdin);
	limparString(pessoas[index].endereco);

	printf("Digite o telefone da pessoa: ");
	fgets(pessoas[index].telefone, 52, stdin);
	limparString(pessoas[index].telefone);
	
	pessoas[index].cadastrado = true;
	return ++qtd;
}

int excluirPessoa(person pessoas[], int qtd){
	char telefone[52];
	int existe, i, count;
	
	do{
		system("clear");
		existe = false;
		printf("Digite um telefone registrado: ");
		fgets(telefone, 52, stdin);
		limparString(telefone);

		for(i=0, count=0; count<qtd; i++){
			if(pessoas[i].cadastrado == true){
				if(strcmp(telefone, pessoas[i].telefone)==0){
					existe = true;
					break;
				}
				count++;
			}
			if(existe == true){
				break;
			}
		}
		if(existe == false){
			printf("\nPessoa nao encontrada\n");
			getchar();
		}
	}while(existe==false);

	pessoas[i].cadastrado = false;
	qtd--;
	getchar();
	
	return qtd;
}

void consultarPessoa(person pessoas[], int qtd){
	char telefone[52];
	int existe, i, count;
	
	do{
		system("clear");
		existe = false;
		printf("Digite um telefone registrado: ");
		fgets(telefone, 52, stdin);
		limparString(telefone);

		for(i=0, count=0; count<qtd; i++){
			if(pessoas[i].cadastrado == true){
				if(strcmp(telefone, pessoas[i].telefone)==0){
					existe = true;
					break;
				}
				count++;
			}
			if(existe == true){
				break;
			}
		}
		if(existe == false){
			printf("\nPessoa nao encontrada\n");
			getchar();
		}
	}while(existe==false);

	printf("\nNome da pessoa: %s", pessoas[i].nome);
	printf("\nEndereco da pessoa: %s", pessoas[i].endereco);
	printf("\nTelefone da pessoa: %s\n\n", pessoas[i].telefone);
	getchar();
}

int trueIndex(person pessoas[], int qtd){
	int index, count;

	for(index = 0, count = 0; count < qtd; index++){
		if(pessoas[index].cadastrado == false){
			return index;
		}
		else if(pessoas[index].cadastrado == true){
			count++;
		}
	}
	return index;
}

// Usada para retirar o '\n' após inserir uma string[] via fgets()
void limparString(char string[]){
	for(int i=0;string[i] != '\0';i++)
		if(string[i] == '\n')
			string[i] = '\0';
}