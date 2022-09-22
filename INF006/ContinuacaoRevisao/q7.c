// Que declare uma matriz 5x5  e armazene em um vetor o maior elemento cadastrado em cada coluna da matriz, e em um vetor b o menor elemento cadastrado em cada coluna da matriz e imprima: a) toda a matrix; b) o vetor a; c) o vetor b; d)(a+b)/2
#include <stdio.h>

int main(){
  int mat[5][5], A[5], B[5], i, j, countMenor=0, countMaior=0, maior, menor;
  
  for(i=0;i<5;i++){
    printf("Linha %d:\n", i+1);
    for(j=0;j<5;j++){
      scanf("%d", mat[i][j]).
    }
    printf("\n");
  }
    

  for(i=0;i<5;i++){
    for(j=0;j<5;j++)
      printf("[%d] ", mat[i][j]);
    printf("\n");
  }

  j=0;
  for(i=0;i<5;i++){
    j=0;
    menor=mat[j][i];
    maior=mat[j][i];
    for(j=0;j<5;j++){
      if(mat[j][i]<menor)
        menor=mat[j][i];
      if(mat[j][i]>maior)
        maior=mat[j][i];
    }
    printf("\n");
    A[countMaior]=maior;
    B[countMenor]=menor;
    countMaior++;
    countMenor++;
  }
  
  printf("\n\nMaiores de cada coluna:\n");
  for(i=0;i<5;i++)
    printf("[%d] ", A[i]);
  printf("\n\n");

  printf("Menores de cada coluna:\n");
  for(i=0;i<5;i++)
    printf("[%d] ", B[i]);
  printf("\n\n");

  printf("(A+B)/2:\n");
  for(i=0;i<5;i++)
    printf("[%d] ", ((A[i]+B[i])/2));
  printf("\n\n");
  return 0;
}