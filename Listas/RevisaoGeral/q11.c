#include <stdio.h>

int main(void) {
  int m[10][10], m_inv[10][10];
  int i, i_inv;
  int x, x_inv;
  int preencher_m = 0;

  for(i=0, i_inv = 9;i<10;i++, i_inv--)
    for(x=0, x_inv = 9;x<10;x++, x_inv--)
      {
        m[i][x] = preencher_m;
        m_inv[i_inv][x_inv] = preencher_m;
        preencher_m++;
      }

  for(i=0;i<10;i++)
    {
      for(x=0;x<10;x++)
        printf("[%d] ", m_inv[i][x]);
      
      printf("\n");
    }
    
  
  return 0;
}