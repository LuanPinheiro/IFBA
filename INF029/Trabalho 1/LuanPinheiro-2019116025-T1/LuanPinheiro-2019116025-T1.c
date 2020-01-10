// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Luan Pinheiro da Silva
//  email: luanp.soledade@gmail.com
//  Matrícula: 2019116025
//  Semestre: 2º

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 20/06/2018 - 19/08/2016

// #################################################

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LuanPinheiro-2019116025-T1.h"

/*
## função utilizada para testes  ##
 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y){
  int soma = 0;
  soma = x + y;
  return soma;
}

/*
## função utilizada para testes  ##
 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x){ //função utilizada para testes
  int fat = 1;
  return fat;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 */
int q1(char *data){
    
    inteirodata retorno;
    
    retorno = quantidadeData(data);

    return validaData(retorno.intDia,retorno.intMes,retorno.intAno); 
    //printf("%s\n", data);
}

int validaData(int Dia, int Mes, int Ano)
{
    int Bissexto = 0;
    if(( Ano%4==0 && Ano%100!=0) || Ano%400==0)
       Bissexto = 1;
    
    if(Bissexto==1)
    {
        if (Mes==1 || Mes==3 || Mes==5 || Mes==7 || Mes==8 || Mes==10 || Mes==12)
        {
            if( Dia > 0 && Dia < 32)
               return 1;
        }
        else 
        {
            if (Mes==2)
            {
                if (Dia > 0 && Dia <30)
                    return 1;
            }
            else
            {
                if (Mes==4 || Mes==6 || Mes==9 || Mes==11)
                    if (Dia >0 && Dia < 31)
                        return 1;
            }
        }
    }
    else
    {
        if ((Mes>0 && Mes<2) || (Mes>2 && Mes<13))
        {
            if (Dia>0 && Dia<31)
                return 1;
        }
        else
        {
            if (Mes==2)
                if (Dia>0 && Dia<29)
                    return 1;
        }
    }
    return 0;
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
 */
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos){
    
    //calcule os dados e armazene nas três variáveis a seguir
    int nDias=0, nMeses=0, nAnos=0;
    inteirodata retornoInicial, retornoFinal;

    retornoInicial = quantidadeData(datainicial);
    retornoFinal = quantidadeData(datafinal);
    if (retornoInicial.intDia == 0 || retornoInicial.intMes == 0 || retornoInicial.intAno == 0)
        return 2;
    else if (retornoFinal.intDia == 0 || retornoFinal.intMes == 0 || retornoFinal.intAno == 0)
        return 3;
    
    if(retornoInicial.intAno>retornoFinal.intAno)
        return 4;
    else
        if(retornoInicial.intAno==retornoFinal.intAno)
            if(retornoInicial.intMes>retornoFinal.intMes)
                return 4;
            else
                if(retornoInicial.intMes==retornoFinal.intMes)
                    if(retornoInicial.intDia>retornoFinal.intDia)
                        return 4;
    

    nAnos = retornoFinal.intAno - retornoInicial.intAno;
    if(retornoInicial.intMes>retornoFinal.intMes)
    {
        nAnos--;
        nMeses = (12-retornoInicial.intMes) + retornoFinal.intMes;
    }
    else
        nMeses = retornoFinal.intMes - retornoInicial.intMes;
    
    if(retornoInicial.intDia>retornoFinal.intDia)
        nMeses--;
    

    if(retornoInicial.intMes!=retornoFinal.intMes && retornoInicial.intDia>retornoFinal.intDia)
    {
        retornoInicial.intMes=retornoFinal.intMes-1;
        if(retornoInicial.intMes==0)
        {
            retornoInicial.intMes=12;
            retornoInicial.intAno = retornoFinal.intAno-1;
        }
        else
        {
            if((retornoInicial.intMes==1 || retornoInicial.intMes==3 || retornoInicial.intMes==5 || retornoInicial.intMes==7 || retornoInicial.intMes==8 || retornoInicial.intMes==10 || retornoInicial.intMes==12))
            {
                nDias = (31 - retornoInicial.intDia) + retornoFinal.intDia;
            }
            else
            {
                if (retornoInicial.intMes==4 || retornoInicial.intMes==6 || retornoInicial.intMes==9 || retornoInicial.intMes==11)
                {
                    nDias = (30 - retornoInicial.intDia) + retornoFinal.intDia;
                }
                else
                {
                    if((retornoInicial.intAno%4==0 && retornoInicial.intAno%100!=0) || retornoInicial.intAno%400==0)
                    {
                        if(retornoInicial.intMes == 2)
                        {
                            nDias = (29 - retornoInicial.intDia) + retornoFinal.intDia;
                        }
                    }
                    else
                    {
                        nDias = (28 - retornoInicial.intDia) + retornoFinal.intDia;
                    }
                }
            }
        }
    }
    else
        nDias = retornoFinal.intDia - retornoInicial.intDia;
    
    if(nAnos == -1)
        nAnos=0;
    if(nMeses == -1)
        nMeses=0;
    if(nDias == -1)
        nDias=0;
    

    printf("Diferenca de %d Anos, %d Meses e %d Dias\n",nAnos, nMeses, nDias);
    /*mantenha o código abaixo, para salvar os dados em 
    nos parâmetros da funcao*/
    *qtdDias = nDias;
    *qtdAnos = nAnos;
    *qtdMeses = nMeses;

    //coloque o retorno correto
    return 1;

}

