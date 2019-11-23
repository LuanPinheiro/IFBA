#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TAMANHO_LISTA 10

//Structs
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
    int matricula;
    char sexo;
} Lista_aluno;

typedef struct cadProf
{
    char nome[50];
    struct dataNascimento dtnasc;
    char CPF[15];
    int matricula;
    char sexo;
} Lista_Prof;

//Funções Gerais
int validarnome(char nm[50]);
int validardtnasc(int d, int m, int a);
int validarcpf(char c[15]);
int validarsexo(char s);
int validarmatricula(int mat);
void aniversariantes(int mesAtual, int qtdAlunos, Lista_aluno Alunos[], int qtdProf, Lista_Prof Professores[]);

//Funções para Alunos
int matricula_Aluno(int qtd, Lista_aluno Alunos[]);
void listar_aluno(Lista_aluno Alunos[]);
void status_aluno(Lista_aluno Alunos[]);
void retirar_aluno(int qtd, Lista_aluno Alunos[]);
void alterar_aluno(int qtd, Lista_aluno Alunos[]);
void listar_aluno_sexo(Lista_aluno Alunos[]);
//void listar_aluno_data(int qtd, Lista_aluno Alunos[]);

//Funções para Professores
int matricula_Professor(int qtd,Lista_Prof Professores[]);
void listar_Professor(Lista_Prof Professores[]);
void listar_Professor_sexo(Lista_Prof Professores[]);
void status_Professor(Lista_Prof Professores[]);
void retirar_Professor(int qtd, Lista_Prof Professores[]);
void alterar_professor(int qtd, Lista_Prof Professores[]);

int main()
{
    //valor de options em 1 para iniciar o while
    int options=1, qtdAlunos=0, qtdProf=0, mesAtual, retorno;// qtdDisc=0;
    Lista_aluno Aluno[TAMANHO_LISTA];
    Lista_Prof Prof[TAMANHO_LISTA];

    //iniciando as matriculas como inativas
    status_aluno(Aluno);
    status_Professor(Prof);

    printf("Digite o Mes atual:\n");
    scanf("%d",&mesAtual);
    if(mesAtual>12||mesAtual<1)
    {
        while(mesAtual>12||mesAtual<1)
        {
            printf("\nMES INVALIDO, DIGITE NOVAMENTE\n");
            scanf("%d",&mesAtual);
        }
    }
    printf("\n");

    while (options!=0)
    {
        printf("\nEscolha uma das opcoes abaixo:\n\n");
        printf("(1) Cadastrar novo Aluno\n");
        printf("(2) Cadastrar novo Professor\n");
        printf("(3) Cadastrar nova Disciplina\n");
        printf("(4) Excluir Cadastro de Aluno\n");
        printf("(5) Excluir Cadastro de Professor\n");
        printf("(6) Alterar Cadastro de Aluno\n");
        printf("(7) Alterar Cadastro de Professor\n");
        printf("(8) Listar Alunos\n");
        printf("(9) Listar Professores\n");
        printf("(10) Listar Disciplinas\n");
        printf("(11) Listar uma Disciplina\n");
        printf("(12) Listar Alunos por Sexo\n");
        printf("(13) Listar Alunos por Nome\n");
        printf("(14) Listar Alunos por Data de Nascimento\n");
        printf("(15) Listar Professores por Sexo\n");
        printf("(16) Listar Professores por Nome\n");
        printf("(17) Listar Professores por Data de Nascimento\n");
        printf("(18) Buscar um professor ou aluno\n");
        printf("(19) Mostrar Aniversariantes do Mes\n");
        printf("(20) Mudar o mes atual\n");
        printf("(0) Fechar o programa\n\n");

        scanf("%d",&options);
        
        printf("\n");
        
        switch(options)
        {
            case 0: return 0; break;
            case 1: retorno = matricula_Aluno(qtdAlunos, Aluno);
                    if (retorno==1)
                        qtdAlunos++;
                    break;
            case 2: retorno = matricula_Professor(qtdProf, Prof);
                    if (retorno==1)
                        qtdProf++;
                    break;
            case 3: /*cadastroDisciplina(qtdDisc);*/ break;
            case 4: if(qtdAlunos>0)
                    {
                        retirar_aluno(qtdAlunos, Aluno);
                        qtdAlunos--;
                    }
                    else
                        printf("\nNAO POSSUI ALUNOS CADASTRADOS\n");                    
                    break;
            case 5: if(qtdProf>0)
                    {
                        retirar_Professor(qtdProf, Prof);
                        qtdProf--;
                    }
                    else
                        printf("\nNAO POSSUI PROFESSORES CADASTRADOS\n");                    
                    break;
            case 6: if(qtdAlunos>0)
                        alterar_aluno(qtdAlunos, Aluno);
                    else
                        printf("\nNAO POSSUI ALUNOS CADASTRADOS\n");                    
                    break;
            case 7: if(qtdProf>0)
                        alterar_professor(qtdProf, Prof);
                    else
                        printf("\nNAO POSSUI PROFESSORES CADASTRADOS\n");                    
                    break;
            case 8: if(qtdAlunos>0)
                        listar_aluno(Aluno);
                    else
                        printf("\nNAO POSSUI ALUNOS CADASTRADOS\n");                    
                    break;
            case 9: if(qtdProf>0)
                        listar_Professor(Prof);
                    else
                        printf("\nNAO POSSUI PROFESSORES CADASTRADOS\n");                    
                    break;
            case 12:if(qtdAlunos>0)
                        listar_aluno_sexo(Aluno);
                    else
                        printf("\nNAO POSSUI ALUNOS CADASTRADOS\n");                    
                    break;
            /*case 14:if(qtdAlunos>0)
                        listar_aluno_data(qtdAlunos, Aluno);
                    else
                        printf("\nNAO POSSUI ALUNOS CADASTRADOS\n");                    
                    break;*/
            case 15:if(qtdProf>0)
                        listar_Professor_sexo(Prof);
                    else
                        printf("\nNAO POSSUI PROFESSORES CADASTRADOS\n");                    
                    break;
            case 19:aniversariantes(mesAtual, qtdAlunos, Aluno, qtdProf, Prof); break;
            case 20:printf("Digite o mes atual:\n");
                    scanf("%d", &mesAtual);
                    if(mesAtual>12||mesAtual<1)
                    {
                        while(mesAtual>12||mesAtual<1)
                        {
                            printf("\nMES INVALIDO, DIGITE NOVAMENTE\n");
                            scanf("%d",&mesAtual);
                        }
                    }
                    printf("\n");
                    break;
            default: while(options>19 || options<0)
            {
                printf("Numero Invalido\n");
                scanf("%d",&options);
            }
            break;
        }
    }
}

