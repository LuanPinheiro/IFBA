/*Considere uma empresa que precisa armazenar os seguintes dados de um cliente:
■ nome completo;
■ ano de nascimento;
■ renda mensal do cliente.
Especifique um TAD para armazenar os dados de um cliente e as operações necessárias para inserir, consultar e
excluir os dados dos clientes. Especifique também operações para exibir o número de clientes com renda mensal
acima da média, e exibir o número de clientes que nasceram entre 1980 e 2000.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define tam 100

typedef struct{
	char nome[52];
	int anoNascimento;
	int rendaMensal;
	int cadastrado;
}person;

int incluirPessoa(person pessoas[], int qtd);
int excluirPessoa(person pessoas[], int qtd);
void consultarPessoa(person pessoas[], int qtd);
void exibirAcimaMedia(int rendaMedia, person pessoas[], int qtd);
void exibirEspacoAnos(person pessoas[], int qtd);
void printPessoa(person pessoa);
int calcularMedia(int qtd, person pessoas[]);
int trueIndex(person pessoas[], int qtd);
void limparString(char string[]);

int main(){
	person pessoas[tam];
	int op, qtd = 0, rendaMensalMedia = 0;
	
	do{
		system("clear");
		printf("%d\n\n", qtd);
		printf("1. Inserir\n2. Excluir\n3. Consultar\n4. Pessoas com renda mensal acima da media\n5. Clientes que nasceram entre 1980 e 2000\n");
		printf("(Digite 0 para fechar o programa)\n");
		scanf("%d", &op);
		getchar();

		switch(op){
			case 0: printf("\n\nFECHANDO O PROGRAMA"); return 0; break;
			case 1: qtd = incluirPessoa(pessoas, qtd); rendaMensalMedia = calcularMedia(qtd, pessoas); break;
			case 2: qtd = excluirPessoa(pessoas, qtd); rendaMensalMedia = calcularMedia(qtd, pessoas); break;
			case 3: consultarPessoa(pessoas, qtd); break;
            case 4: exibirAcimaMedia(rendaMensalMedia, pessoas, qtd); break;
            case 5: exibirEspacoAnos(pessoas, qtd);
			default: printf("\nOPCAO INVALIDA\n\n");
		}
	}while(op);
}

int incluirPessoa(person pessoas[], int qtd){
	system("clear");
    int index = trueIndex(pessoas, qtd);
	
	printf("Digite o nome da pessoa: ");
	fgets(pessoas[index].nome, 52, stdin);
	limparString(pessoas[index].nome);

	printf("Digite o ano de nascimento da pessoa: ");
	scanf("%d", &pessoas[index].anoNascimento);
    getchar();

	printf("Digite a renda mensal da pessoa: ");
	scanf("%d", &pessoas[index].rendaMensal);
    getchar();
	
	pessoas[index].cadastrado = true;
	return ++qtd;
}

int excluirPessoa(person pessoas[], int qtd){
	char nome[52];
	int existe, i, count;
	
	do{
		system("clear");
		existe = false;
		printf("Digite um nome registrado: ");
		fgets(nome, 52, stdin);
		limparString(nome);

		for(i=0, count=0; count<qtd; i++){
			if(pessoas[i].cadastrado == true){
				if(strcmp(nome, pessoas[i].nome)==0){
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
	char nome[52];
	int existe, i, count;
	
	do{
		system("clear");
		existe = false;
		printf("Digite um nome registrado: ");
		fgets(nome, 52, stdin);
		limparString(nome);

		for(i=0, count=0; count<qtd; i++){
			if(pessoas[i].cadastrado == true){
				if(strcmp(nome, pessoas[i].nome)==0){
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

	printPessoa(pessoas[i]);
	getchar();
}

void exibirAcimaMedia(int rendaMedia, person pessoas[], int qtd){
    for(int i = 0, count = 0, countAcimaMedia = 0; count < qtd; i++){
        if(pessoas[i].cadastrado == true){
            if(pessoas[i].rendaMensal > rendaMedia){
                countAcimaMedia++;
                printf("####### %d", countAcimaMedia);
                printPessoa(pessoas[i]);
            }
            count++;
        }
    }
    getchar();
}

void exibirEspacoAnos(person pessoas[], int qtd){
    printf("Pessoas que nasceram entre 1980 e 2000:\n");
    for(int i = 0, count = 0, countEspaco = 0; count < qtd; i++){
        if(pessoas[i].cadastrado == true){
            if(pessoas[i].anoNascimento > 1980 && pessoas[i].anoNascimento < 2000){
                countEspaco++;
                printf("####### %d", countEspaco);
                printPessoa(pessoas[i]);
            }
            count++;
        }
    }
    getchar();
}

int calcularMedia(int qtd, person pessoas[]){
    int media = 0;

    for(int i = 0, count = 0; count < qtd; i++){
        if(pessoas[i].cadastrado == true){
            media += pessoas[i].rendaMensal;
            count++;
        }
    }
    return media /= qtd;
}

void printPessoa(person pessoa){
    printf("\nNome da pessoa: %s", pessoa.nome);
	printf("\nAno de nascimento da pessoa: %d", pessoa.anoNascimento);
	printf("\nRenda mensal da pessoa: %d\n\n", pessoa.rendaMensal);
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
	for(int i = 0; string[i] != '\0'; i++)
		if(string[i] == '\n')
			string[i] = '\0';
}