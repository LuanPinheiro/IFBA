#include <stdio.h>

int main(void) {
  int m[10][10];
  int i;
  int x;
  int preencher_m = 0;

  for(i=0;i<10;i++)
    for(x=0;x<10;x++)
      {
        m[i][x]= preencher_m;
        preencher_m++;
      }

  for(i=0;i<10;i++)
    printf("%d ", m[i][i]);
  
  return 0;
}