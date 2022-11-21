#include <stdio.h>

int main()
{
   int n;
   int idade;
   int idade_21 = 0;
   int idade_50 = 0;
   
   do{
       printf("Digite uma idade: ");
       scanf("%d", &idade);
       
       if(idade < 21 && idade>0)
        idade_21++;
       else if(idade >50)
        idade_50++;
       
       
   }while(idade>0);
   
   printf("Idade maior que 50: %d.\n", idade_50);
   printf("Idade menor que 21: %d.\n", idade_21);

  return 0;
}