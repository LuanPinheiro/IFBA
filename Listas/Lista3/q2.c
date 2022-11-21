// Crie um programa que dado uma string, coloque as letras dela em ordem crescente pelo algoritmo da bolha.
#include <stdio.h>
#define n 10

void bubbleSort(char vet[]);

int main(){
	char string[n] = "teststring";

	bubbleSort(string);
	
	for(int i = 0; string[i] != '\0'; i++){
		printf("[%c] ", string[i]);
	}
	return 0;
}

void bubbleSort(char vet[]){
	int i, j, aux;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(vet[j+1]<vet[j]){
				aux = vet[j];
				vet[j] = vet[j+1];
				vet[j+1] = aux;
			}
		}
	}
}