// Que leia e armazene os elementos de uma matriz inteira (10,10) e imprima. depois troque os dados da segunda linha pela oitava. da quarta pela decima, a diagonal principal pela diagonal segundaria.
#include <stdio.h>
#include <stdbool.h>

int main(){
  int mat[10][10], l1, l2, c1, c2, aux;

  printf("A matriz original: \n\n");
  for(l1=0;l1<10;l1++){
    printf("Linha %d:\n", l1+1);
    for(c1=0;c1<10;c1++){
      scanf("%d", &mat[l1][c1]);
    }
    printf("\n\n");
  }

  printf("\nA matriz com os dados da segunda linha trocada pela oitava: \n\n");
  for(l1=1, l2=7, c1=0;c1<10;c1++){
    aux=mat[l1][c1];
    mat[l1][c1]=mat[l2][c1];
    mat[l2][c1]=aux;
  }
  for(l1=0;l1<10;l1++){
    for(c1=0;c1<10;c1++)
      printf("[%d] ", mat[l1][c1]);
    printf("\n\n");
  }

  // fazendo a matriz voltar a ficar igual a original
  for(l1=7, l2=1, c1=0;c1<10;c1++){
    aux=mat[l1][c1];
    mat[l1][c1]=mat[l2][c1];
    mat[l2][c1]=aux;
  }

  printf("\nA matriz com a quarta linha trocada pela décima: \n\n");
  for(l1=3, l2=9, c1=0;c1<10;c1++){
    aux=mat[l1][c1];
    mat[l1][c1]=mat[l2][c1];
    mat[l2][c1]=aux;
  }
  for(l1=0;l1<10;l1++){
    for(c1=0;c1<10;c1++)
      printf("[%d] ", mat[l1][c1]);
    printf("\n\n");
  }
  
  // fazendo a matriz voltar a ficar igual a original
  for(l1=9, l2=3, c1=0;c1<10;c1++){
    aux=mat[l1][c1];
    mat[l1][c1]=mat[l2][c1];
    mat[l2][c1]=aux;
  }

  printf("\nA matriz com a diagonal principal trocada com a diagonal secundaria: \n\n");
  for(l1=0, l2=9;l1<10;l1++,l2--){
    aux=mat[l1][l1];
    mat[l1][l1]=mat[l1][l2];
    mat[l1][l2]=aux;
  }
  for(l1=0;l1<10;l1++){
    for(c1=0;c1<10;c1++)
      printf("[%d] ", mat[l1][c1]);
    printf("\n\n");
  }
  
  return 0;
}