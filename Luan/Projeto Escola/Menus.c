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

int cadastroAluno(int qtd, Lista_aluno Aluno[]);
int validarnome(char nm[50]);
int validardtnasc(int d, int m, int a);
int validarcpf(char c[15]);
int validarsexo(char s);
int validarmatricula(int mat);
int matricula_Aluno(int qtd, Lista_aluno Alunos[]);
int menu_opcoes();
void listar_aluno(Lista_aluno Alunos[]);
void status_aluno(Lista_aluno Alunos[]);
int retirar_aluno(Lista_aluno Alunos[]);

int main()
{
    //valor de options em 1 para iniciar o while
    int options=1, retorno, qtdAlunos=0, qtdProf=0, qtdDisc=0;
    Lista_aluno Aluno[TAMANHO_LISTA];

    status_aluno(Aluno);

    while (options!=0)
    {
        printf("\nEscolha uma das opcoes abaixo:\n\n");
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
        printf("(0) Fechar o programa\n\n");

        scanf("%d",&options);
        
        printf("\n");
        
        switch(options)
        {
            case 0: return 0; break;
            case 1: retorno = cadastroAluno(qtdAlunos, Aluno);
                    if(retorno==1)
                        qtdAlunos++;
                    break;
            case 2: /*cadastroProfessor(qtdProf);*/
                    qtdProf++;
                    break;
            case 3: /*cadastroDisciplina(qtdDisc);*/
                    qtdDisc++;
                    break;
            case 4: qtdAlunos=retirar_aluno(Aluno); break;

            // quando for listar enviar qtdAluno/Prof/Disc para cada respectiva função
            case 5: listar_aluno(Aluno); break;
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

int cadastroAluno(int qtd, Lista_aluno Aluno[])
{
    int x;
    int status_matricula;

    for(x=0;x<10;x++)
    {
        status_matricula = matricula_Aluno(qtd, Aluno);
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
    int v1,v2,v3,v4,v5,ver;
    
     for(ver=0;ver<TAMANHO_LISTA;ver++)
    {
        if(Alunos[qtd].matricula!=-1)
            qtd++;
        else
            break;
    }
    
    printf("Informe a matricula do aluno\n");
    scanf("%d",&Alunos[qtd].matricula);
    getchar();

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
    getchar();

    printf("Informe o CPF do Aluno\n");
    fgets(Alunos[qtd].CPF,15,stdin);
    ln= strlen(Alunos[qtd].CPF)-1;
    if(Alunos[qtd].CPF[ln]=='\n')
            Alunos[qtd].CPF[ln]='\0';
        
        
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
    if(tam>5)
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
    if(mat>-1)
        return 1;
    else
        return 0;
}

void listar_aluno(Lista_aluno Alunos[])
{
    int x;
    
    for(x=0;x<TAMANHO_LISTA;x++)
    {
        if(Alunos[x].matricula!=-1)
        printf("%d. %s\n",x+1,Alunos[x].nome);
    }
}

void status_aluno(Lista_aluno Alunos[])
{
    int x;
    
    for(x=0;x<TAMANHO_LISTA;x++)
        Alunos[x].matricula = -1;
}

int retirar_aluno(Lista_aluno Alunos[])
{
    int del;
    
    printf("Informe o numero do Aluno\n");
    listar_aluno(Alunos);
    scanf("%d",&del);
    Alunos[del-1].matricula=-1;
    del--;
    return del;
}
