/*Desconsidere o conhecimento da função sqrt na linguagem C.
Uma forma de se obter a raiz quadrada de um número qualquer x seria através de busca binária.
Assuma que a raiz quadrada de x está entre 0 e x (Se o número for negativo, retorne 0).
Para sabermos se um palpite y é a raiz quadrada de x, basta testar se y*y é próximo o suficiente de x ou,
em outras palavras, se o módulo da diferença entre eles está dentro de uma tolerância definida.
Caso contrário, podemos restringir a busca entre 0 e y ou entre y e x.
Escreva a função abaixo que implemente este algoritmo, considerando 10-6 como tolerância para o cálculo do resultado.
double raiz(double x)*/
#include <stdio.h>

double raiz(double x);

int main(){
    double x = 20;
    double sqrt;
    sqrt = raiz(x);
    if(sqrt == -1){
        printf("Numero negativo");
    }
    else{
        printf("A raiz quadrada de %lf eh %lf", x, sqrt);
    }

    return 0;
}

double raiz(double x){
    double ini = 0, fim = x-1.0, meio;
    double sqrt = 0;
    if(x < 0){
        return sqrt;
    }
    else{
        while(ini <= fim){
            meio = (ini + fim) / 2;

            if((meio * meio) >= x-0.09 && (meio * meio) <= x+0.09){
                sqrt = meio;
                break;
            }
            else if((meio * meio) < x){
                ini = meio;
            }
            else{
                fim = meio;
            }
        }
    }
    
    return sqrt;
}