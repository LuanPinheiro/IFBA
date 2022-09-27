#include <stdio.h>

typedef struct{
  char nome[60];
  float nota1;
  float nota2;
  float media;
  int ap_rp;
}ficha_aluno;

void LimparString(char string[]);

int main(void) {
  ficha_aluno alunos[15];
  int i;

  for(i=0;i<15;i++)
  {
    getchar();
    fgets(alunos[i].nome, 60, stdin);
    LimparString(alunos[i].nome);
    
    scanf("%f", &alunos[i].nota1);
    scanf("%f", &alunos[i].nota2);
    alunos[i].media = (alunos[i].nota1 + alunos[i].nota2) / 2;
    if(alunos[i].media >= 5)
      alunos[i].ap_rp = 0;
    else
      alunos[i].ap_rp = 1;
  }

  for(i=0;i<15;i++)
  {
    printf("Nome do Aluno: %s\n", alunos[i].nome);
    printf("Nota 1 do Aluno: %.1f\n", alunos[i].nota1);
    printf("Nota 2 do Aluno: %.1f\n", alunos[i].nota2);
    printf("Media do Aluno: %.1f\n", alunos[i].media);
    if(alunos[i].ap_rp == 0)
      printf("Situacao do Aluno: Aprovado\n\n");
    else
      printf("Situacao do Aluno: Reprovado\n\n");
  }

  return 0;
}

void LimparString(char string[]){
  for(int i=0;string[i] != '\0';i++)
      if(string[i] == '\n')
        string[i] = '\0';
}