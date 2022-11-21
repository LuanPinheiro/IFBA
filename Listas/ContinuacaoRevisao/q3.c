// Que  entre com dados num vetor VET do tipo inteiro com 20 posiçoes, onde podem existir varios elementos repetidos. Gere um vetor VET1 que tambem será ordenado e terá somente os elementos do vetor VET que não sao repetidos.
#include <stdio.h>
#include <stdbool.h>
#define n 10
int main(void) {

  int vet[n];
  int vet1[n];
  int i, aux, j, chk, count=0;

  printf("Preencha o vetor:\n");
  for(i=0;i<n;i++)
    scanf("%d", &vet[i]);

  for(i=0;i<n-1;i++){
    chk=false;
    for(j=i+1;j<n;j++)
      if(vet[i]==vet[j]){
        chk=true;
        break;
      }

    if(chk==false){
      vet1[count]=vet[i];
      count++;
    } 
  }

  printf("Elementos comuns:\n");
  for(i=0;i<count;i++)
        printf("%d\n", vet1[i]);

  return 0;
}