int matricula_Aluno(int qtd, Lista_aluno Alunos[])
{
    int v1,v2,v3,v4,v5;

    printf("Informe a matricula do aluno\n");
    scanf("%d",&Alunos[qtd].matricula);
    getchar();
    
    printf("Informe o nome do Aluno\n");
    fgets(Alunos[qtd].nome,40,stdin);
    size_t ln= strlen(Alunos[qtd].nome)-1;
    if(Alunos[qtd].nome[ln]=='\n')
            Alunos[qtd].nome[ln]='\0';
    
    printf("Informe o dia de Nascimento\n");
    scanf("%d",&Alunos[qtd].dtnasc.dia);
    
    printf("Informe o mes de Nascimento\n");
    scanf("%d",&Alunos[qtd].dtnasc.mes);
    
    printf("Informe o ano de Nascimento\n");
    scanf("%d",&Alunos[qtd].dtnasc.ano);
    getchar();
        
    printf("Informe o CPF do Aluno\n");
    fgets(Alunos[qtd].CPF,15,stdin);
    ln= strlen(Alunos[qtd].CPF)-1;
    if(Alunos[qtd].CPF[ln]=='\n')
            Alunos[qtd].CPF[ln]='\0';
        
    printf("Infome o sexo do Aluno(F, M ou O)\n");
    scanf("%c",&Alunos[qtd].sexo);
    
    //Validação dos dados inseridos//
    v1=validarnome(Alunos[qtd].nome);
    v2=validardtnasc(Alunos[qtd].dtnasc.dia,Alunos[qtd].dtnasc.mes,Alunos[qtd].dtnasc.ano);
    v3=validarcpf(Alunos[qtd].CPF);
    v4=validarsexo(Alunos[qtd].sexo);
    v5=validarmatricula(Alunos[qtd].matricula);
    
    if(v1==1 && v2==1 && v3==1 && v4==1 && v5==1)
    {
        printf("\nMATRICULA CONCLUIDA\n");
        return 1;
    }
    if(v1==0)
        printf("\nERRO_NOME_INVALIDO\n");
    if(v2==0)
        printf("\nERRO_DATA_INVALIDA\n");
    if(v3==0)
        printf("\nERRO_CPF_INVALIDO\n");
    if(v4==0)
        printf("\nERR0_SEXO_INVALIDO\n");
    if(v5==0)
        printf("\nERRO_MATRICULA_INVALIDA\n");

    Alunos[qtd].matricula=-1;
    return 0;   
}

