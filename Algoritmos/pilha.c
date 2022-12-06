typedef struct no{
    int dado;
    struct no *proximo;
}no;

// Adiciona novos valores a uma pilha, estando ela vazia ou não, retorna o novo topo
no* pilhaNovo(no *topo){
    no *novo = malloc(sizeof(no));

    if(novo){
        printf("Empilhado\n");
        novo->dado = 5;
        novo->proximo = topo;
        return novo;
    }
    else{
        printf("Erro na Alocacao\n");
    }
    return NULL;
}

// Retira um elemento da pilha
no* pilhaRetira(no **topo){
    if(*topo){
        no *remover = *topo;
        *topo = remover->proximo;
        return remover;
    }
    else{
        printf("Pilha Vazia\n");
    }
    return NULL;
}