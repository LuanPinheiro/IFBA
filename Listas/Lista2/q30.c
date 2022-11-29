#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef struct node{
    int valor;
    struct node *prox;
}node;

void preencheLista(node *inicioLista);
node* adicionarNodo(node *nodoAnterior, int valor);
void eliminaEmCada3(node *inicioLista, int qtdRemocoes);

int main(){
	node *inicioLista = malloc(sizeof(node));
	int qtdRemocoes = 2;

	preencheLista(inicioLista);
	eliminaEmCada3(inicioLista, qtdRemocoes);
	free(inicioLista);
	return 0;
}

void preencheLista(node *inicioLista){
    node *nodoAnterior = inicioLista;
    nodoAnterior->valor = 1;
    int qtdNodos = 5;
    for(int i = 1; i < qtdNodos; i++){
        nodoAnterior = adicionarNodo(nodoAnterior, i+1);
    }
	nodoAnterior->prox = inicioLista;
}

node* adicionarNodo(node *nodoAnterior, int valor){
    node *nodoNovo = malloc(sizeof(node));
    nodoNovo->valor = valor;
    nodoNovo->prox = NULL;
    nodoAnterior->prox = nodoNovo;
    return nodoNovo;
}

void eliminaEmCada3(node *inicioLista, int qtdRemocoes){
	node *nodo = inicioLista;
	node *nodoAnterior;
	
	while(qtdRemocoes > 0){
		for(int i = 0; i < 2; i++){
			nodoAnterior = nodo;
			nodo = nodo->prox;
		}
		// 2 4 5
		nodoAnterior->prox = nodo->prox;
		nodo = nodo->prox;
		qtdRemocoes--;
	}

	node *inicio = nodo;
	while(nodo){
		printf("Vai ficar viva a pessoa %d\n", nodo->valor);
		nodo = nodo->prox;
		if(nodo == inicio){
			break;
		}
	}
	
}