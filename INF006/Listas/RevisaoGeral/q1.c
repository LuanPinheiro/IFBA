#include <stdio.h>

int main(void) {
  int h = 0, m = 0, s = 0;
  float massa;

  scanf("%f", &massa);

  do
  {
    s+=30;
    if(s == 60)
    {
      s=0;
      m++;
      if(m == 60)
      {
        h++;
        m=0;
      }
    }
    massa -= massa * 0.25;
    
  }while (massa >= 0.10);

  printf("Foram necessarias %d:%d:%d", h, m, s);
  
  return 0;
}