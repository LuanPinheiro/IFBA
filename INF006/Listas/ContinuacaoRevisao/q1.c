/* Que imprima o horóscopo de varias pessoas, a aprtir da sua data de nascimento (ddmm). O fim é determinado quando se digita 9999 para data. considera que a data foi digitada corretamente.

01-20 Capricornio
02-19 Aquario
03-20 Peixes
04-20 Aries
05-20 Touro
06-20 Gemeos
07-21 Cancer
08-22 Leão
09-22 Virgem
10-22 Libra
11-21 Escorpião
12-21 Sargitario*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void limparString(char string[]);
void limparBuffer();

int main(){
  int mes, dia, erro;
  char entrada[6];

  do{
    erro=false;
    printf("Digite a data de nascimento: ");
    fgets(entrada, 6, stdin);
    limparString(entrada);
    if(strlen(entrada)!=4){
      erro=true;
      if(strlen(entrada)>4)
        limparBuffer();
    }
    
    if(erro==false){
      mes = ((entrada[2]-48) * 10) + (entrada[3]-48);
      if(mes>=1 && mes<=12){
        dia = ((entrada[0]-48) * 10) + (entrada[1]-48);
        
        if(dia > 31 || dia <= 0)
          erro=true;
        else{
          if(mes != 2){
            if(mes == 4 || mes == 6 || mes == 9 || mes == 11)
              if(dia > 30)
                erro=true;
          } 
          else
            if(dia > 29)
              erro=true;
        }
      }
      else
        erro=true;
    }

    if(erro==false){
      printf("\nSigno: ");
      switch(mes){
        case 1: if(dia<=20)
          printf("Capricornio\n\n");
        else
          printf("Aquario\n\n"); break;
        
        case 2: if(dia<=19)
          printf("Aquario\n\n");
        else
          printf("Peixes\n\n"); break;
        
        case 3: if(dia<=20)
          printf("Peixes\n\n");
        else
          printf("Aries\n\n"); break;
        
        case 4: if(dia<=20)
          printf("Aries\n\n");
        else
          printf("Touro\n\n"); break;
        
        case 5: if(dia<=20)
          printf("Touro\n\n");
        else
          printf("Gemeos\n\n"); break;
        
        case 6: if(dia<=20)
          printf("Gemeos\n\n");
        else
          printf("Cancer\n\n"); break;
        
        case 7: if(dia<=21)
          printf("Cancer\n\n");
        else
          printf("Leao\n\n"); break;

        case 8: if(dia>=22)
          printf("Leao\n\n");
        else
          printf("Virgem\n\n"); break;
        
        case 9: if(dia>=22)
          printf("Virgem\n\n");
        else
          printf("Libra\n\n"); break;
        
        case 10: if(dia>=22)
          printf("Libra\n\n");
        else
          printf("Escorpiao\n\n"); break;
        
        case 11: if(dia>=21)
          printf("Escorpiao\n\n");
        else
          printf("Sagitario\n\n"); break;
        
        case 12: if(dia>=21)
          printf("Sagitario\n\n");
        else
          printf("Aquario\n\n"); break;
        
        default: break;
      }
    }
    else
      printf("\n***ENTRADA INVALIDA***\n\n");
  }while(strcmp("9999", entrada)!=0);
  
  printf("\nENCERRANDO\n");
  
  return 0;
}

void limparString(char string[]){
  for(int i=0;string[i]!='\0';i++)
      if(string[i]=='\n')
        string[i] = '\0';
}

void limparBuffer(){
  char c = 'm';
  do{
    c = getchar();
  }while (c != '\n');
}