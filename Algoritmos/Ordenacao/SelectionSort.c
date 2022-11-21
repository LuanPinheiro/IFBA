#include <stdio.h>
#define n 10

int main(void) {
  int i, j, menor, aux, vet[n];

  for(i=0;i<n;i++)
    scanf("%d", &vet[i]);

  
  for(i=0;i<n-1;i++){       // n-1
    menor = i;              // n-1
    for(j=i+1;j<n;j++)      // n*(n-1)/2
      if(vet[j]<vet[menor]) // n*(n-1)/2
        menor = j;          // n*(n-1)/2
    
    if(menor!=i){           // n-1
      aux = vet[i];         // n-1
      vet[i] = vet[menor];  // n-1
      vet[menor] = aux;     // n-1
    }
  }

  // Progressão Aritmética = n*(n-1)/2, estrutura: (elemento1+elementofinal)*(qtd elementos)/2
  // T(n) ~ n^2

  // Linear para trocas. (n-1)
  // Quadrático para comparações. (~n^2)
  // Eficiente por ter menos trocas, mas ainda ineficiente por ser quadrático em comparações
  
  for(i=0;i<n;i++)
    printf("[%d] ", vet[i]);
      
  return 0;
}