int matricula_Professor(int qtd, Lista_Prof Professores[])
{
    int v1,v2,v3,v4,v5;
    
    printf("Informe a matricula do Professor\n");
    scanf("%d",&Professores[qtd].matricula);
    getchar();
    
    printf("Informe o nome do Professor\n");
    fgets(Professores[qtd].nome,40,stdin);
    size_t ln= strlen(Professores[qtd].nome)-1;
    if(Professores[qtd].nome[ln]=='\n')
            Professores[qtd].nome[ln]='\0';
    
    printf("Informe o dia de Nascimento\n");
    scanf("%d",&Professores[qtd].dtnasc.dia);
    
    printf("Informe o mes de Nascimento\n");
    scanf("%d",&Professores[qtd].dtnasc.mes);
    
    printf("Informe o ano de Nascimento\n");
    scanf("%d",&Professores[qtd].dtnasc.ano);
    getchar();
        
    printf("Informe o CPF do Professor\n");
    fgets(Professores[qtd].CPF,15,stdin);
    ln= strlen(Professores[qtd].CPF)-1;
    if(Professores[qtd].CPF[ln]=='\n')
            Professores[qtd].CPF[ln]='\0';
        
    printf("Infome o sexo do Professor(F, M ou O)\n");
    scanf("%c",&Professores[qtd].sexo);
    
    //ValidaÃ§Ã£o dos dados inseridos//
    v1=validarnome(Professores[qtd].nome);
    v2=validardtnasc(Professores[qtd].dtnasc.dia,Professores[qtd].dtnasc.mes,Professores[qtd].dtnasc.ano);
    v3=validarcpf(Professores[qtd].CPF);
    v4=validarsexo(Professores[qtd].sexo);
    v5=validarmatricula(Professores[qtd].matricula);
    
    if(v1==1 && v2==1 && v3==1 && v4==1 && v5==1)
    {
        printf("\nMATRICULA CONCLUIDA\n");
        return 1;
    }
    if(v1==0)
        printf("\nERRO_NOME_INVALIDO\n");
    if(v2==0)
        printf("\nERRO_DATA_INVALIDA\n");
    if(v3==0)
        printf("\nERRO_CPF_INVALIDO\n");
    if(v4==0)
        printf("\nERR0_SEXO_INVALIDO\n");
    if(v5==0)
        printf("\nERRO_MATRICULA_INVALIDA\n");

    Professores[qtd].matricula=-1;
    return 0;
    
}

int validarnome(char nm[])
{
    int tam;
    tam=strlen(nm);
    if(tam>10)
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
            if(m==2)
        	{
        		if(a%4==0 && a%100!=0)
        		{
        			if (d>=30)
        				return 0;
				}
				else if (d>=29)
					return 0;
			}
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
    if(mat>=-1)
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
        {
            printf("%d. Nome: %s\n",x+1,Alunos[x].nome);
            printf("Matricula: %d\n",Alunos[x].matricula);
            printf("Data de Nascimento : %d/%d/%d\n",Alunos[x].dtnasc.dia,Alunos[x].dtnasc.mes,Alunos[x].dtnasc.ano);
            printf("CPF : %s\n",Alunos[x].CPF);
            printf("Sexo : %c\n",Alunos[x].sexo);
            printf("\n");
        }
    }
}

