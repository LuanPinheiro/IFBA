/*O algoritmo que remove um nodo com base em sua ordem na
lista pode ser otimizado da seguinte forma: se o nodo a ser
removido estiver localizado na primeira metade da lista, o deslocamento deve
ser feito para baixo; caso contrário, o deslocamento deve ser feito para cima.
Implemente, de forma otimizada, um algoritmo que receba como parâmetro
uma lista e um valor e retorne a lista resultante da exclusão do elemento cuja
posição na lista foi indicada pelo parâmetro valor.*/
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
void printaLista(lista Lista);

int main(){
    lista Lista;
    Lista.qtd = 0;

    Lista = preencheLista(Lista);
    Lista = excluiNodo(Lista, 3);
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

void printaLista(lista Lista){
    for(int i = Lista.inicioLista; i < Lista.fimLista; i++){
        printf("[%d] ", Lista.valores[i]);
    }
}