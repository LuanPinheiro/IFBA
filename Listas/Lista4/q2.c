/*Faça um algoritmo que leia um conjunto de valores inteiros e
armazene estes valores em duas pilhas, uma para os valores positivos lidos e a
outra, para os valores negativos. As pilhas devem ser implementadas sobre um
mesmo arranjo PILHAS, a partir de posições fornecidas como parâmetros. Em
caso de overflow de alguma das pilhas, deve ser emitida uma mensagem.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define tam 8

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

int pilhaNovo(pilha *pilhaParametro, pilha *pilhaCheck, int valor, int arranjo[tam]);

int main(){
	pilha *pilhaPositivos = malloc(sizeof(pilha)), *pilhaNegativos = malloc(sizeof(pilha));
	int PILHAS[tam], valor;

	// Inicializando as duas pilhas como NULL e suas posicoes no arranjo
	pilhaPositivos->topo = NULL;
	pilhaPositivos->direcao = 1;
	pilhaPositivos->comecoPilhaNoArranjo = 0;
	pilhaPositivos->fimPilhaNoArranjo = 0;
	
	pilhaNegativos->topo = NULL;
	pilhaNegativos->direcao = -1;
	pilhaNegativos->comecoPilhaNoArranjo = tam - 1;
	pilhaNegativos->fimPilhaNoArranjo = tam - 1;

	for(int i = 0; i < tam; i++){
		printf("\nDigite um Valor: ");
		scanf("%d", &valor);
		getchar();

		if(valor > 0){
			i += pilhaNovo(pilhaPositivos, pilhaNegativos, valor, PILHAS);
		}
		else{
			i += pilhaNovo(pilhaNegativos, pilhaPositivos, valor, PILHAS);
		}

		for(int j = 0; j < tam; j++){
			printf("[%d] ", PILHAS[j]);
		}
	}

	free(pilhaPositivos);
	free(pilhaNegativos);
}

int pilhaNovo(pilha *pilhaParametro, pilha *pilhaCheck, int valor, int arranjo[tam]){
    no *novo = malloc(sizeof(no));
	int retorno;

    if(novo){
		if(pilhaParametro->fimPilhaNoArranjo == pilhaCheck->fimPilhaNoArranjo || pilhaParametro->fimPilhaNoArranjo == pilhaCheck->comecoPilhaNoArranjo){
			printf("\nOVERFLOW\n");
			retorno = tam;
		}
		else{
			retorno = 0;
		}
		novo->dado = valor;
		novo->prox = pilhaParametro->topo;
		pilhaParametro->topo = novo;
		
		arranjo[pilhaParametro->fimPilhaNoArranjo] = valor;
		pilhaParametro->fimPilhaNoArranjo += pilhaParametro->direcao;
    }
    else{
        printf("Erro na Alocacao\n");
		retorno = tam;
    }
	return retorno;
}