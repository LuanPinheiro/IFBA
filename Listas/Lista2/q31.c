/*Suponha que uma fábrica de potes plásticos com tampas co-
loridas (vermelha-V, verde-G, azul-B). O funcionário da linha de montagem
monta 100 potes por dia. No início da jornada ele recebe uma ordem de
montagem, onde consta o número de potes a montar de cada cor. Outro
funcionário monta kits com potes de três cores diferentes. Especifique as es-
truturas de dados para os tipos de pote e kit. Implemente uma aplicação que
represente o processo de montagem dos kits.*/

#include <stdio.h>
#include <stdlib.h>


typedef struct pote{
    int qtd;
    char cor;
    int inicioLista;
    int fimLista;
}pote;

void produzirPotes(pote qtdPotes[3], int potesProduzidos[3]);
void montarKits(int *kitsMontados, int potesProduzidos[100], pote qtdPotes[3]);
void usarPotes(pote qtdPotes[3]);

int main(){
    pote qtdPotes[3]; // Usando R, G e B para representar as cores para ser mais coeso na linguagem(cores em inglês)
    int potesProduzidos[100];
    int *kitsMontados = malloc(sizeof(int));

    // Ordem de Montagem
    qtdPotes[0].cor = 'r';
    qtdPotes[0].qtd = 25;

    qtdPotes[1].cor = 'g';
    qtdPotes[1].qtd = 50;

    qtdPotes[2].cor = 'b';
    qtdPotes[2].qtd = 25;

    if(qtdPotes[0].qtd + qtdPotes[1].qtd + qtdPotes[2].qtd != 100){
        printf("Total de pedidos de potes invalido");
    }
    else{
        produzirPotes(qtdPotes, potesProduzidos);
        montarKits(kitsMontados, potesProduzidos, qtdPotes);
    }

    free(kitsMontados);
    return 0;
}

void produzirPotes(pote qtdPotes[3], int potesProduzidos[100]){
    int index;

    for(qtdPotes[0].inicioLista = 0, index = qtdPotes[0].inicioLista; index < qtdPotes[0].qtd; index++){
        potesProduzidos[index] = qtdPotes[0].cor;
    }
    qtdPotes[0].fimLista = index-1;

    for(qtdPotes[1].inicioLista = qtdPotes[0].fimLista + 1, index = qtdPotes[1].inicioLista; (index - qtdPotes[1].inicioLista) < qtdPotes[1].qtd; index++){
        potesProduzidos[index] = qtdPotes[1].cor;
    }
    qtdPotes[1].fimLista = index-1;

    for(qtdPotes[2].inicioLista = qtdPotes[1].fimLista + 1, index = qtdPotes[2].inicioLista; (index - qtdPotes[2].inicioLista) < qtdPotes[2].qtd; index++){
        potesProduzidos[index] = qtdPotes[2].cor;
    }
    qtdPotes[2].fimLista = index-1;
}

void montarKits(int *kitsMontados, int potesProduzidos[100], pote qtdPotes[3]){
    kitsMontados = 0;
    for(int i = 0; i < 33; i++){ // 33 é o número máximo de potes que podem ser produzidos
        usarPotes(qtdPotes);
        kitsMontados = i;
        if(qtdPotes[0].qtd < 0 || qtdPotes[1].qtd < 0 || qtdPotes[2].qtd < 0){
            break;
        }
    }
    printf("Foram montados %d kits\n", kitsMontados);
}

void usarPotes(pote qtdPotes[3]){
    qtdPotes[0].qtd--;
    qtdPotes[0].fimLista--;

    qtdPotes[1].qtd--;
    qtdPotes[1].fimLista--;

    qtdPotes[2].qtd--;
    qtdPotes[2].fimLista--;
}