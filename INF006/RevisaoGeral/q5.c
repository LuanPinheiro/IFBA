#include <stdio.h>

typedef struct{
  char nome[20];
  int idade;
}info_pessoa;

int main(void) {
  info_pessoa pessoas[20];
  info_pessoa pessoas_ls[20];
  int count_ls = 0;
  int i, x;

  for(i=0;i<2;i++)
  {
    scanf("%d", &pessoas[i].idade);
    scanf("%s", pessoas[i].nome);
    if((pessoas[i].nome[0] >= 108 && pessoas[i].nome[0] <= 115) || (pessoas[i].nome[0] >= 76 && pessoas[i].nome[0] <= 83))
    {
      for(x=0;pessoas[i].nome[x] != '\0';x++)
        pessoas_ls[count_ls].nome[x] = pessoas[i].nome[x];

      pessoas_ls[count_ls].nome[x] = '\0'; //colocando o \0 para a ultima posição
      count_ls++;
    }
  }

  printf("Pessoas com iniciais entre l e s:\n");
  for(i=0;i<count_ls;i++)
    printf("%s\n", pessoas_ls[i].nome);
}