void listar_Professor(Lista_Prof Professores[])
{
    int x;
    
    for(x=0;x<TAMANHO_LISTA;x++)
    {
        if(Professores[x].matricula!=-1)
        {
            printf("%d. Nome: %s\n",x+1,Professores[x].nome);
            printf("Matricula: %d\n",Professores[x].matricula);
            printf("Data de Nascimento : %d/%d/%d\n",Professores[x].dtnasc.dia,Professores[x].dtnasc.mes,Professores[x].dtnasc.ano);
            printf("CPF : %s\n",Professores[x].CPF);
            printf("Sexo : %c\n",Professores[x].sexo);
            printf("\n");
        }
    }
}

void status_aluno(Lista_aluno Alunos[])
{
    int x;
    
    for(x=0;x<TAMANHO_LISTA;x++)
        Alunos[x].matricula = -1;
}

void status_Professor(Lista_Prof Professores[])
{
    int x;
    
    for(x=0;x<TAMANHO_LISTA;x++)
        Professores[x].matricula = -1;
}

void retirar_aluno(int qtd, Lista_aluno Alunos[])
{
    int del;
    int cont;
    printf("Informe o numero do Aluno\n");
    listar_aluno(Alunos);
    scanf("%d",&del);
    if(del>qtd||del<1)
    {
        printf("\nNUMERO INVALIDO\n");
        return;
    }
    del--;
    for(cont=del;Alunos[cont].matricula!=-1;cont++)
    {
        Alunos[cont].matricula=Alunos[cont+1].matricula;
        Alunos[cont].sexo=Alunos[cont+1].sexo;
        Alunos[cont].dtnasc.dia=Alunos[cont+1].dtnasc.dia;
        Alunos[cont].dtnasc.mes=Alunos[cont+1].dtnasc.mes;
        Alunos[cont].dtnasc.ano=Alunos[cont+1].dtnasc.ano;
        strcpy(Alunos[cont].nome,Alunos[cont+1].nome);
        strcpy(Alunos[cont].CPF,Alunos[cont+1].CPF);
    }
}

void retirar_Professor(int qtd, Lista_Prof Professores[])
{
    int del;
    int cont;
    printf("Informe o numero do Professor\n");
    listar_Professor(Professores);
    scanf("%d",&del);
    if(del>qtd||del<1)
    {
        printf("\nNUMERO INVALIDO\n");
        return;
    }
    del--;
    for(cont=del;Professores[cont].matricula!=-1;cont++)
    {
        Professores[cont].matricula=Professores[cont+1].matricula;
        Professores[cont].sexo=Professores[cont+1].sexo;
        Professores[cont].dtnasc.dia=Professores[cont+1].dtnasc.dia;
        Professores[cont].dtnasc.mes=Professores[cont+1].dtnasc.mes;
        Professores[cont].dtnasc.ano=Professores[cont+1].dtnasc.ano;
        strcpy(Professores[cont].nome,Professores[cont+1].nome);
        strcpy(Professores[cont].CPF,Professores[cont+1].CPF);
    }
}

