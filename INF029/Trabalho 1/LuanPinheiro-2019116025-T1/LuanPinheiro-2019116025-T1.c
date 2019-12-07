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

int main(){
    int options=1, retorno;
    char data[10];

    while(options!=0)
    {
        printf("0.Fechar o Programa\n");
        printf("1.Questão 1\n");
        printf("2.Questão 2\n");
        printf("3.Questão 3\n");
        printf("4.Questão 4\n");
        printf("5.Questão 5\n");
        printf("6.Questão 6\n");

        scanf("%d",&options);
        getchar();
        switch(options)
        {
            case 0: return 0; break;
            case 1: strcpy(data,"1/1/200");
                    retorno = q1(data);
                    if(retorno==0)
                        printf("Data Invalida\n");
                    else
                        printf("Data Valida\n");
                    break;
            //case 2: q2(); break;
            //case 3: q3(); break;
            //case 4: q4(); break;
            //case 5: q5(); break;
            //case 6: q6(); break;
        }
    }
}
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
int q1(char data[]){

    int i, j, intDia, intMes, intAno;
    char strDia[3], strMes[3], strAno[3];

    if(strlen(data)>10)
        return 0;
    else
    {
        for(i=0;data[i]!='/';i++)
        {
            strDia[i]=data[i];
            if(i>1)
                return 0;
            else if(strDia[i]>57 && strDia[i]<48)
                return 0;
        }

        strDia[i]='\0';
        if(strlen(strDia) == 0)
            return 0;
        intDia = atoi(strDia);
        i++;

        for(j=0;data[i]!='/';i++,j++)
        {
            strMes[j]=data[i];
            if(j>1)
                return 0;
            else if(strMes[j]>57 && strDia[j]<48)
                return 0;
        }

        strMes[j] = '\0';
        if(strlen(strMes) == 0) 
            return 0;
        intMes = atoi(strMes); 
        i++;

        for(j=0;data[i]!='\0';i++,j++)
        {
            strAno[j]=data[i];
            if(j>3)
                return 0;
            else if(strAno[j]>57 && strAno[j]<48)
                return 0;
        }

        if(strlen(strAno) == 0 || j==1 || j==3) 
            return 0;
        intAno = atoi(strAno);

        return validaData(intDia,intMes,intAno); 
    }


    
    
    //printf("%s\n", data);
}

int validaData(int Dia, int Mes, int Ano)
{
    int Bissexto = 0;
    if ((Ano % 4 == 0) || (Ano % 400 == 0))
       Bissexto = 1;
    
    if(Bissexto=1)
    {
        if (Mes==1 || Mes==3 || Mes==5 || Mes==7 || Mes==8 || Mes==10 || Mes==12)
            if( Dia > 0 && Dia < 32)
               return 1;
        else if (Mes==2)
            if (Dia > 0 && Dia <30)
               return 1;
        else if (Mes==4 || Mes==6 || Mes==9 || Mes==11)
            if (Dia >0 && Dia < 31)
               return 1;
    }
    else
    {
        if ((Mes>0 && Mes<2) || (Mes>2 && Mes<13))
            if (Dia>0 && Dia<31)
                return 1;
        else if (Mes==2)
            if (Dia>0 && Dia<29)
                return 1;
    }
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
    int nDias, nMeses, nAnos;


    if (q1(datainicial) == 0)
        return 2;

    nDias = 4;
    nMeses = 10;
    nAnos = 2;




    /*mantenha o código abaixo, para salvar os dados em 
    nos parâmetros da funcao
    */
    *qtdDias = nDias;
    *qtdAnos = nAnos;
    *qtdMeses = nMeses;

    //coloque o retorno correto
    return 1;

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
    int qtdOcorrencias = -1;

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
    int qtdOcorrencias = -1;

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

int q5(int num){

    return num;
}

/*
 Q5 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca){
    int qtdOcorrencias;
    return qtdOcorrencias;
}