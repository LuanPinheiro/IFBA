/*Considere uma aplicação para armazenar os seguintes dados de carros para uma garagem: placa,
marca/modelo e cor. Especifique um TAD para armazenar os dados dos carros e as operações necessárias para inserir,
consultar e excluir os dados das pessoas.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define tam 100

typedef struct{
	char placa[10]; // Formato, LLLNNN, 3 letras e 3 numeros
	char marca[20]; // Formato livre, desde que tenha 1 caractere
	char cor[10];   // permitido cores pré determinadas na função de validação
	int cadastrado; // Organiza exclusão lógica
}carros;

int incluirCarro(carros carros[], int qtd);
int excluirCarro(carros carros[], int qtd);
void consultarCarro(carros carros[], int qtd);
int validarPlaca(carros garagem[], int qtd, char placaValidar[]);
int placaRepetida(carros garagem[], int qtd, char placaValidar[]);
int validarCor(char corValidar[]);
void transformMaiusculo(char string[]);
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
			case 1:	qtd = incluirCarro(garagem, qtd); break;
			case 2: if(qtd > 0){
				qtd = excluirCarro(garagem, qtd);
				}
				else{
					printf("\n(NAO HA CARROS CADASTRADOS)\n");
					getchar();
				} break;
			case 3: if(qtd > 0){
				consultarCarro(garagem, qtd);
				}
				else{
					printf("\n(NAO HA CARROS CADASTRADOS)\n");
					getchar();
				} break;
			default: printf("\nOPCAO INVALIDA\n\n");
		}
	}while(op);
}

int incluirCarro(carros garagem[], int qtd){
	system("cls");
	int index = trueIndex(garagem, qtd);
	int valido;

	do{
		valido = true;
		printf("Digite a placa do carro: ");
		fgets(garagem[index].placa, 10, stdin);
		limparString(garagem[index].placa);
		if(strlen(garagem[index].placa) != 6){
			valido = false;
		}
		else{
			transformMaiusculo(garagem[index].placa);
			valido = validarPlaca(garagem, qtd, garagem[index].placa);
		}
		if(valido == false){
			printf("\n(ENTRADA INVALIDA)\n");
		}
	}while(valido != true);

	do{
		valido = true;
		printf("Digite a marca do carro: ");
		fgets(garagem[index].marca, 20, stdin);
		limparString(garagem[index].marca);
		if(strlen(garagem[index].marca) < 1){
			valido = false;
			printf("\n(ENTRADA INVALIDA)\n");
		}
		else{
			transformMaiusculo(garagem[index].marca);
		}
	}while(valido != true);

	do{
		valido = true;
		printf("Digite a cor do carro: ");
		fgets(garagem[index].cor, 10, stdin);
		limparString(garagem[index].cor);
		if(strlen(garagem[index].cor) < 3){
			valido = false;
		}
		else{
			transformMaiusculo(garagem[index].cor);
			valido = validarCor(garagem[index].cor);
		}
		
		if(valido == false){
			printf("\n(ENTRADA INVALIDA)\n");
		}
	}while(valido != true);
	
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
		transformMaiusculo(placa);

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
		transformMaiusculo(placa);

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

int validarPlaca(carros garagem[], int qtd, char placaValidar[]){
	for(int i = 0; placaValidar[i] != '\0'; i++){
		if(i<3){
			if(placaValidar[i] < 65 || placaValidar[i] > 90){
				return false;
			}
		}
		else{
			if(placaValidar[i] < 48 || placaValidar[i] > 57){
				return false;
			}
		}
	}
	if(qtd > 0){
		return placaRepetida(garagem, qtd, placaValidar);
	}
	else{
		return true;
	}
}

int placaRepetida(carros garagem[], int qtd, char placaValidar[]){
	for(int i = 0, count = 0; count < qtd; i++){
		if(garagem[i].cadastrado == true){
			if(strcmp(placaValidar, garagem[i].placa) == 0){
				return false;
			}
			count++;
		}
	}
	return true;
}

int validarCor(char corValidar[]){
	if(strcmp(corValidar, "BRANCO")){
		return true;
	}
	else if(strcmp(corValidar, "PRETO")){
		return true;
	}
	else if(strcmp(corValidar, "CINZA")){
		return true;
	}
	else if(strcmp(corValidar, "PRATA")){
		return true;
	}
	else if(strcmp(corValidar, "VERMELHO")){
		return true;
	}
	else if(strcmp(corValidar, "AZUL")){
		return true;
	}
	else if(strcmp(corValidar, "VERDE")){
		return true;
	}
	else if(strcmp(corValidar, "AMARELO")){
		return true;
	}
	else if(strcmp(corValidar, "ROSA")){
		return true;
	}
	else{
		return false;
	}
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

//****************** Se houver letras minusculas transformará em maiuscula para padronização do modelo das strings
void transformMaiusculo(char string[]){
  for(int i=0;string[i]!='\0';i++)
    if(string[i]>=97 && string[i]<=122)
      string[i] -= 32;
}