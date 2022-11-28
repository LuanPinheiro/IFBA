/*Implemente um algoritmo que receba como parâmetro um pon-
teiro para o primeiro nodo de uma lista encadeada e dois valores, e retorne a
lista resultante da troca de todas as ocorrências do primeiro valor pelo segun-
do, ambos passados como parâmetros, e o número total de trocas efetuadas.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int valor;
    struct node *prox;
}node;

int q11(node *inicioLista, int valor1, int valor2);
node* adicionarNodo(node *nodoAnterior, int valor);
void preencheLista(node *inicioLista);
void printaLista(node *inicioLista);
void liberaLista(node *inicioLista);

int main(){
    node *inicioLista = malloc(sizeof(node));
    int valor1 = 5, valor2 = 9;

    preencheLista(inicioLista);
    q11(inicioLista, valor1, valor2);
    printaLista(inicioLista);
    liberaLista(inicioLista);
    return 0;
}

int q11(node *inicioLista, int valor1, int valor2){
    node *nodo = inicioLista;
    node *nodoTroca;
    int qtdTrocas = 0;

    while(nodo){
        if(nodo->valor == valor1){
            nodoTroca = nodo;
            while(nodoTroca){
                if(nodoTroca->valor == valor2){
                    nodo->valor = nodoTroca->valor;
                    qtdTrocas++;
                    break;
                }
                if(nodoTroca->prox == NULL){
                    break;
                }
                nodoTroca = nodoTroca->prox;
            }
        }
        if(nodo->prox == NULL){
            break;
        }
        nodo = nodo->prox;
    }

    printf("Foram realizadas %d trocas\n", qtdTrocas);

    return qtdTrocas;
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