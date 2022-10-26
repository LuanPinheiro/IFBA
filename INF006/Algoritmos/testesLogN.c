#include <stdio.h>

int main(){
    int i, n, x;

    printf("Testes Multiplicando por 2:\n");
    n = 2;
    printf("Entrada: %d => ", n);
    for(x = 0, i = 1; i < n; i = i*2, x++){printf("%d ", i);}
    printf("qtd passos: %d\n", x);

    n = 4;
    printf("Entrada: %d => ", n);
    for(x = 0, i = 1; i < n; i = i*2, x++){printf("%d ", i);}
    printf("qtd passos: %d\n", x);

    n = 8;
    printf("Entrada: %d => ", n);
    for(x = 0, i = 1; i < n; i = i*2, x++){printf("%d ", i);}
    printf("qtd passos: %d\n", x);

    n = 16;
    printf("Entrada: %d => ", n);
    for(x = 0, i = 1; i < n; i = i*2, x++){printf("%d ", i);}
    printf("qtd passos: %d\n", x);


    printf("Testes Dividindo por 2: \n");
    n = 2;
    printf("Entrada: %d => ", n);
    for(x = 0, i = n; i > 1; i = i/2, x++){printf("%d ", i);}
    printf("qtd passos: %d\n", x);

    n = 4;
    printf("Entrada: %d => ", n);
    for(x = 0, i = n; i > 1; i = i/2, x++){printf("%d ", i);}
    printf("qtd passos: %d\n", x);

    n = 8;
    printf("Entrada: %d => ", n);
    for(x = 0, i = n; i > 1; i = i/2, x++){printf("%d ", i);}
    printf("qtd passos: %d\n", x);

    n = 16;
    printf("Entrada: %d => ", n);
    for(x = 0, i = n; i > 1; i = i/2, x++){printf("%d ", i);}
    printf("qtd passos: %d", x);
    return 0;
}

