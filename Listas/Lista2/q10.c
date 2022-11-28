/*Construa um algoritmo que receba, como parâmetro, o ende-
reço do primeiro nodo de uma lista encadeada e um valor. O algoritmo deve
retornar: o número total de nodos da lista; o número de nodos da lista que
possuem em seu conteúdo o valor passado como parâmetro e sua respectiva
posição na lista; e o número de nodos que possuem em seu conteúdo valores
maiores do que o valor passado como parâmetro.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int valor;
    struct node *prox;
}node;

typedef struct{
    int qtdNodos;
    int repeticaoValor;
    int *repeticaoPosicoes;
    int qtdNodosMaiorQueParam;
}retornoF;

retornoF q10(node *inicioLista, int valor);
node* adicionarNodo(node *nodoAnterior, int valor);
void preencheLista(node *inicioLista);
void printaLista(node *inicioLista);
void liberaLista(node *inicioLista);

int main(){
    node *inicioLista = malloc(sizeof(node));
    retornoF retorno;
    int valor = 5;

    preencheLista(inicioLista);
    retorno = q10(inicioLista, valor);
    printaLista(inicioLista);
    liberaLista(inicioLista);
    return 0;
}

retornoF q10(node *inicioLista, int valor){
    retornoF retorno;
    node *nodo = inicioLista;
    retorno.qtdNodos = 0;
    retorno.repeticaoValor = 0;
    retorno.qtdNodosMaiorQueParam = 0;
    retorno.repeticaoPosicoes = malloc(sizeof(int));
    int tamRep = 0;

    while(nodo){
        // Nodo com mesmo valor do parâmetro e sua respectiva posição
        if(nodo->valor == valor){
            retorno.repeticaoValor++;
            retorno.repeticaoPosicoes[tamRep] = retorno.qtdNodos;
            tamRep++;
            retorno.repeticaoPosicoes = realloc(retorno.repeticaoPosicoes, sizeof(int)*(tamRep+1));
        }
        // Nodo com valor maior que o parâmetro
        if(nodo->valor > valor){
            retorno.qtdNodosMaiorQueParam++;
        }
        // Quantidade total de nodos
        retorno.qtdNodos++;
        if(nodo->prox == NULL){
            break;
        }
        nodo = nodo->prox;
    }

    printf("Quantidade de Nodos: %d\n", retorno.qtdNodos);
    printf("Quantidade de Nodos maior que Parametro: %d\n", retorno.qtdNodosMaiorQueParam);
    printf("Quantidade de Repeticoes do Parametro: %d\n", retorno.repeticaoValor);
    printf("Posicoes das Repeticoes: ");
    nodo = inicioLista;
    for(int i = 0; i < retorno.repeticaoValor; i++){
        printf("[%d] ", retorno.repeticaoPosicoes[i]);
    }
    printf("\n");

    return retorno;
}

void preencheLista(node *inicioLista){
    node *nodoAnterior = inicioLista;
    nodoAnterior->valor = 0;
    int qtdNodos = 10;
    for(int i = 1; i < qtdNodos; i++){
        nodoAnterior = adicionarNodo(nodoAnterior, i);
    }
}

void printaLista(node *inicioLista){
    node *node = inicioLista;
    printf("Lista completa: ");
    while(node){
        printf("[%d] ", node->valor);
        if(node->prox == NULL){
            break;
        }
        node = node->prox;
    }
}

node* adicionarNodo(node *nodoAnterior, int valor){
    node *nodoNovo = malloc(sizeof(node));
    nodoNovo->valor = valor;
    nodoNovo->prox = NULL;
    nodoAnterior->prox = nodoNovo;
    return nodoNovo;
}

void liberaLista(node *inicioLista){
    node *nodoAtual = inicioLista;
    node *proxNodo;
    
    while(nodoAtual){
        proxNodo = nodoAtual->prox;
        free(nodoAtual);
        if(proxNodo->prox == NULL){
            free(proxNodo);
            break;
        }
        nodoAtual = proxNodo;
    } 
}