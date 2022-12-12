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