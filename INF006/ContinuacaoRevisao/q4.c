// Que armazene 10 numeros em um vetor. Na entrada de dados, o numero ja deve ser armazenado na sua posição definitiva em ordem decrescente. imprimir o vetor logo apos a entrada de dados;
#include <stdio.h>
#include <stdbool.h>

int main(){
  int vet[10], aux, i, j;

  for(i=0;i<10;i++){
    printf("digite um numero: ");
    scanf("%d", &vet[i]);
    for(j=0;j<i;j++)
      if(vet[i]<vet[j]){
        aux=vet[i];
        vet[i] = vet[j];
        vet[j] = aux;
      }

    printf("Vetor atual: ");
    for(int k=0;k<=i;k++)
      printf("[%d] ", vet[k]);

    printf("\n\n");
  }
  
  return 0;
}