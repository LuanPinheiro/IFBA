/* Faça um programa que leia n nomes e ordene-os pelo tamanho utilizando o algoritmo da seleção.
No final, o algoritmo deve mostrar todos os nomes ordenados.*/
#include <stdio.h>
#include <string.h>
#define n 10

typedef struct{
	char nome[32];
	int tam;
}pessoas;

void selectionSort(pessoas vet[]);
void limparString(char string[]);

int main(){
	pessoas entrada[n];
	int i;

	for(i = 0; i < n; i++){
		fgets(entrada[i].nome, 32, stdin);
		limparString(entrada[i].nome);
		entrada[i].tam = strlen(entrada[i].nome);
	}
	
	selectionSort(entrada);
	printf("\n");
	for(i = 0; i < n; i++){
		printf("%s\n", entrada[i].nome);
	}
	
	return 0;
}

void selectionSort(pessoas vet[]){
	int i, j, menor, auxTam;
	char aux[n];
	for(i = 0; i < n-1; i++){
    	menor = i;
	    for(j = i+1; j < n; j++)
	      	if(vet[j].tam < vet[menor].tam){
				menor = j;
			}
	    
	   		if(menor!=i){
				strcpy(aux, vet[i].nome);
				auxTam = vet[i].tam;
				
				strcpy(vet[i].nome, vet[menor].nome);
				vet[i].tam = vet[menor].tam;
				
				strcpy(vet[menor].nome, aux);
				vet[menor].tam = auxTam;
	    	}
  	}
}

void limparString(char string[]){
	for(int i=0; string[i]!='\0'; i++)
		if(string[i]=='\n')	
			string[i] = '\0';	
}