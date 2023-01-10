#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int conteudo;
    struct node *esquerda;
    struct node *direita;
}node;

node* iniciaArvore();
node* inserirArvore(node *raiz, int valor);
void printaArvoreOrdenado(node *raiz);
void liberaArvore(node *raiz);
node* buscaArvore(node *raiz, int valorBuscado);
node* menorElemento(node *raiz);
node* retiraElemento(node *raiz, int elemento);
int alturaArvore(node *raiz);

int main(){
    node *raiz = iniciaArvore();
    raiz = inserirArvore(raiz, 5);
    raiz = inserirArvore(raiz, 10);
    raiz = inserirArvore(raiz, 12);
    raiz = inserirArvore(raiz, 6);
    raiz = inserirArvore(raiz, 4);
    printaArvoreOrdenado(raiz);
    printf("altura: %d\n", alturaArvore(raiz));

    node* busca = buscaArvore(raiz, 6);
    if(busca){
        printf("\nEncontrado elemento %d no endereco %p\n", busca->conteudo, busca);
    }
    else{
        printf("\nElemento nao encontrado\n");
    }

    busca = buscaArvore(raiz, 7);
    if(busca){
        printf("\nEncontrado elemento %d no endereco %p\n", busca->conteudo, busca);
    }
    else{
        printf("\nElemento nao encontrado\n");
    }

    if(!buscaArvore(raiz, 10)){
        printf("Elemento nao encontrado\n");
    }
    else{
        printf("Removendo da Arvore\n");
        raiz = retiraElemento(raiz, 10);
    }
    printaArvoreOrdenado(raiz);

    liberaArvore(raiz);
    return 0;
}

// Inicia o ponteiro para o inicio da árvore
node* iniciaArvore(){
    printf("Arvore Iniciada\n");
    return NULL;
}

// Insere um novo elemento de maneira ordenada na arvore
node* inserirArvore(node *raiz, int valor){
    if(!raiz){
        node *novo = (node*) malloc(sizeof(node));
        novo->conteudo = valor;
        novo->direita = NULL;
        novo->esquerda = NULL;
        return novo;
    }
    else{
        if(valor < raiz->conteudo){
            raiz->esquerda = inserirArvore(raiz->esquerda, valor);
        }
        else if(valor > raiz->conteudo){
            raiz->direita = inserirArvore(raiz->direita, valor);
        }
        return raiz;
    }
}

// Printa os elementos da árvore em ordem crescente, da esquerda para a direita
void printaArvoreOrdenado(node *raiz){
    if(raiz){
        printaArvoreOrdenado(raiz->esquerda);
        printf("%d ", raiz->conteudo);
        printaArvoreOrdenado(raiz->direita);
    }
}

// Libera a memória em todos os nodos
void liberaArvore(node *raiz){
    if(raiz){
        liberaArvore(raiz->esquerda);
        liberaArvore(raiz->direita);
        free(raiz);
    }
}

// Busca um elemento dentro da arvore, retorna o endereço caso encontre, retorna NULL caso não encontre
node* buscaArvore(node *raiz, int valorBuscado){
    if(raiz){
        if(raiz->conteudo == valorBuscado){
            return raiz;
        }
        if(valorBuscado < raiz->conteudo){
            return buscaArvore(raiz->esquerda, valorBuscado);
        }
        if(valorBuscado > raiz->conteudo){
            return buscaArvore(raiz->direita, valorBuscado);
        }
    }
    return raiz;
}

// Retorna o menor elemento da árvore
node* menorElemento(node *raiz){
    if(raiz){
        if(!raiz->esquerda){
            return raiz;
        }
        return menorElemento(raiz->esquerda);
    }
    printf("Entrada invalida\n");
    return NULL;
}

node* retiraElemento(node *raiz, int elemento){
    if(raiz){
        if(elemento < raiz->conteudo){
            raiz->esquerda = retiraElemento(raiz->esquerda, elemento);
        }
        else if(elemento > raiz->conteudo){
            raiz->direita = retiraElemento(raiz->direita, elemento);
        }
        else{
            if(!raiz->esquerda && !raiz->direita){
                free(raiz);
                return NULL;
            }
            else if(!raiz->esquerda && raiz->direita){
                node* aux = raiz->direita;
                free(raiz);
                return aux;
            }
            else if(raiz->esquerda && !raiz->direita){
                node* aux = raiz->esquerda;
                free(raiz);
                return aux;
            }
            else{ // Caso hajam nodes para os dois lados, pegar o menor valor da subarvore à direita para ser colocado no lugar do nodo removido
                node* menor = menorElemento(raiz->direita);
                int menorConteudo = menor->conteudo;
                raiz = retiraElemento(raiz, menorConteudo); // Remove o menor elemento da subarvore à direita
                raiz->conteudo = menorConteudo;
                return raiz;
            }
        }
    }
    return raiz;
}

// Retorna a altura de uma árvore, ou seja, a distancia da raiz até uma folha que percorra mais nós
int alturaArvore(node *raiz){
    if(!raiz){
        return -1;
    }
    int esquerda = alturaArvore(raiz->esquerda);
    int direita = alturaArvore(raiz->direita);
    if(esquerda > direita){
        return esquerda + 1;
    }
    else{
        return direita + 1;
    }
}