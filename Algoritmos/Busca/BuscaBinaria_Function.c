#include <stdio.h>
#define n 10

// Em um vetor "vet[n]" ORDENADO, busca um numero "num", utilizando um método de encontrar o meio do vetor e checar se é maior ou menor que o valor de vet[meio], e fazendo o meio se tornar o inicio/fim da proxima checagem, gerando um novo meio

int BinarySearch(int vetor[], int inicio, int fim, int valor_buscado){
	if(inicio > fim){
		return -1; // O valor não foi encontrado
	}

	int meio = (inicio + fim) / 2;
	
	if(vetor[meio] == valor_buscado){
		return meio; // O valor foi encontrado na posição em int que será retornada
	}
	else if(vetor[meio] > valor_buscado){
		return BinarySearch(vetor, inicio, meio-1, valor_buscado); // Será buscado do meio para menos
	}
	else{
		return BinarySearch(vetor, meio+1, fim, valor_buscado); // Será buscado do meio para mais
	}
}