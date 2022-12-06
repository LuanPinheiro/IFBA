/*Em algumas aplicações tem-se que trabalhar com mais de uma
pilha ao mesmo tempo. Pode-se implementar essas pilhas em um mesmo ar-
ranjo, de forma que cada uma ocupe parte desse arranjo. Faça um programa
que tenha duas pilhas alocadas em um mesmo arranjo, sendo que cada uma
delas cresce em sentido oposto. Implemente algoritmos para as seguintes
operações:

■ inicialização das duas pilhas;
■ verificar se as duas pilhas estão vazias;
■ empilhar um elemento em cada uma das pilhas;
■ desempilhar um elemento de cada uma das pilhas;
■ imprimir o conteúdo do nodo no topo das duas pilhas.*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define tam 20

typedef struct no{
	int dado;
	struct no *prox;
}no;

typedef struct pilha{
	no *topo;
	int comecoPilhaNoArranjo;
	int fimPilhaNoArranjo;
	int direcao; // Indica a direção que as pilhas irão, 1 para direita e -1 para esquerda
}pilha;

void pilhaNovo(pilha *pilhaParametro, int valor, int arranjo[tam]);
void pilhaRetira(pilha *pilhaParametro, int arranjo[tam]);

int main(){
	pilha *pilha1 = malloc(sizeof(pilha)), *pilha2 = malloc(sizeof(pilha));
	int arranjo[tam];

	// Inicializando as duas pilhas como NULL e suas posicoes no arranjo
	pilha1->topo = NULL;
	pilha1->direcao = 1;
	pilha1->comecoPilhaNoArranjo = 0;
	pilha1->fimPilhaNoArranjo = 0;
	
	pilha2->topo = NULL;
	pilha2->direcao = -1;
	pilha2->comecoPilhaNoArranjo = tam - 1;
	pilha2->fimPilhaNoArranjo = tam - 1;
	
	printf("\nTentando remover da pilha 1 vazia: ");
	pilhaRetira(pilha1, arranjo);
	printf("Tentando remover da pilha 2 vazia: ");
	pilhaRetira(pilha2, arranjo);

	printf("\nEmpilhando elemento na pilha 1: ");
	pilhaNovo(pilha1, 5, arranjo);
	printf("Empilhando elemento na pilha 2: ");
	pilhaNovo(pilha2, 11, arranjo);

	printf("\nTentando remover da pilha 1: ");
	pilhaRetira(pilha1, arranjo);
	printf("Tentando remover da pilha 2: ");
	pilhaRetira(pilha2, arranjo);

	free(pilha1);
	free(pilha2);
}

void pilhaNovo(pilha *pilhaParametro, int valor, int arranjo[tam]){
    no *novo = malloc(sizeof(no));

    if(novo){
        printf("Empilhado elemento %d\n", valor);
        novo->dado = valor;
        novo->prox = pilhaParametro->topo;
		pilhaParametro->topo = novo;
		
		arranjo[pilhaParametro->fimPilhaNoArranjo] = valor;
		pilhaParametro->fimPilhaNoArranjo += pilhaParametro->direcao;
    }
    else{
        printf("Erro na Alocacao\n");
    }
}

void pilhaRetira(pilha *pilhaParametro, int arranjo[tam]){
    if(pilhaParametro->topo){
        no *remover = pilhaParametro->topo;
        pilhaParametro->topo = remover->prox;
		pilhaParametro->fimPilhaNoArranjo -= pilhaParametro->direcao; // Exclusão lógica dentro do arranjo
		
		printf("Removido elemento %d\n", remover->dado);
        free(remover);
    }
    else{
        printf("Pilha Vazia\n");
    }
}