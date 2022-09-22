// Que deixe entrar com valores de uma matriz de ordem cinco e verificar se ela é ou nao uma matriz triangular superior. P.S. Matriz triangular superior é uma matriz onde todos elementos de posições L<C são diferentes de 0 e todos os elementos de L>C são iguais a 0.
#include <stdio.h>
#include <stdbool.h>

int main(){
  int mat[5][5], A[5], B[5], i, j, countMenor=0, countMaior=0, maior, menor, preencher_m=0;
  
  for(i=0;i<5;i++){
    printf("Linha %d:\n", i+1);
    for(j=0;j<5;j++)
      scanf("%d", &mat[i][j]);
    printf("\n");
  }
    

  for(i=0;i<5;i++){
    for(j=0;j<5;j++)
      printf("[%d] ", mat[i][j]);
    printf("\n");
  }

  int triangular = true;
  for(i=0;i<5;i++){
    for(j=0;j<5;j++){
      if(i<j)
        if(mat[i][j]==0){
          triangular=false;
          break;
        }
      if(i>j)
        if(mat[i][j]!=0){
          triangular=false;
          break;
        }
    }
  }
  if(triangular==true)
    printf("\nEh triangular");
  else
    printf("\nNao eh triangular");
  return 0;
}