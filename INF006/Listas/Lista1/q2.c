/*Considere uma aplicação para armazenar os seguintes dados de uma pessoa em uma agenda de endereços:
nome, endereço e telefone. Especifique um TAD para armazenar os dados das pessoas e as operações
necessárias para inserir, consultar e excluir os dados das pessoas.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define tam 100

typedef struct{
	char nome[50];     // Mínimo 3 carateres, apenas letras e espaços(desde que não seja na primeira posição)
	char endereco[50]; // Mínimo 3 caracteres
	char telefone[10]; // Formato "9 9999 9999" sem os espaços
	int cadastrado;    // Organiza a exclusão lógica
}person;

int incluirPessoa(person pessoas[], int qtd);
int excluirPessoa(person pessoas[], int qtd);
void consultarPessoa(person pessoas[], int qtd);
int telefoneRepetido(person pessoas[], int qtd, char telefoneValidar[]);
int trueIndex(person pessoas[], int qtd);
int validarTelefone(person pessoas[], int index, int qtd, char telefone[]);
int validarNome(char validNome[]);
void limparString(char string[]);

int main(){
	person pessoas[tam];
	int op, qtd = 0;
	
	do{
		system("cls");
		printf("%d\n\n", qtd);
		printf("1. Inserir\n2. Excluir\n3. Consultar\n");
		printf("(Digite 0 para fechar o programa)\n");
		scanf("%d", &op);
		getchar();

		switch(op){
			case 0: printf("\n\nFECHANDO O PROGRAMA"); return 0; break;
			case 1: qtd = incluirPessoa(pessoas, qtd); break;
			case 2: if(qtd > 0){
				qtd = excluirPessoa(pessoas, qtd);
				}
				else{
					printf("\n(NAO HA PESSOAS CADASTRADAS)\n");
					getchar();
				} break;
			case 3: if(qtd > 0){
				consultarPessoa(pessoas, qtd);
				}
				else{
					printf("\n(NAO HA PESSOAS CADASTRADAS)\n");
					getchar();
				} break;
			default: printf("\nOPCAO INVALIDA\n\n");
		}
	}while(op);
}

int incluirPessoa(person pessoas[], int qtd){
	system("cls");
	int index = trueIndex(pessoas, qtd);
	int valido;
	
	do{
		valido = true;
		printf("Digite o nome da pessoa: ");
		fgets(pessoas[index].nome, 50, stdin);
		limparString(pessoas[index].nome);
		if(strlen(pessoas[index].nome) < 3){
			valido = false;
		}
		else{
			valido = validarNome(pessoas[index].nome);
		}
		if(valido == false){
			printf("\n(ENTRADA INVALIDA)\n");
		}
	}while(valido == false);
	if(pessoas[index].nome[0]>=97){
		pessoas[index].nome[0] -= 32;
	}

	do{
		valido = true;
		printf("Digite o endereco da pessoa: ");
		fgets(pessoas[index].endereco, 50, stdin);
		limparString(pessoas[index].endereco);
		if(strlen(pessoas[index].endereco) < 3){
			valido = false;
			printf("\n(ENTRADA INVALIDA)\n");
		}
	}while(valido == false);

	do{
		valido = true;
		printf("Digite o telefone da pessoa(Coloque o 9 na frente): ");
		fgets(pessoas[index].telefone, 10, stdin);
		limparString(pessoas[index].telefone);
		if(strlen(pessoas[index].telefone) != 9){
			valido = false;
		}
		else{
			valido = validarTelefone(pessoas, index, qtd, pessoas[index].telefone);
		}

		if(valido == false){
			printf("\n(ENTRADA INVALIDA)\n");
		}
	}while(valido == false);
	
	pessoas[index].cadastrado = true;
	return ++qtd;
}

int excluirPessoa(person pessoas[], int qtd){
	char telefone[10];
	int existe, i, count;
	
	do{
		system("cls");
		existe = false;
		printf("Digite um telefone registrado: ");
		fgets(telefone, 10, stdin);
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
	char telefone[10];
	int existe, i, count;
	
	do{
		system("cls");
		existe = false;
		printf("Digite um telefone registrado: ");
		fgets(telefone, 10, stdin);
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

int validarTelefone(person pessoas[], int index, int qtd, char telefone[]){
	if(telefone[0]!='9'){
		return false;
	}
	for(int i = 0; telefone[i] != '\0'; i++){
		if(telefone[i] < 48 || telefone[i] > 57){
			return false;
		}
	}
	if(qtd>0){
		return telefoneRepetido(pessoas, qtd, telefone);
	}
	return true;
}

int telefoneRepetido(person pessoas[], int qtd, char telefoneValidar[]){
	for(int i = 0, count = 0; count < qtd; i++){
		if(pessoas[i].cadastrado == true){
			if(strcmp(pessoas[i].telefone, telefoneValidar) == 0){
				return false;
			}
			count++;
		}
	}
	return true;
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

//****************** Checa se há caracteres além de letras e espaços na string
int validarNome(char validNome[]){
  // checando se o primeiro caracter é um espaço
  if(validNome[0]==32)
    return true;
  else for(int i=0;validNome[i]!='\0';i++)
    if(validNome[i]!=32 && (validNome[i]>90 || validNome[i]<65))
      return true;

  return false;
}