/*Construa um algoritmo que receba como parâmetros uma lista
e um valor, valor este que representa a posição de um nodo na lista. O algo-
ritmo deverá retornar as informações contidas neste nodo e a lista resultante
da exclusão deste nodo.*/

#include <stdio.h>
#define max 6

typedef struct{
    int qtd;
    int valores[max];
    int inicioLista;
    int fimLista;
}lista;

lista preencheLista(lista Lista);
lista excluiNodo(lista Lista, int index);
void printaNodo(lista Lista, int index);
void printaLista(lista Lista);

int main(){
    lista Lista;
    int index = 3;
    Lista.qtd = 0;

    Lista = preencheLista(Lista);
    printaNodo(Lista, index);
    printaLista(Lista);

    Lista = excluiNodo(Lista, index);
    printaNodo(Lista, 3);
    printaLista(Lista);
    return 0;
}

lista preencheLista(lista Lista){
    for(; Lista.qtd < max; Lista.qtd++){
        Lista.valores[Lista.qtd] = Lista.qtd;
    }
    Lista.inicioLista = 0;
    Lista.fimLista = Lista.qtd;
    return Lista;
}

lista excluiNodo(lista Lista, int index){
    int metade = (max/2)-1;
    
    Lista.qtd--;
    if(index <= metade){
        for(int i = index; i < Lista.qtd; i++){
            Lista.valores[i] = Lista.valores[i+1];
        }
        Lista.fimLista--;
    }
    else{
        for(int i = index; i > 0; i--){
            Lista.valores[i] = Lista.valores[i-1];
        }
        Lista.inicioLista++;
    }
    return Lista;
}

void printaNodo(lista Lista, int index){
    for(int i = 0; Lista.inicioLista < Lista.fimLista; Lista.inicioLista++, i++){
        if(i == index){
            printf("Nodo da posicao %d: %d\n", index, Lista.valores[Lista.inicioLista]);
            break;
        }
    }
}

void printaLista(lista Lista){
    for(int i = Lista.inicioLista; i < Lista.fimLista; i++){
        printf("[%d] ", Lista.valores[i]);
    }
    printf("\n");
}