void alterar_aluno(int qtd, Lista_aluno Alunos[])
{
    int alt;
    int op;
    int ver;
    int altnum,altdia,altmes,altano;
    char altname[50];
    char altchar;
    
    printf("Informe o Aluno que quer alterar\n");
    listar_aluno(Alunos);
    scanf("%d",&alt);
    if(alt>qtd||alt<1)
    {
        while(alt>qtd||alt<1)
        {
            printf("NUMERO INVALIDO\n");
            scanf("%d",&alt);
        }
    }
    alt--;
    printf("Informe que dado alterar\n");
    printf("1.Matricula\n");
    printf("2.Nome\n");
    printf("3.Data de Nascimento\n");
    printf("4.CPF\n");
    printf("5.Sexo\n");
    scanf("%d",&op);
    getchar();
    
    switch(op)
    {
        case 1:
        {
            printf("Informe a nova matricula\n");
            scanf("%d",&altnum);
            ver=validarmatricula(altnum);
            if(ver==1)
            {
                Alunos[alt].matricula=altnum;
                printf("\n###ALTERAÇÃO REALIZADA COM SUCESSO###\n");
                break;
            }
            else
            {
                printf("\n###ERRO_MATRICULA_INVALIDA###\n");
                break;
            }
        }
        case 2:
        {
            printf("Informe o novo nome\n");
            fgets(altname,50,stdin);
            size_t ln= strlen(altname)-1;
            if(altname[ln]=='\n')
                altname[ln]='\0';    
            ver=validarnome(altname);
            if(ver==1)
            {
                strcpy(Alunos[alt].nome,altname);
                printf("\n###ALTERAÇÃO REALIZADA COM SUCESSO###\n");
                break;
            }
            else
            {
                printf("\n###ERRO_NOME_INVALIDO###\n");
                break;
            }
        }
        case 3:
        {
            printf("Informe a nova Data de Nascimento\n");
            printf("Dia:\n");
            scanf("%d",&altdia);
            printf("Mes:\n");
            scanf("%d",&altmes);    
            printf("Ano:\n");
            scanf("%d",&altano);
            ver=validardtnasc(altdia,altmes,altano);
            if(ver==1)
            {
                Alunos[alt].dtnasc.dia=altdia;
                Alunos[alt].dtnasc.mes=altmes;
                Alunos[alt].dtnasc.ano=altano;
                printf("\n###ALTERAÇÃO REALIZADA COM SUCESSO###\n");
                break;
            }
            else
            {
                printf("\n###ERRO_DATA_INVALIDA###\n");
                break;
            }
        }
        case 4:
        {
            printf("Informe o novo CPF\n");
            fgets(altname,50,stdin);
            size_t ln= strlen(altname)-1;
            if(altname[ln]=='\n')
                altname[ln]='\0';    
            ver=validarcpf(altname);
            if(ver==1)
            {
                strcpy(Alunos[alt].CPF,altname);
                printf("\n###ALTERAÇÃO REALIZADA COM SUCESSO###\n");
                break;
            }
            else
            {
                printf("\n###ERRO_CPF_INVALIDO###\n");
                break;
            }
        } 
        case 5:
        {
            printf("Informe o novo sexo\n");
            scanf("%c",&altchar);
            ver=validarsexo(altchar);
            if(ver==1)
            {
                Alunos[alt].sexo=altchar;
                printf("\n###ALTERAÇÃO REALIZADA COM SUCESSO###\n");
                break;
            }
            else
            {
                printf("\n###ERRO_SEXO_INVALIDA###\n");
                break;
            }
        }
    }
}

void alterar_professor(int qtd, Lista_Prof Professores[])
{
    int alt;
    int op;
    int ver;
    int altnum,altdia,altmes,altano;
    char altname[50];
    char altchar;
    
    printf("Informe o Professor que quer alterar:\n");
    listar_Professor(Professores);
    scanf("%d",&alt);
    if(alt>qtd||alt<1)
    {
        while(alt>qtd||alt<1)
        {
            printf("NUMERO INVALIDO\n");
            scanf("%d",&alt);
        }
    }
    alt--;
    printf("Informe que dado alterar:\n");
    printf("1.Matricula\n");
    printf("2.Nome\n");
    printf("3.Data de Nascimento\n");
    printf("4.CPF\n");
    printf("5.Sexo\n");
    scanf("%d",&op);
    getchar();
    
    switch(op)
    {
        case 1:
        {
            printf("Informe a nova matricula\n");
            scanf("%d",&altnum);
            ver=validarmatricula(altnum);
            if(ver==1)
            {
                Professores[alt].matricula=altnum;
                printf("\n###ALTERAÇÃO REALIZADA COM SUCESSO###\n");
                break;
            }
            else
            {
                printf("\n###ERRO_MATRICULA_INVALIDA###\n");
                break;
            }
        }
        case 2:
        {
            printf("Informe o novo nome\n");
            fgets(altname,50,stdin);
            size_t ln= strlen(altname)-1;
            if(altname[ln]=='\n')
                altname[ln]='\0';    
            ver=validarnome(altname);
            if(ver==1)
            {
                strcpy(Professores[alt].nome,altname);
                printf("\n###ALTERAÇÃO REALIZADA COM SUCESSO###\n");
                break;
            }
            else
            {
                printf("\n###ERRO_NOME_INVALIDO###\n");
                break;
            }
        }
        case 3:
        {
            printf("Informe a nova Data de Nascimento\n");
            printf("Dia:\n");
            scanf("%d",&altdia);
            printf("Mes:\n");
            scanf("%d",&altmes);    
            printf("Ano:\n");
            scanf("%d",&altano);
            ver=validardtnasc(altdia,altmes,altano);
            if(ver==1)
            {
                Professores[alt].dtnasc.dia=altdia;
                Professores[alt].dtnasc.mes=altmes;
                Professores[alt].dtnasc.ano=altano;
                printf("\n###ALTERAÇÃO REALIZADA COM SUCESSO###\n");
                break;
            }
            else
            {
                printf("\n###ERRO_DATA_INVALIDA###\n");
                break;
            }
        }
        case 4:
        {
            printf("Informe o novo CPF\n");
            fgets(altname,50,stdin);
            size_t ln= strlen(altname)-1;
            if(altname[ln]=='\n')
                altname[ln]='\0';    
            ver=validarcpf(altname);
            if(ver==1)
            {
                strcpy(Professores[alt].CPF,altname);
                printf("\n###ALTERAÇÃO REALIZADA COM SUCESSO###\n");
                break;
            }
            else
            {
                printf("\n###ERRO_CPF_INVALIDO###\n");
                break;
            }
        } 
        case 5:
        {
            printf("Informe o novo sexo\n");
            scanf("%c",&altchar);
            ver=validarsexo(altchar);
            if(ver==1)
            {
                Professores[alt].sexo=altchar;
                printf("\n###ALTERAÇÃO REALIZADA COM SUCESSO###\n");
                break;
            }
            else
            {
                printf("\n###ERRO_SEXO_INVALIDA###\n");
                break;
            }
        }
    }
}

