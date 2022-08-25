#include <stdio.h>
#define tam 5

int main(void) {

  int n[tam], par[tam];
  int maior, menor, media = 0;
  int i, cont_par=0, cont_media = 0;
  float percent_par;

  scanf("%d",&n[0]);

  media += n[0];
  maior = n[0];
  menor = n[0];
  
  for(i=1;i<tam;i++)
  {
    scanf("%d",&n[i]);

    media+= n[i];
    
    if (n[i]>maior)
      maior = n[i];
    if (n[i]<menor)
      menor = n[i];

    if(n[i]%2 == 0)
    {
      par[cont_par] = n[i];
      cont_par++;
    }
  }

  media /= tam;

  percent_par = ((float)cont_par / tam) * 100.0;

  printf("\nVetor:\n");
  for(i=0;i<tam;i++)
    printf("%d ", n[i]);
  printf("Maior valor: %d\n", maior);
  printf("Menor valor: %d\n", menor);
  printf("Porcentagem de numeros pares: %.0f%\n", percent_par);
  printf("Media dos valores: %d\n", media);
  
  return 0;
}