/*Considere um arranjo unidimensional de N elementos inteiros,
utilizado para implementar duas pilhas A e B. As bases das pilhas estarão uma
em cada extremidade do arranjo. Cada uma das pilhas apresenta um índice
próprio indicando o topo. Escreva:

■ um algoritmo para incluir um elemento no topo da pilha B, atualizando o
indicador de topo desta pilha. Este algoritmo receberá, como parâmetros,
o valor do elemento a ser incluído na pilha B, os índices correspondentes
ao topo das duas pilhas e o número de elementos do arranjo. Deverá tes-
tar se existe uma célula livre para incluir o elemento (se as duas pilhas não
estão ocupando todo o arranjo) e, caso isto ocorrer, não efetuar a inclusão
e enviar uma mensagem avisando;

■ um algoritmo que calcule a quantidade de elementos da pilha A que tam-
bém aparecem na pilha B. Elementos repetidos na mesma pilha devem ser
contados apenas uma vez.*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 20

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

int preenchidosVetor = 0;

int pilhaNovo(pilha *pilhaParametro, pilha *pilhaCheck, int valor, int arranjo[]);
void elementosRepetidos(pilha *pilha1, pilha *pilha2);
int retiraRepetido(int vetor[], int tamanho);
void shiftVetor(int vetor[], int posicaoAtual, int tamanho);

int main(){
	pilha *pilhaA = malloc(sizeof(pilha)), *pilhaB = malloc(sizeof(pilha));
	int arranjo[N];

	// Inicializando as duas pilhas como NULL e suas posicoes no arranjo
	pilhaA->topo = NULL;
	pilhaA->direcao = 1;
	pilhaA->comecoPilhaNoArranjo = 0;
	pilhaA->fimPilhaNoArranjo = 0;
	
	pilhaB->topo = NULL;
	pilhaB->direcao = -1;
	pilhaB->comecoPilhaNoArranjo = N - 1;
	pilhaB->fimPilhaNoArranjo = N - 1;
    
    // Tentando inserir o valor 5 na pilha B, se o vetor estiver cheio não preenche
	pilhaNovo(pilhaB, pilhaA, 5, arranjo);

    // Teste de inserir o mesmo elemento na pilha A para confirmar a função de baixo
    pilhaNovo(pilhaA, pilhaB, 5, arranjo);
    pilhaNovo(pilhaA, pilhaB, 5, arranjo);

    // Printando a quantidade de elementos de A que também tem em B
    elementosRepetidos(pilhaA, pilhaB);

	free(pilhaA);
	free(pilhaB);
}

int pilhaNovo(pilha *pilhaParametro, pilha *pilhaCheck, int valor, int arranjo[]){
    no *novo = malloc(sizeof(no));
	int retorno;

    if(novo){
		if(preenchidosVetor == N){
			printf("\nVETOR CHEIO\n");
			return false;
		}
		novo->dado = valor;
		novo->prox = pilhaParametro->topo;
		pilhaParametro->topo = novo;
		
		arranjo[pilhaParametro->fimPilhaNoArranjo] = valor;
		pilhaParametro->fimPilhaNoArranjo += pilhaParametro->direcao;
        preenchidosVetor++;
    }
    else{
        printf("Erro na Alocacao\n");
		return false;
    }
	return true;
}

void elementosRepetidos(pilha *pilha1, pilha *pilha2){
    int elementosA[N], elementosB[N];
    int qtdA = 0, qtdB = 0, qtdRepete = 0;
    no *elemento = pilha1->topo;

    for(int i = 0; elemento; i++, qtdA++){
        elementosA[i] = elemento->dado;
        elemento = elemento->prox;
    }

    elemento = pilha2->topo;
    for(int i = 0; elemento; i++, qtdB++){
        elementosB[i] = elemento->dado;
        elemento = elemento->prox;
    }
    qtdA = retiraRepetido(elementosA, qtdA);
    qtdB = retiraRepetido(elementosB, qtdB);

    if(qtdA != 0 && qtdB != 0){
        for(int i = 0; i < qtdA; i++){
            for(int j = 0; j < qtdB; j++){
                if(elementosA[i] == elementosB[j]){
                    qtdRepete++;
                    break;
                }
            }
        }
    }
    printf("%d Elementos da pilha A aparecem na pilha B", qtdRepete);
}

int retiraRepetido(int vetor[], int tamanho){
    for(int i = 0; i < tamanho-1; i++){
        for(int j = i+1; j < tamanho; j++){
            if(vetor[i] == vetor[j]){
                shiftVetor(vetor, i, tamanho);
                tamanho--;
            }
        }
    }
    return tamanho;
}

void shiftVetor(int vetor[], int posicaoAtual, int tamanho){
    for(int i = posicaoAtual; i < tamanho-1; i++){
        vetor[i] = vetor[i+1];
    }
}