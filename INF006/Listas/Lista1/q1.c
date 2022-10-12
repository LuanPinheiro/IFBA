/*Especifique um TAD que seja capaz de armazenar uma data composta por dia, mês e ano e implemente
o seguinte conjunto de operações para manipular esse tipo Data:*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct{
    int dia;
    int mes;
    int ano;
}dataInt;

int q1_a(int dia, int mes, int ano, dataInt data[]);
int q1_b(char string[], dataInt data[]);
dataInt q1_c(int diasSomar, dataInt data);
dataInt q1_d(int diasSubtrair, dataInt data);
int q1_e(dataInt data);
dataInt q1_f(dataInt data);
int validarData(dataInt data);
void limparString(char string[]);

int main(){
    dataInt data[2];
    int dia, mes, ano;

    // Código da primeira parte
    printf("PRIMEIRA FUNCAO\n");
    printf("Digite o dia: ");
    scanf("%d", &dia);
    getchar();

    printf("Digite o mes: ");
    scanf("%d", &mes);
    getchar();

    printf("Digite o ano: ");
    scanf("%d", &ano);
    getchar();

    printf("Retorno: %d\n", q1_a(dia, mes, ano, data));

    printf("Data armazenada: %d/%d/%d\n", data[0].dia, data[0].mes, data[0].ano);

    // Código da segunda parte
    char string[11];
    printf("\nSEGUNDA FUNCAO\n");
    printf("Digite a string de data: ");
    fgets(string, 11, stdin);
    limparString(string);

    printf("Retorno: %d\n", q1_b(string, data));

    printf("Data armazenada: %d/%d/%d\n", data[0].dia, data[0].mes, data[0].ano);

    // Para simplificar, as próximas funções usarão a data conseguida através da última função acima
    // Código da terceira parte
    int diasSomar;
    printf("\nTERCEIRA FUNCAO\n");
    printf("Digite quantos dias quer somar a data: ");
    scanf("%d", &diasSomar);
    getchar();

    data[0] = q1_c(diasSomar, data[0]);

    printf("Data armazenada: %d/%d/%d", data[0].dia, data[0].mes, data[0].ano);

    // Código da quarta parte
    int diasSubtrair;
    printf("\nQUARTA FUNCAO\n");
    printf("Digite quantos dias quer subtrair da data: ");
    scanf("%d", &diasSubtrair);

    data[0] = q1_d(diasSubtrair, data[0]);

    printf("Data armazenada: %d/%d/%d", data[0].dia, data[0].mes, data[0].ano);

    // Código da quinta parte
    printf("\nQUINTA FUNCAO\n");

    printf("Retorno: %d\n", q1_e(data[0]));

    // Código da sexta parte
    printf("\nSEXTA FUNCAO\n");

    data[0] = q1_f(data[0]);

    return 0;
}

int q1_a(int dia, int mes, int ano, dataInt data[]){
    data[0].dia = dia;
    data[0].mes = mes;
    data[0].ano = ano;

    return validarData(data[0]);
}

int q1_b(char string[], dataInt data[]){
    if(string[2]!='/' || string[5]!='/'){
        return false;
    }
    data[0].dia = ((string[0]-48) * 10) + (string[1]-48);
    data[0].mes = (string[3]-48) * 10 + (string[4]-48);
    data[0].ano = (string[6]-48) * 1000 + (string[7]-48) * 100 + (string[8]-48) * 10 + (string[9]-48);
    
    return validarData(data[0]);
}

dataInt q1_c(int diasSomar, dataInt data){
    for(int passouMes = false;diasSomar>0;data.dia++, diasSomar--, passouMes=false){
        if(data.mes == 2){
            if(data.ano % 4 == 0 && (data.ano % 100 != 0 || data.ano % 400 == 0)){
                if(data.dia>29){
                    passouMes = true;
                }
            }
            else{
                if(data.dia>28){
                    passouMes = true;
                }
            }
        }
        else{
            if(data.mes == 4 || data.mes == 6 || data.mes == 9 || data.mes == 11){
                if(data.dia>30){
                    passouMes = true;
                }
            }
            else{
                if(data.dia>31){
                    passouMes = true;
                }
            }
        }

        if(passouMes == true){
            data.dia = 1;
            data.mes++;
            if(data.mes>12){
                data.mes = 1;
                data.ano++;
            }
        }
    }
    return data;
}

dataInt q1_d(int diasSubtrair, dataInt data){
    while(diasSubtrair>0){
        data.dia--;
        diasSubtrair--;
        if(data.dia<1){
            data.mes--;
            if(data.mes<1){
                data.mes = 12;
                data.ano--;
            }

            if(data.mes == 2){
                if(data.ano % 4 == 0 && (data.ano % 100 != 0 || data.ano % 400 == 0)){
                    data.dia = 29;
                }
                else{
                    data.dia = 28;
                }
            }
            else{
                if(data.mes == 4 || data.mes == 6 || data.mes == 9 || data.mes == 11){
                    data.dia = 30;
                }
                else{
                    data.dia = 31;
                }
            }
        } 
    }
    return data;
}

int q1_e(dataInt data){
    if(validarData(data) == true){
        printf("%d de ", data.dia);

        switch(data.mes){
            case 1: printf("Janeiro"); break;
            case 2: printf("Fevereiro"); break;
            case 3: printf("Marco"); break;
            case 4: printf("Abril"); break;
            case 5: printf("Maio"); break;
            case 6: printf("Junho"); break;
            case 7: printf("Julho"); break;
            case 8: printf("Agosto"); break;
            case 9: printf("Setembro"); break;
            case 10: printf("Outubro"); break;
            case 11: printf("Novembro"); break;
            case 12: printf("Dezembro"); break;
            default: break;
        }

        printf(" de %d\n", data.ano);
        return true;
    }
    
    return false;
}

dataInt q1_f(dataInt data){
    int a = data.ano % 19;
    int b = data.ano / 100;
    int c = data.ano % 100;
    int d = b / 4;
    int e = b % 4;
    int g = (8 * b + 13)/25;
    int h = (19 * a + b - d - g + 15) / 30;
    int j = c / 4;
    int k = c % 4;
    int m = (a + 11 * h) / 319;
    int r = (2 * e + 2 * j - k - h + m + 32) % 7;
    int n = (h - m + r + 90) / 25;
    int pascoa = (h - m + r + n + 19) % 32;

    data = q1_d(pascoa, data); // Chamada da função que subtrai dias de uma determinada data
    
    return data;
}

int validarData(dataInt data){
    if(data.mes<1 || data.mes>12 || data.dia<1 || data.ano<1){
        return false;
    }
    if(data.mes == 2){
        if(data.ano % 4 == 0 && (data.ano % 100 != 0 || data.ano % 400 == 0)){
            if(data.dia>29){
                return false;
            }
        }
        else{
            if(data.dia>28){
                return false;
            }
        }
    }
    else{
        if(data.mes == 4 || data.mes == 6 || data.mes == 9 || data.mes == 11){
            if(data.dia>30){
                return false;
            }
        }
        else{
            if(data.dia>31){
                return false;
            }
        }
    }

    return true;
}

void limparString(char string[]){
  for(int i=0;string[i] != '\0';i++)
      if(string[i] == '\n')
        string[i] = '\0';
}