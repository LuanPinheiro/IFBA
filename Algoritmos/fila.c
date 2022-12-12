typedef struct no{
    int dado;
    struct no *proximo;
}no;

// Insere elemento no fim de uma fila
void inserirFila(no **inicioFila, int valor){
    no *aux, *novoElemento = malloc(sizeof(no));
    if(novoElemento){
        novoElemento->dado = valor;
        novoElemento->proximo = NULL;
        if(*inicioFila == NULL){
            *inicioFila = novoElemento;
        }
        else{
            aux = *inicioFila;
            while(aux->proximo){
                aux = aux->proximo;
            }
            aux->proximo = novoElemento;
        }
    }
    else{
        printf("Erro na alocacao da memoria\n");
    }
}