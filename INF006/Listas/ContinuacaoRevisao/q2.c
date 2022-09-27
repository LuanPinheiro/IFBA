// Que dado dois vetores de 10 posições, efetue operações basicas aritmeticas, indicadas por um terceiro vetor cujos dados tambem são fornecidos pelo usuario, gerando e imprimindo um quarto vetor.
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void leituraDados(float num1[], float num2[], char op[], float result[], int index);
int validOp(char op);
void limparString(char string[]);
void limparBuffer();

int main(){
  float vetor1[10], vetor2[10], vetor4[10];
  char vetor3[3];

  for(int i=0;i<10;i++)
    leituraDados(vetor1, vetor2, vetor3, vetor4, i);

  printf("ENCERRANDO PROGRAMA");
  
  return 0;
}

void leituraDados(float num1[], float num2[], char op[], float result[], int index){
  int tam, erro;
  
  printf("***OPERACAO #%d***\n", index);
  printf("Digite o primeiro valor: ");
  scanf("%f", &num1[index]);
  getchar();
  printf("\n");

  printf("Digite o segundo valor: ");
  scanf("%f", &num2[index]);
  getchar();
  printf("\n");

  do{
    erro=false;
    printf("Digite a operacao: ");
    fgets(op, 3, stdin);
    limparString(op);
    tam = strlen(op);
    if(tam>1 || validOp(op[0])!=true){
      printf("\n***ERRO NA ENTRADA***\n\n");
      erro=true;
      if(tam>1)
        limparBuffer();
    }
  }while(erro!=false);
  printf("\n");

  if(op[0]=='+')
    result[index] = num1[index]+num2[index];
  else if(op[0]=='-')
    result[index] = num1[index]-num2[index];
  else if(op[0]=='*')
    result[index] = num1[index]*num2[index];
  else if(op[0]=='/')
    result[index] = num1[index]/num2[index];
    
  printf("%.1f %c %.1f = %.1f\n\n", num1[index], op[0], num2[index], result[index]);
}

int validOp(char op){
  char valid[] = {'+', '-', '*', '/'};

  for(int i=0;valid[i]!='\0';i++)
    if(op==valid[i])
      return true;

  return false;
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