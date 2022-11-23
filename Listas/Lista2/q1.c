/*Considere uma lista de valores inteiros e implemente um algorit-
mo que receba como parâmetro dois valores (n1 e n2) e uma lista, e insira o
valor n2 após o nodo que contém o valor n1.*/
#include <stdio.h>
#include <stdlib.h>
#define max 5

typedef struct{
    int qtd;
    int valores[max];
}lista;

void insertElementos(int n1, int n2, lista *Lista);
void printaLista(lista *Lista);

int main(){
    lista *Lista;
    Lista = (lista*) malloc(sizeof(lista));
    Lista->qtd = 0;
    int n1 = 5, n2 = 7;

    insertElementos(n1, n2, Lista);
    printaLista(Lista);
    return 0;
}

void insertElementos(int n1, int n2, lista *Lista){
    Lista->valores[Lista->qtd] = n1;
    Lista->qtd++;
    Lista->valores[Lista->qtd] = n2;
}

void printaLista(lista *Lista){
    for(int i = 0; i <= Lista->qtd; i++){
        printf("[%d] ", Lista->valores[i]);
    }
}