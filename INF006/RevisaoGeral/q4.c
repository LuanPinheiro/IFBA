#include <stdio.h>

int main(void) {
  float chico = 1.5, juca = 1.10;
  int anos;

  for(anos=0;juca<=chico;anos++)
  {
    juca += 0.03;
    chico += 0.02;
  }

  printf("Serao necessarios %d anos para juca ser maior que chico", anos);
  
  return 0;
}