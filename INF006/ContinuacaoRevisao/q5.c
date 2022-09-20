// Que leia os elemntos de uma matrix 10x10 e mostre somente os elementos abaixo da diagonal;
#include <stdio.h>

int main(void) {

  int i, j, vet[10][10], preencher_m = 0;

  for(i=0; i<10; i++)
  	for(j=0; j<10; j++){
      vet[i][j] = preencher_m;
      preencher_m++;
    }
  		 
  
  for(i=0; i<10; i++){
  	for(j=0; j<10; j++)
  		if(j < i)
  			printf("[%d]", vet[i][j]);
    printf("\n");
  }

  
  return 0;
}