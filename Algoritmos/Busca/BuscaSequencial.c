#include <stdio.h>
#define n 10

// Em um vetor "vet[n]", busca um numero "num", iniciando na posição 0 e seguindo por cada posição até encontrar o numero desejado

// T(n) ~ n^2
int main(){
	int vet[n];
	int i, num;
	
	//Vetor do exemplo: [0][1][2][3][4][5][6][7][8][9];
	for(i=0;i<n;i++)
	vet[i] = i;
	
	scanf("%d",&num);

	for(i=0;i<n;i++){
		if(vet[i]==num){
			break;
		}
	}

	if(i<n)
		printf("Numero encontrado na posicao: %d", i);
	
	return 0;
}