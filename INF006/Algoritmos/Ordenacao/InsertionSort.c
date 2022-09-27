#include <stdio.h>
#define n 10

int main(void) {
	int i, j, key, aux, vet[n];
	
	for(i=0;i<n;i++)
		scanf("%d", &vet[i]);
	
	for(i=1;i<n;i++){           		// n-1
		key=vet[i];						// n-1
		for(j=i-1;j>=0;j--){       		// (n*(n-1)/2)
			if(vet[j]>key){				// (n*(n-1)/2)
				vet[j+1] = vet[j];		// (n*(n-1)/2)
			}
			vet[j] = key;				// n-1
		}
	}
	
	// Progressão Aritmética = n*(n-1)/2, estrutura: (elemento1+elementofinal)*(qtd elementos)/2
	// T(n) ~ n^2
	
	// Quadrático para trocas. (~n^2)
	// Quadrático para comparações. (~n^2)
	// Ineficiente por ser totalmente quadrático, tanto em trocas tanto em comparações, mas em casos de vetores quase ordenados pode ser linear, sendo essa sua vantagem
	
	for(i=0;i<n;i++)
		printf("[%d] ", vet[i]);
	
	return 0;
}