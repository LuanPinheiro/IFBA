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
    for(x=0;x<10;x++)
      {
        if((i == 0 || i % 2 == 0) && (x == 1 || x % 2 != 0))
          printf("%d\n",m[i][x]);
      }
  
  return 0;
}