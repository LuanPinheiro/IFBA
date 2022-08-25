#include <stdio.h>

int main(void) {

  int conj_a[10];
  int conj_b[20];
  int conj_comum[10], cont_comum = 0, cont;
  int i, x, y;

  printf("Preencha o primeiro conjunto:\n");
  for(i=0;i<10;i++)
    scanf("%d", &conj_a[i]);
  printf("Preencha o segundo conjunto:\n");
  for(i=0;i<20;i++)
    scanf("%d", &conj_b[i]);

  for(i=0;i<10;i++)
    for(x=0;x<20;x++)
      if(conj_a[i] == conj_b[x])
      {
        for(y=0, cont=0;y<cont_comum;y++)
        {
          if(conj_a[i] == conj_comum[y] && cont_comum>0)
          {
            cont++;
            if(cont == 2)
            {
              conj_comum[y] = '\0';
              cont_comum--;
            }
          }
        }
        if(cont == 0)
        {
          conj_comum[cont_comum] = conj_a[i];
          cont_comum++;
        }
      }

  printf("Elementos comuns:\n");
  for(i=0;i<cont_comum;i++)
        printf("%d\n", conj_comum[i]);

  return 0;
}