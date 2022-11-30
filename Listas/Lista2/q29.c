/*Uma maneira usual de representar conjuntos é listando seus
elementos. Implemente uma aplicação que ofereça as operações usuais de
conjuntos (união, intersecção e diferença), considerando que cada um dos
conjuntos é representado por uma lista encadeada.*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int valor;
    struct node *prox;
}node;

void criarConjunto1(node *conjunto);
void criarConjunto2(node *conjunto);
void criarConjunto3(node *conjunto);
void liberaLista(node *inicioLista);
node* unirConjuntos(node *conjunto1, node *conjunto2);
node* intersecaoConjuntos(node *conjunto1, node *conjunto2);
node* diferencaConjuntos(node *conjunto1, node *conjunto2);
node* adicionarNodo(node *nodoAnterior, int valor);
void printaConjunto(node *conjunto);
int repetido(node *conjunto1, int valor);

int main(){
    node *conjunto1 = malloc(sizeof(node));
    node *conjunto2 = malloc(sizeof(node));
    node *conjunto3 = malloc(sizeof(node));

    criarConjunto1(conjunto1);
    criarConjunto2(conjunto2);
    criarConjunto3(conjunto3);

	printf("OBS: Os conjuntos envolvidos nas operacoes se tornam iguais apos as modificacoes\n");
    conjunto1 = unirConjuntos(conjunto1, conjunto2);
    conjunto2 = conjunto1;
    printf("\nConjuntos 1 e 2 unidos");
    printaConjunto(conjunto1);

    conjunto2 = intersecaoConjuntos(conjunto2,conjunto3);
    conjunto3 = conjunto2;
    printf("\n\nIntersecao dos conjuntos 2 e 3");
    printaConjunto(conjunto2);

    conjunto1 = diferencaConjuntos(conjunto1, conjunto3);
	conjunto3 = conjunto1;
	printf("\n\nDiferenca dos conjuntos 1 e 3");
	printaConjunto(conjunto1);

    liberaLista(conjunto1);
    liberaLista(conjunto2);
    return 0;
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

void criarConjunto1(node *conjunto){
    node *nodo = malloc(sizeof(node));
    node *nodo2 = malloc(sizeof(node));

    conjunto->valor = 5;
    conjunto->prox = nodo;

    nodo->valor = 7;
    nodo->prox = nodo2;

    nodo2->valor = 2;
    nodo2->prox = NULL;
}

void criarConjunto2(node *conjunto){
    node *nodo = malloc(sizeof(node));
    node *nodo2 = malloc(sizeof(node));

    conjunto->valor = 10;
    conjunto->prox = nodo;

    nodo->valor = 5;
    nodo->prox = nodo2;

    nodo2->valor = 3;
    nodo2->prox = NULL;
}

void criarConjunto3(node *conjunto){
    node *nodo = malloc(sizeof(node));
    node *nodo2 = malloc(sizeof(node));

    conjunto->valor = 3;
    conjunto->prox = nodo;

    nodo->valor = 20;
    nodo->prox = nodo2;

    nodo2->valor = 5;
    nodo2->prox = NULL;
}

// Conjuntos 1 e 2 se tornarão o mesmo conjunto unido no final
node* unirConjuntos(node *conjunto1, node *conjunto2){
    node *nodoFinal = conjunto1;

    while(conjunto1){
        if(nodoFinal->prox == NULL){
            break;
        }
        nodoFinal = nodoFinal->prox;
    }

    while(conjunto2){
        if(repetido(conjunto1, conjunto2->valor) != true){
            adicionarNodo(nodoFinal, conjunto2->valor);
            nodoFinal = nodoFinal->prox;
        }
        if(conjunto2->prox == NULL){
            break;
        }
        conjunto2 = conjunto2->prox;
    }

    return conjunto1;
}

node* intersecaoConjuntos(node *conjunto1, node *conjunto2){
    node *conjuntoFinal = malloc(sizeof(node));
    node *nodoFinal = conjuntoFinal;
    node *nodoAnterior;
    
    while(conjunto2){
        if(repetido(conjunto1, conjunto2->valor) == true){
            nodoFinal->valor = conjunto2->valor;
            nodoFinal->prox = malloc(sizeof(node));
            nodoAnterior = nodoFinal;
            nodoFinal = nodoFinal->prox;
        }
        if(conjunto2->prox == NULL){
            break;
        }
        conjunto2 = conjunto2->prox;
    }
    nodoAnterior->prox = NULL;

    return conjuntoFinal;
}

node* diferencaConjuntos(node *conjunto1, node *conjunto2){
	node *conjuntoFinal = malloc(sizeof(node));
    node *nodoFinal = conjuntoFinal;
    node *nodoAnterior;
	node *nodoC1 = conjunto1; // Para percorrer a lista corretamente no segundo while
    
	while(nodoC1){
        if(repetido(conjunto2, nodoC1->valor) == false){
            nodoFinal->valor = nodoC1->valor;
            nodoFinal->prox = malloc(sizeof(node));
            nodoAnterior = nodoFinal;
            nodoFinal = nodoFinal->prox;
        }
        if(nodoC1->prox == NULL){
            break;
        }
        nodoC1 = nodoC1->prox;
    }
	
	while(conjunto2){
        if(repetido(conjunto1, conjunto2->valor) == false){
            nodoFinal->valor = conjunto2->valor;
            nodoFinal->prox = malloc(sizeof(node));
            nodoAnterior = nodoFinal;
            nodoFinal = nodoFinal->prox;
        }
        if(conjunto2->prox == NULL){
            break;
        }
        conjunto2 = conjunto2->prox;
    }
    nodoAnterior->prox = NULL;

    return conjuntoFinal;
}

node* adicionarNodo(node *nodoAnterior, int valor){
    node *nodoNovo = malloc(sizeof(node));
    nodoNovo->valor = valor;
    nodoNovo->prox = NULL;
    nodoAnterior->prox = nodoNovo;
    return nodoNovo;
}

void printaConjunto(node *conjunto){
    node *node = conjunto;
    printf("\nConjunto completo: ");
    while(node){
        printf("[%d] ", node->valor);
        if(node->prox == NULL){
            break;
        }
        node = node->prox;
    }
}

int repetido(node *conjunto1, int valor){
    node *nodoC1 = conjunto1;

    while(nodoC1){
        if(nodoC1->valor == valor){
            return true;
        }
        if(nodoC1->prox == NULL){
            break;
        }
        nodoC1 = nodoC1->prox;
    }
    return false;
}