/*Considere uma aplicação para armazenar os seguintes dados de carros para uma garagem: placa,
marca/modelo e cor. Especifique um TAD para armazenar os dados dos carros e as operações necessárias para inserir,
consultar e excluir os dados das pessoas.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define tam 100

typedef struct{
	char placa[10];
	char marca[10];
	char cor[10];
	int cadastrado;
}carros;

int incluirCarro(carros carros[], int qtd);
int excluirCarro(carros carros[], int qtd);
void consultarCarro(carros carros[], int qtd);
int trueIndex(carros garagem[], int qtd);
void limparString(char string[]);

int main(){
	carros garagem[tam];
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
			case 1: qtd = incluirCarro(garagem, qtd); break;
			case 2: qtd = excluirCarro(garagem, qtd); break;
			case 3: consultarCarro(garagem, qtd); break;
			default: printf("\nOPCAO INVALIDA\n\n");
		}
	}while(op);
}

int incluirCarro(carros garagem[], int qtd){
	system("cls");
	int index = trueIndex(garagem, qtd);

	printf("Digite a placa do carro: ");
	fgets(garagem[index].placa, 10, stdin);
	limparString(garagem[index].placa);

	printf("Digite a marca do carro: ");
	fgets(garagem[index].marca, 10, stdin);
	limparString(garagem[index].marca);

	printf("Digite a cor do carro: ");
	fgets(garagem[index].cor, 10, stdin);
	limparString(garagem[index].cor);
	
	garagem[index].cadastrado = true;
	return ++qtd;
}

int excluirCarro(carros garagem[], int qtd){
	char placa[10];
	int existe, i, count;
	
	do{
		system("cls");
		existe = false;
		printf("Digite uma placa registrada: ");
		fgets(placa, 10, stdin);
		limparString(placa);

		for(i=0, count=0; count<qtd; i++){
			if(garagem[i].cadastrado == true){
				if(strcmp(placa, garagem[i].placa)==0){
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
			printf("\nCarro nao encontrado\n");
			getchar();
		}
	}while(existe==false);

	garagem[i].cadastrado = false;
	qtd--;
    printf("\n(Carro de placa %s excluido)");
	getchar();
	
	return qtd;
}

void consultarCarro(carros garagem[], int qtd){
	char placa[10];
	int existe, i, count;
	
	do{
		system("cls");
		existe = false;
		printf("Digite uma placa registrada: ");
		fgets(placa, 10, stdin);
		limparString(placa);

		for(i=0, count=0; count<qtd; i++){
			if(garagem[i].cadastrado == true){
				if(strcmp(placa, garagem[i].placa)==0){
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
			printf("\nCarro nao encontrado\n");
			getchar();
		}
	}while(existe==false);

	printf("\nPlaca do carro: %s", garagem[i].placa);
	printf("\nMarca do carro: %s", garagem[i].marca);
	printf("\nCor do carro: %s\n\n", garagem[i].cor);
	getchar();
}

int trueIndex(carros garagem[], int qtd){
	int index, count;

	for(index = 0, count = 0; count < qtd; index++){
		if(garagem[index].cadastrado == false){
			return index;
		}
		else if(garagem[index].cadastrado == true){
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