void listar_aluno_sexo(Lista_aluno Alunos[])
{
    int x, aux;
    
    printf("\nSexo Feminino:\n");
    for(x=0,aux=1;x<TAMANHO_LISTA;x++)
    {
        if(Alunos[x].sexo=='f' || Alunos[x].sexo=='F') 
        {
            printf("%d.%s\n",aux,Alunos[x].nome);
            printf("\n");
            aux++;
        }
    }
    printf("\nSexo Masculino:\n");

    for(x=0,aux=1;x<TAMANHO_LISTA;x++)
    {
        if(Alunos[x].sexo=='m' || Alunos[x].sexo=='M') 
        {
            printf("%d.%s\n",aux,Alunos[x].nome);
            printf("\n");
            aux++;
        }
    }

    printf("\nSexo Outro:\n");

    for(x=0,aux=1;x<TAMANHO_LISTA;x++)
    {
        if(Alunos[x].sexo=='o' || Alunos[x].sexo=='O') 
        {
            printf("%d.%s\n",aux,Alunos[x].nome);
            printf("\n");
            aux++;
        }
    }
}

void listar_Professor_sexo(Lista_Prof Professores[])
{
    int x, aux;
    
    printf("\nSexo Feminino:\n");
    for(x=0,aux=1;x<TAMANHO_LISTA;x++)
    {
        if(Professores[x].sexo=='f' || Professores[x].sexo=='F') 
        {
            printf("%d.%s\n",aux,Professores[x].nome);
            printf("\n");
            aux++;
        }
    }
    printf("\nSexo Masculino:\n");

    for(x=0,aux=1;x<TAMANHO_LISTA;x++)
    {
        if(Professores[x].sexo=='m' || Professores[x].sexo=='M') 
        {
            printf("%d.%s\n",aux,Professores[x].nome);
            printf("\n");
            aux++;
        }
    }

    printf("\nSexo Outro:\n");

    for(x=0,aux=1;x<TAMANHO_LISTA;x++)
    {
        if(Professores[x].sexo=='o' || Professores[x].sexo=='O') 
        {
            printf("%d.%s\n",aux,Professores[x].nome);
            printf("\n");
            aux++;
        }
    }
}

void aniversariantes(int mesAtual, int qtdAlunos, Lista_aluno Alunos[], int qtdProf, Lista_Prof Professores[])
{
    int x;

    printf("\n###ANIVERSARIANTES DO MES###\n");

    for(x=0;x<qtdAlunos;x++)
    {
        if(Alunos[x].dtnasc.mes==mesAtual)
        {
            printf("%s\n",Alunos[x].nome);
        }
    }
    for(x=0;x<qtdProf;x++)
    {
        if(Professores[x].dtnasc.mes==mesAtual)
        {
            printf("%s\n",Professores[x].nome);
        }
    }
    printf("\n");
}

