#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TAMANHO_LISTA 10

struct dataNascimento
{
    int dia;
    int mes;
    int ano;
};
typedef struct cadAluno
{
    char nome[50];
    struct dataNascimento dtnasc;
    char CPF[15];
    int matricula;//ano depois numero, ex: 201901,201902
    char sexo;
} Lista_aluno;

int cadastroAluno(int qtd);
int validarnome(char nm[50]);
int validardtnasc(int d, int m, int a);
int validarcpf(char c[15]);
int validarsexo(char s);
int validarmatricula(int mat);
int matricula_Aluno(int qtd,Lista_aluno Alunos[]);
int menu_opcoes();
void remover_Aluno();

int main()
{
    //valor de options em 1 para iniciar o while
    int options=1, retorno, qtdAlunos=0, qtdProf=0, qtdDisc=0;

    while (options!=0)
    {
        printf("Escolha uma das opcoes abaixo:\n\n");
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
            case 1: retorno = cadastroAluno(qtdAlunos);
                    if(retorno==1)
                        qtdAlunos++;
                    break;
            case 2: /*cadastroProfessor();*/
                    qtdProf++;
                    break;
            case 3: /*cadastroDisciplina();*/
                    qtdDisc++;
                    break;
            case 4: /*inserirAluno();*/ break;

            // quando for listar enviar qtdAluno/Prof/Disc para cada respectiva função

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
}

int cadastroAluno(int qtd)
{
    int x;
    int status_matricula;
    Lista_aluno Aluno[TAMANHO_LISTA];
    for(x=0;x<10;x++)
    {
        status_matricula = matricula_Aluno(qtd, Lista_aluno Aluno[TAMANHO_LISTA]);
        if(status_matricula==1)
        {
            printf("### MATRICULA REALIZADA COM SUCESSO###\n");
            return 1;
        }
        else
        {
            printf("###FALHA NA MATRICULA###\n");
            return 0;
        }
    }    
}
   
int matricula_Aluno(int qtd, Lista_aluno Alunos[])
{
    int v1,v2,v3,v4,v5;
    
    printf("Informe o nome do Aluno\n");
    fgets(Alunos[qtd].nome,50,stdin);
    size_t ln= strlen(Alunos[qtd].nome)-1;
    if(Alunos[qtd].nome[ln]=='\n')
            Alunos[qtd].nome[ln]='\0';
    
    printf("Informe a dia do Nascimento\n");
    scanf("%d",&Alunos[qtd].dtnasc.dia);
    
    printf("Informe a mes do Nascimento\n");
    scanf("%d",&Alunos[qtd].dtnasc.mes);
    
    printf("Informe a ano do Nascimento\n");
    scanf("%d",&Alunos[qtd].dtnasc.ano);
        
    printf("Informe a matricula do aluno\n");
    scanf("%d",&Alunos[qtd].matricula);

    printf("Informe o CPF do Aluno\n");
    scanf("%s",&Alunos[qtd].CPF);
        
    printf("Infome o sexo do Aluno(F, M ou O)\n");
    scanf("%s",&Alunos[qtd].sexo);
    
    //Validação dos dados inseridos//
    v1=validarnome(Alunos[qtd].nome);
    v2=validardtnasc(Alunos[qtd].dtnasc.dia,Alunos[qtd].dtnasc.mes,Alunos[qtd].dtnasc.ano);
    v3=validarcpf(Alunos[qtd].CPF);
    v4=validarsexo(Alunos[qtd].sexo);
    v5=validarmatricula(Alunos[qtd].matricula);
    
    if(v1==1 && v2==1 && v3==1 && v4==1 && v5==1)
    {
        return 1;
    }
    if(v1==0)
        printf("ERRO_NOME_INVALIDO\n");
    if(v2==0)
        printf("ERRO_DATA_INVALIDA\n");
    if(v3==0)
        printf("ERRO_CPF_INVALIDO\n");
    if(v4==0)
        printf("ERR0_SEXO_INVALIDO\n");
    if(v5==0)
        printf("ERRO_MATRICULA_INVALIDA\n");
    return 0;
    
}

int validarnome(char nm[])
{
    int tam;
    tam=strlen(nm);
    if(tam>20)
        return 1;
     else
        return 0;
}

int validardtnasc(int d,int m,int a)
{
    if( d<=31 &&  d>0)
    {
        if( m<=12 &&  m>0)
        {
            if( a > 0)
                return 1;
            else 
                return 0;
        }
        else
            return 0;
    }
    else
        return 0;
}

int validarcpf(char c[])
{
    int len;
    len = strlen(c);
    if(len==14 || len==11)
        return 1;
    else
        return 0;
}

int validarsexo(char s)
{
    if(s=='M' || s=='m' || s=='F' || s=='f' || s=='O'  || s=='o')
        return 1;
    else
        return 0;
}

int validarmatricula(int mat)
{
    if(mat>0)
        return 1;
    else
        return 0;
}