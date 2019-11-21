#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Alunos.h"
#include "Professor.h"
#include "Disciplina.h"

int main()
{
    //valor de options em 1 para iniciar o while
    int options=1, qtdAlunos, qtdProf=0, mesAtual;// qtdDisc=0;
    Lista_aluno Aluno[TAMANHO_LISTA];
    Lista_Prof Prof[TAMANHO_LISTA];

    status_aluno(Aluno);

    printf("Digite o Mes atual:\n");
    scanf("%d",&mesAtual);
    printf("\n");

    while (options!=0)
    {
        printf("\nEscolha uma das opcoes abaixo:\n\n");
        printf("(1) Alunos\n");
        printf("(2) Professores\n");
        printf("(3) Disciplina\n");
        printf("(4) Buscar um professor ou aluno\n");
        printf("(5) Mudar o mes atual");
        printf("(0) Fechar o programa\n\n");

        scanf("%d",&options);
        
        printf("\n");
        
        switch(options)
        {
            case 0: return 0; break;
            case 1: qtdAlunos += cadastroAluno(qtdAlunos, Aluno); break;
            case 2: qtdProf += cadastroProf(qtdProf, Prof);  break;
            case 3: /*cadastroDisciplina(qtdDisc);*/ break;
            case 4: /*Busca(Aluno)*/; break;
            case 5: printf("Digite o mes atual"); scanf("%d", &mesAtual); break;
            default: while(options>5 || options<0)
            {
                printf("Numero Invalido\n");
                scanf("%d",&options);
            }
            break;
        }
    }
}