inteirodata quantidadeData(char data[])
{
    inteirodata retorno;
    int i, j;
    char strDia[3], strMes[3], strAno[5];
    for(i=0;data[i]!='/';i++)
    {
        strDia[i]=data[i];
        if(i>1)
        {
            strcpy(strDia,"0");
            break;
        }
        else if(strDia[i]>57 && strDia[i]<48)
        {
            strcpy(strDia,"0");
            break;
        }
    }

    strDia[i]='\0';
    retorno.intDia = atoi(strDia);
    if(strlen(strDia) == 0)
        return retorno;
    i++;

    for(j=0;data[i]!='/';i++,j++)
    {
        strMes[j]=data[i];
        if(j>1)
        {
            strcpy(strMes,"0");
            break;
        }
        else if(strMes[j]>57 && strMes[j]<48)
        {
            strcpy(strMes,"0");
            break;
        }
    }

    strMes[j] = '\0';
    retorno.intMes = atoi(strMes);
    if(strlen(strMes) == 0) 
        return retorno;
    i++;

    for(j=0;data[i]!='\0';i++,j++)
    {
        strAno[j]=data[i];
        if(j>3)
        {
            strcpy(strDia,"0");
            break;
        }
        else if(strAno[j]>57 && strAno[j]<48)
        {
            strcpy(strDia,"0");
            break;
        }
    }

    strAno[j]='\0';
    retorno.intAno = atoi(strAno);
    if(strlen(strAno) == 0 || j==1 || j==3) 
       return retorno;
    
    if(validaData(retorno.intDia, retorno.intMes, retorno.intAno)==0)
        retorno.intDia=0;

    return retorno;
}


/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive){
    int qtdOcorrencias=0, i, tamanho;

    tamanho = strlen(texto);
    texto[tamanho]='\0';
    if (isCaseSensitive==1)
    {
        for(i=0;i<tamanho;i++)
            if (texto[i]==c)
                qtdOcorrencias++;
    }
    else
    {
        for(i=0;i<tamanho;i++)
        {
            if(texto[i]==c)
                qtdOcorrencias++;
            else
            {
                if(c>=65 && c<=90)
                {
                    if(texto[i]==c+32)
                        qtdOcorrencias++;
                }
                else if(c>=97 && c<=122)
                {
                    if(texto[i]==c-32)
                        qtdOcorrencias++;
                }
            }
        }
    }

    return qtdOcorrencias;

}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;
 */
int q4(char *strTexto, char *strBusca, int posicoes[30]){
    int qtdOcorrencias = 0, i, j, k, l, tamanho, tamanho2, mudou;

    tamanho=strlen(strTexto);
    tamanho2=strlen(strBusca);
    strTexto[tamanho]='\0';
    strBusca[tamanho2]='\0';

    for(i=0,l=0;i<tamanho;i++)
    {
        if(strTexto[i]==strBusca[0])
        {
            printf("ENTROU");
            for(j=0,k=i,mudou=1;j<tamanho2||k<tamanho-1;j++,k++)
            {
                printf("  strTexto[%d]:%c,strBusca[%d]:%c  ", k, strTexto[k], j, strBusca[j]);
                if(strTexto[k]!=strBusca[j])
                {
                    mudou=0;
                    printf("FALHOU ");
                    break;
                }
            }

            if(mudou!=0)
            {
                posicoes[l]=j-1;
                posicoes[l+1]=i;
                l+=2;
                qtdOcorrencias++;
                i=k;
            }
        }
    }
    for(i=0;i<l;i++)
    {
        //printf(" posicoes[%d]:%d\n ", i, posicoes[i]);
    }
    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
    int i, j, x, aux[200], final=0;
    char sNum[200];
    
    int ultimonumeroEhzero = 0;
    
    if (num/10 == 0) 
        ultimonumeroEhzero = 1;
    
    for(x=0;num!=0;x++)
    {
        aux[x]=num%10;
        num=num/10;
        printf("posicao:%d, Numero:%d\n",x,aux[x]);
    }
    
    for(i=0,j=x;i<x;i++,j--)
    {
            aux[i]=aux[i] * mypow(j);
            final+=aux[i];
            printf("FINAL:%d\n",final);
    }
    
    if(aux[i]!=0)
    {
        aux[i]=aux[i] * mypow(j);
        final+=aux[i];
        printf("FINAL:%d\n",final);
    }

    
    num=final;

    return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca){
    int qtdOcorrencias=0, i;
    
    for(i=0;(numerobusca/10)!=0;i++)
    {}
    
    return qtdOcorrencias;
}

int mypow(int j)
{
    int i, retorno=1;
    
    while(j>0)
    {
        retorno*=10;
        j--;
    }
        
    return retorno;
}
