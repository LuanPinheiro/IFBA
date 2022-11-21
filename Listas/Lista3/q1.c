/* Faça um programa que leia n nomes inserindo-os em uma lista de forma ordenada utilizando a ideia do algoritmo da inserção.
No final, o programa deve mostrar todos os nomes ordenados alfabeticamente.*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define n 3

typedef struct{
	char nome[32];
}pessoas;

void insertionSort(pessoas vet[]);
void limparString(char string[]);

int main(){
	pessoas entrada[n];
	int i;

	for(i = 0; i < n; i++){
		fgets(entrada[i].nome, 32, stdin);
		limparString(entrada[i].nome);
	}
	
	insertionSort(entrada);
	printf("\n");
	for(i = 0; i < n; i++){
		printf("%s\n", entrada[i].nome);
	}
	return 0;
}

void insertionSort(pessoas vet[]){
    int i, j, k, check;
    char key[32];
    for(i = 1; i < n; i++){
        strcpy(key, vet[i].nome);
		j = i-1;
		check = false;

		while(j >= 0 && check == false){
            for(k = 0; vet[j].nome[k] != '\0'; k++){
				// luan, clara, joao
                if(vet[j].nome[k] > key[k]){
                    strcpy(vet[j+1].nome, vet[j].nome);
					check = true;
					break;
                }
                else if(vet[j].nome[k] < key[k]){
					check = true;
                    break;
                }
            }
			j--;
		}
		strcpy(vet[j+1].nome, key);
	}
}

void limparString(char string[]){
	for(int i=0; string[i]!='\0'; i++)
		if(string[i]=='\n')	
			string[i] = '\0';	
}