/*void listar_aluno_data(int qtd, Lista_aluno Alunos[])
{
    int x, y, j, menor;
    Lista_aluno ordem[TAMANHO_LISTA], aux;
    //fazendo uma copia dos alunos
    for(x=0;x<qtd;x++)
    {
        ordem[x].dtnasc.ano=Alunos[x].dtnasc.ano;
        ordem[x].dtnasc.mes=Alunos[x].dtnasc.mes;
        ordem[x].dtnasc.dia=Alunos[x].dtnasc.dia;
        strcpy(ordem[x].nome,Alunos[x].nome);
    }
    //ordenando anos
    for(x=0;x<qtd;x++)
    {
        menor=ordem[x].dtnasc.ano;
        for(y=x;x<qtd;x++)
            if(ordem[y].dtnasc.ano<menor)
                menor=y;
        
        aux.dtnasc.ano=ordem[y].dtnasc.ano;
        aux.dtnasc.mes=ordem[y].dtnasc.mes;
        aux.dtnasc.dia=ordem[y].dtnasc.dia;
        strcpy(aux.nome,ordem[y].nome);

        ordem[y].dtnasc.ano=ordem[x].dtnasc.ano;
        ordem[y].dtnasc.mes=ordem[x].dtnasc.mes;
        ordem[y].dtnasc.dia=ordem[x].dtnasc.dia;
        strcpy(ordem[y].nome,ordem[x].nome);

        ordem[x].dtnasc.ano=aux.dtnasc.ano;
        ordem[x].dtnasc.mes=aux.dtnasc.mes;
        ordem[x].dtnasc.dia=aux.dtnasc.dia;
        strcpy(ordem[x].nome,aux.nome);
    }
    //ordenando os meses
    for(x=0;x<qtd;x++)
    {
        menor=ordem[x].dtnasc.mes;
        for(y=x;x<qtd;x++)
            if(ordem[y].dtnasc.ano==ordem[x].dtnasc.ano)
                if(ordem[y].dtnasc.mes<menor)
                    menor=ordem[y].dtnasc.mes;
        
        aux.dtnasc.ano=ordem[y].dtnasc.ano;
        aux.dtnasc.mes=ordem[y].dtnasc.mes;
        aux.dtnasc.dia=ordem[y].dtnasc.dia;
        strcpy(aux.nome,ordem[y].nome);
            
        ordem[y].dtnasc.ano=ordem[x].dtnasc.ano;
        ordem[y].dtnasc.mes=ordem[x].dtnasc.mes;
        ordem[y].dtnasc.dia=ordem[x].dtnasc.dia;
        strcpy(ordem[y].nome,ordem[x].nome);

        ordem[x].dtnasc.ano=aux.dtnasc.ano;
        ordem[x].dtnasc.mes=aux.dtnasc.mes;
        ordem[x].dtnasc.dia=aux.dtnasc.dia;
        strcpy(ordem[x].nome,aux.nome);
    }
    //ordenando os dias
    for(x=0;x<qtd;x++)
    {
        menor=ordem[x].dtnasc.dia;
        for(y=x;x<qtd;x++)
            if(ordem[y].dtnasc.ano==ordem[x].dtnasc.ano)
                if(ordem[y].dtnasc.mes==ordem[x].dtnasc.mes)
                    if(ordem[y].dtnasc.dia<menor)
                        menor=ordem[y].dtnasc.dia;

            aux.dtnasc.ano=ordem[y].dtnasc.ano;
            aux.dtnasc.mes=ordem[y].dtnasc.mes;
            aux.dtnasc.dia=ordem[y].dtnasc.dia;
            strcpy(aux.nome,ordem[y].nome);
            
            ordem[y].dtnasc.ano=ordem[x].dtnasc.ano;
            ordem[y].dtnasc.mes=ordem[x].dtnasc.mes;
            ordem[y].dtnasc.dia=ordem[x].dtnasc.dia;
            strcpy(ordem[y].nome,ordem[x].nome);

            ordem[x].dtnasc.ano=aux.dtnasc.ano;
            ordem[x].dtnasc.mes=aux.dtnasc.mes;
            ordem[x].dtnasc.dia=aux.dtnasc.dia;
            strcpy(ordem[x].nome,aux.nome);
    }
    //Lista Final
    for(x=0,j=1;x<qtd;x++,j++)
        printf("%d.%s\n",j,ordem[x].nome);
}*/