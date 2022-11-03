/*Refaça as funções de busca sequencial e busca binária assumindo que o vetor possui
chaves que podem ocorrer múltiplas vezes no vetor.
Neste caso, você deve retornar, em um outro vetor, todas as posições onde a chave foi encontrada.

Sua função deve retornar o número de ocorrências da chave no vetor e, para cada uma destas ocorrências
indicar no vetor posicoes[], as posições de vet que possuem a chave.*/
#include <stdio.h>
#define n 8

int buscaSequencial(int vet[], int chave, int posicoes[]);
int buscaBinaria(int vet[], int chave, int posicoes[]);

int main(){
    int vet[n] = {5, 8, 8, 11, 26, 32, 40, 40};
    int posicoesSequencial[n], posicoesBinaria[n];
    int numBusca = 40;
    int ocorrenciasSequencial = buscaSequencial(vet, numBusca, posicoesSequencial);
    int ocorrenciasBinaria = buscaBinaria(vet, numBusca, posicoesBinaria);

    printf("OCORRENCIAS SEQUENCIAL: %d\n", ocorrenciasSequencial);
    for(int i = 0; i < ocorrenciasSequencial; i++){
        printf("Posicoes[%d]: %d\n", i, posicoesSequencial[i]);
    }
    printf("\nOCORRENCIAS BINARIA: %d\n", ocorrenciasBinaria);
    for(int i = 0; i < ocorrenciasBinaria; i++){
        printf("Posicoes[%d]: %d\n", i, posicoesBinaria[i]);
    }
    return 0;
}

int buscaSequencial(int vet[], int chave, int posicoes[]){
    int ocorrencias = 0;
    for(int i = 0; i < n; i++){
        if(vet[i] == chave){
            posicoes[ocorrencias] = i;
            ocorrencias++;
        }
    }
    return ocorrencias;
}

int buscaBinaria(int vet[], int chave, int posicoes[]){
    int ocorrencias = 0;
    int inicio = 0, fim = n-1, meio;

    while(vet[inicio]<=vet[fim]){
        meio = (inicio + fim) / 2;

        if(chave == vet[meio])
        {
            posicoes[ocorrencias] = meio;
            ocorrencias++;
            vet[meio] = -1;
        }
        else if(vet[meio] < chave){
            inicio = meio + 1;
        }
        else{
            fim = meio - 1;
        }
    }
    for(int i = 0; i < n; i++){
        if (vet[i] == -1){
            vet[i] = chave;
        }
    }
    return ocorrencias;
}