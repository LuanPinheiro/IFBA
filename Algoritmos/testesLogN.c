#include <stdio.h>

// logN = Logaritmo de N na base 2
// Ou seja: qual numero elevado a 2 vai resultar em N
// Ex: Log de 8 na base 2 = 3 pois 2³ = 2*2*2 = 4*2 = 8
// ao dobrar N aumenta em 1

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

