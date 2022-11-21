#include <stdio.h>
#define n 10

int main(void) {
	int i, j, aux, vet[n];
	
	for(i=0;i<n;i++)
		scanf("%d", &vet[i]);
	
	for(i=0;i<n-1;i++){    			// n-1
		for(j=0;j<n-i-1;j++){       // (n*(n-i-1)/2)
			if(vet[j+1]<vet[j]){    // (n*(n-i-1)/2)
				aux = vet[j];       // (n*(n-i-1)/2)
				vet[j] = vet[j+1];  // (n*(n-i-1)/2)
				vet[j+1] = aux;     // (n*(n-i-1)/2)
			}
		}
	}
	
	// Progressão Aritmética = n*(n-1)/2, estrutura: (elemento1+elementofinal)*(qtd elementos)/2
	// T(n) ~ n^2
	
	// Quadrático para trocas. (~n^2)
	// Quadrático para comparações. (~n^2)
	// Ineficiente por ser totalmente quadrático, tanto em trocas tanto em comparações
	
	for(i=0;i<n;i++)
		printf("[%d] ", vet[i]);
	
	return 0;
}