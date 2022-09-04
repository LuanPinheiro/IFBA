#include <stdio.h>

int main()
{
   int natalidade_a = 5000000;
   int natalidade_b = 7000000;
   int anos;
   
   for(anos=0; natalidade_a <= natalidade_b; anos++){
       natalidade_a += natalidade_a * 0.03;
       natalidade_b += natalidade_b * 0.02;
   }
   
   printf("Serao necessarios %d anos.", anos);
  
   return 0;
}