#include <stdlib.h>
#include <stdio.h>

int main()
{
    //valor de options em 20 para iniciar o while
    int options=20;

    while (options!=0)
    {
        printf("Escolha uma das ações abaixo:\n\n");

        printf("(1) Cadastrar um aluno\n");
        printf("(2) Cadastrar um professor\n");
        printf("(3) Cadastrar uma disciplina\n");
        printf("(4) Inserir/excluir aluno de uma disciplina\n");
        printf("(5) Listar todos os alunos\n");
        printf("(6) Listar todos os professores\n");
        printf("(7) Listar todas as disciplinas\n");
        printf("(8) Listar uma disciplina e os alunos matriculados nela\n");
        printf("(9) Listar alunos por sexo\n");
        printf("(10) Listar alunos em ordem alfabética\n");
        printf("(11) Listar alunos por data de nascimento\n");
        printf("(12) Listar aniversariantes do mês\n");
        printf("(13) Buscar um professor ou aluno\n");
        printf("(0) Fechar o programa\n");

        scanf("%d",&options);
        
        switch(options)
        {
            case 0: return 0; break;
            case 1: /*cadastroAluno();*/ break;
            case 2: /*cadastroProfessor();*/ break;
            case 3: /*cadastroDisciplina();*/ break;
            case 4: /*inserirAluno();*/ break;
            case 5: /*listaAluno();*/ break;
            case 6: /*listaProfessor();*/ break;
            case 7: /*listaDisciplina();*/ break;
            case 8: /*listaDisciplinaAluno();*/ break;
            case 9: /*listaAlunoSexo();*/ break;
            case 10: /*listaAlunoAlfabetica();*/ break;
            case 11: /*listaAlunoNascimento();*/ break;
            case 12: /*listaAniversariante();*/ break;
            case 13: /*busca();*/ break;
            default: while(options>13)
            {
                printf("Numero Invalido\n");
                scanf("%d",&options);
            }
            break;
        }

    }
    return 0;
}