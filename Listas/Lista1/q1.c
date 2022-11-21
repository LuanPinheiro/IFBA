/*Especifique um TAD que seja capaz de armazenar uma data composta por dia, mês e ano e implemente
o seguinte conjunto de operações para manipular esse tipo Data:
■ uma função que recebe como parâmetro o dia, o mês, o ano e uma estrutura do tipo Data, onde o resultado deve
ser armazenado, e retorna verdadeiro se a data estiver válida; caso contrário, retorna falso. A validação da data pode
ser feita da seguinte forma:
■ meses com 30 dias: 04, 06, 09 e 11;
■ meses com 31 dias: 01, 03, 05, 07, 08, 10,12;
■ cálculo de ano bissexto: cada ano divisível por 4 é um ano bissexto(E); cada ano divisível por 100 não é bissexto
(OU); todo ano divisível por 400 sempre é um ano bissexto;
■ uma função que recebe como parâmetro uma data do tipo string (no formato DD/MM/AAAA) e uma estrutura do
tipo Data, onde o resultado deve ser armazenado, e retorna verdadeiro se a data estiver válida; caso contrário, retorna
falso;
■ uma função que recebe como parâmetro uma estrutura do tipo Data e um número inteiro, e retorna a soma do
número de dias da data recebida;
■ uma função que recebe como parâmetro uma estrutura do tipo Data e um número inteiro, e retorna a subtração do
número de dias da data recebida;
■ uma função que recebe como parâmetro uma data e escreve essa data por extenso. Por exemplo, 25/03/2007 deve
ser escrito como 25 de março de 2007. A função deve retornar verdadeiro se a operação for realizada
com sucesso e falso, caso contrário;
■ uma função que receba como parâmetro o ano e retorne a data da Páscoa. O domingo de Páscoa é o primeiro
domingo depois da primeira lua cheia do outono. Utilize o seguinte algoritmo, criado em 1800 pelo matemático
Carl Gauss:
■ suponha que y seja o ano (como 1800 ou 2001);
■ divida y por 19 e chame o resto de a. Ignore o quociente;
■ divida y por 100 para obter o quociente b e o resto c;
■ divida b por 4 para obter o quociente d e o resto e;
■ divida 8 * b + 13 por 25 para obter o quociente g. Ignore o resto;
■ divida 19 * a + b - d - g + 15 por 30 para obter o quociente h. Ignore o resto;
■ divida c por 4 para obter o quociente j e o resto k;
■ divida a + 11 * h por 319 para obter o quociente m. Ignore o resto;
■ divida 2 * e + 2 * j - k - h + m + 32 por 7 para obter o resto r. Ignore o quociente;
■ divida h - m + r + 90 por 25 para obter o quociente n. Ignore o resto;
■ divida h - m + r + n + 19 por 32 para obter o resto p. Ignore o quociente.*/

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