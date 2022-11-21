#include <stdio.h>
#define n 10

// Em um vetor "vet[n]" ORDENADO, busca um numero "num", utilizando um método de encontrar o meio do vetor e checar se é maior ou menor que o valor de vet[meio], e fazendo o meio se tornar o inicio/fim da proxima checagem, gerando um novo meio

// T(n)=LogN na base 2, ao dobrar a entrada, aumenta o numero de passos em 1
int main(){
  int vet[n];
  int ini, meio, fim, i, num, check = 0;

  //Vetor do exemplo: [0][1][2][3][4][5][6][7];
  for(i=0;i<n;i++)
    vet[i] = i;

  scanf("%d",&num);
  ini = 0;
  meio = i/2;
  fim = i-1;
  
  while(vet[ini]<=vet[fim]){
    meio = (ini + fim) / 2;
    printf("passo %d---\n", check+1);
    printf("meio: %d***\n\n", meio);

    if(num == vet[meio])
    {
      printf("Encontrou");
      break;
    }
    else if(vet[meio] < num)
      ini = meio + 1;
    else
      fim = meio - 1;
    
    check++;
  }
  return 0;
}