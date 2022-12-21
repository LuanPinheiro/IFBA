#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no *proximo;
}no;

// Adiciona um novo elemento a uma pilha, estando ela vazia ou não, o topo se torna o novo elemento
void pilhaNovo(no **topo, int valor){
    no *novo = malloc(sizeof(no));

    if(novo){
        printf("Empilhado\n");
        novo->dado = valor;
        novo->proximo = *topo;
        *topo = novo;
    }
    else{
        printf("Erro na Alocacao\n");
    }
}

// Retira um elemento da pilha, e libera a memória do elemento removido
void pilhaRetira(no **topo){
    if(*topo){
        no *remover = *topo;
        *topo = remover->proximo;
        free(remover);
    }
    else{
        printf("Pilha Vazia\n");
    }
}

int main(){
    no *pilha1 = NULL, *pilha2 = NULL;
    pilhaNovo(&pilha1, 8);
    pilhaNovo(&pilha1, 4);
    pilhaNovo(&pilha1, 1);
    printf("\n");
    pilhaNovo(&pilha2, 9);
    pilhaNovo(&pilha2, 7);
    pilhaNovo(&pilha2, 6);
    pilhaNovo(&pilha2, 2);
    printaPilha(pilha1);
    printf("\n");
    printaPilha(pilha2);
    criaPilha3(pilha1, pilha2);
    return 0;
}

void printaPilha(no *pilha){
    no *aux = pilha;
    while(aux){
        printf("%d ", aux->dado);
        aux = aux->proximo;
    }
}
void criaPilha3(no *pilha1, no *pilha2){
    no *aux, *aux2, *pilha3 = NULL;
    while(aux || aux2){
        if(aux){
            if(aux2){
                if(aux->dado < aux2->dado){
                    pilhaNovo(pilha3, aux->dado);
                    aux = aux->proximo;
                }
            }
        }
        else if(aux2){

        }

    }
    printf("\n");
    printaPilha(pilha3);
}