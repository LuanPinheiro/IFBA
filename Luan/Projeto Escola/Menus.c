#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Alunos.h"
#include "Professor.h"

int main()
{
    //valor de options em 1 para iniciar o while
    int options=1, qtdAlunos=0, qtdProf=0;// qtdDisc=0;
    Lista_aluno Aluno[TAMANHO_LISTA];
    Lista_Prof Prof[TAMANHO_LISTA];

    status_aluno(Aluno);

    while (options!=0)
    {
        printf("\nEscolha uma das opcoes abaixo:\n\n");
        printf("(1) Alunos\n");
        printf("(2) Professores\n");
        printf("(3) Disciplina\n");
        printf("(4) Listar aniversariantes do mês\n");
        printf("(5) Buscar um professor ou aluno\n");
        printf("(0) Fechar o programa\n\n");

        scanf("%d",&options);
        
        printf("\n");
        
        switch(options)
        {
            case 0: return 0; break;
            case 1: qtdAlunos += cadastroAluno(qtdAlunos, Aluno); break;
            case 2: qtdProf += cadastroProf(qtdProf, Prof);  break;
            case 3: /*cadastroDisciplina(qtdDisc);*/ break;
            case 4: /*"Aniversariantes()*/; break;
            case 5: /*Busca(Aluno)*/; break;
            default: while(options>5)
            {
                printf("Numero Invalido\n");
                scanf("%d",&options);
            }
            break;
        }

    }
}