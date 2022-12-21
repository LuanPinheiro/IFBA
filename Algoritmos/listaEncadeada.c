#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no *proximo;
}no;

typedef struct lista{
    no *inicio;
    int tam;
}lista;

void inserirInicio(no **inicioLista, int valor);
void inserirMeio(no **inicioLista, int valor, int referencia);
void inserirFim(no **inicioLista, int valor);
void inserirOrdenado(no **inicioLista, int valor);

void removerInicio();
void removerMeio();
void removerFim();

void busca();

int main(){
    lista *inicioLista = NULL;
    return 0;
}

void inserirInicio(no **inicioLista, int valor){
    no *novo = malloc(sizeof(no));

    if(novo){
        novo->dado = valor;
        novo->proximo = *inicioLista;
        *inicioLista = novo;
    }
    else{
        printf("Erro ao Alocar a Memoria");
    }
}

// Insere após o elemento referência, caso não encontre o valor referência irá inserir no fim
void inserirMeio(no **inicioLista, int valor, int referencia){
    no *aux, *novo = malloc(sizeof(no));

    if(novo){
        novo->dado = valor;
        if(*inicioLista){
            aux = *inicioLista;
            while(aux->dado != referencia && aux->proximo){
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
        else{
            novo->proximo = NULL;
            *inicioLista = novo;
        }
    }
    else{
        printf("Erro ao Alocar a Memoria");
    }
}

void inserirFim(no **inicioLista, int valor){
    no *aux, *novo = malloc(sizeof(no));

    if(novo){
        novo->dado = valor;
        novo->proximo = NULL;
        
        // Caso a lista tenha elementos, irá percorrer a lista até o fim, caso esteja vazia, o novo nó é o começo
        if(*inicioLista){
            aux = *inicioLista;
            while(aux->proximo){
                aux = aux->proximo;
            }
            aux->proximo = novo;
        }
        else{
            *inicioLista = novo;
        }
    }
    else{
        printf("Erro ao Alocar a Memoria");
    }
}

void printaLista(no *listaCompleta){
    printf("Lista completa: ");
    while(listaCompleta){
        printf("[%d] ", listaCompleta->valor);
        listaCompleta = listaCompleta->prox;
    }
}

void inserirOrdenado(no **inicioLista, int valor){
    no *aux, *novo = malloc(sizeof(no));

    if(novo){
        novo->dado = valor;
        if(*inicioLista){
            if(valor < (*inicioLista)->dado){
                novo->proximo = *inicioLista;
                *inicioLista = novo;
            }
            else{
                aux = *inicioLista;
                while(aux->proximo && (aux->proximo->dado < valor)){
                    aux = aux->proximo;
                }
                novo->proximo = aux->proximo;
                aux->proximo = novo;
            }
        }
        else{
            novo->proximo = NULL;
            *inicioLista = novo;
        }
        novo->proximo = *inicioLista;
    }
    else{
        printf("Erro ao Alocar a Memoria");
    }
}