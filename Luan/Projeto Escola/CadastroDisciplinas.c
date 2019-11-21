#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_DISCIPLINAS 3
#define LIMITE_ALUNOS 5
#define SUCESSO_CADASTRO 1
#define ERRO_CADASTRO_CODIGO 2
#define ERRO_CADASTRO_SEMESTRE 4
#define ERRO_LIMITE_DISCIPLINAS 6

typedef struct ficha_disciplina{
     int codigo;
     char nome[30];
     int semestre;
     int alunos_matriculados[LIMITE_ALUNOS];
     int professor_Disciplina;
} Disciplina;

int cadastra_disciplina(int J, Disciplina lista_disciplinas[]);
void imprime_disciplina(Disciplina lista_disciplinas[], int G);
int opcaoMenuDisciplinas();
void excluir_disciplina(Disciplina lista_disciplinas[], int K);
int incluir_aluno(Disciplina lista_disciplinas[], int QTD_DISCIPLINAS);
int localizar_Disciplinas(int loc_codigo, Disciplina lista_disciplinas[], int Q);



int main() {
    
    Disciplina lista_disciplinas[TAM_DISCIPLINAS];
    int i;
    int qtd=0;
    int sair=0;
    int retorno=0;
    int op;
    
    
    while (!sair){
    
    op = opcaoMenuDisciplinas();
    
    switch(op){
      case 0:{
        printf("VOLTANDO\n");
        sair = 1;
        break;
      }
      case 1: {
        retorno = cadastra_disciplina(qtd, lista_disciplinas);
        if (retorno == SUCESSO_CADASTRO){
            printf("Cadastro realizado com sucesso\n");
            qtd++;
        }else{
            switch(retorno) {
                case ERRO_CADASTRO_CODIGO:{
                    printf("Matrícula Inválida\n");
                    break;
                }
                
                case ERRO_CADASTRO_SEMESTRE:{
                    printf("Semestre Inválido\n");
                    break;
                }
                case ERRO_LIMITE_DISCIPLINAS:{
                    printf("O LIMITE DE DISCIPLINAS FOI ATINGIDO\n");
                    break;
                }
                
                default:{
                    printf("Erro desconhecido!\n");
                }
               
            }
           printf("Não foi possível fazer o cadastro\n"); 
            
        }    
        break;
      }
      case 2: {
        imprime_disciplina(lista_disciplinas, qtd);
        break;
      }
      case 4:{
        excluir_disciplina(lista_disciplinas, qtd);
        qtd--;
        break;  
    }
    case 5:{
        incluir_aluno(lista_disciplinas, qtd);
        break;  
    }
      default:{
        printf("Opção Inválida\n");
      }
    }
  }
    
	return 0;
}

int opcaoMenuDisciplinas(){
    int opcao;
    printf("Digite a opção:\n");
    printf("0 - Voltar a Menu Principal\n");
    printf("1 - Inserir Disciplina\n");
    printf("2 - Listar Disciplinas\n");
    printf("3 - Alterar Cadastro Disciplinas\n");
    printf("4 - Excluir Disciplinas\n");
    printf("5 - Incluir Aluno nas Disciplinas\n");
    printf("6 - Excluir Aluno nas Disciplinas\n");
    scanf("%d", &opcao);
    return opcao;
}

int cadastra_disciplina(int J, Disciplina lista_disciplinas[]){
    
    if(J >= TAM_DISCIPLINAS)
        return ERRO_LIMITE_DISCIPLINAS;
    
    printf("\n### Cadastro de Disciplina ###\n");
    
    printf("Digite o codigo da Disciplina: ");
    scanf("%d", &lista_disciplinas[J].codigo);
    getchar();
    
    if (lista_disciplinas[J].codigo <= 0) {
        return ERRO_CADASTRO_CODIGO;
    }    
    
    printf("Nome da Disciplina: ");
    fgets(lista_disciplinas[J].nome, 30, stdin);
    size_t ln = strlen(lista_disciplinas[J].nome) - 1; //size_t = unsigned integer type
        if (lista_disciplinas[J].nome[ln] == '\n')
          lista_disciplinas[J].nome[ln] = '\0';

    
    printf("Digite o Semestre: ");
    scanf("%d", &lista_disciplinas[J].semestre);
    getchar();
    
    if (lista_disciplinas[J].semestre <= 0) {
        return ERRO_CADASTRO_SEMESTRE;
    }   
    
    
    return SUCESSO_CADASTRO;

}

void imprime_disciplina(Disciplina lista_disciplinas[], int G){
    int k;
    for (k = 0; k < G; k++){
            
            printf("\n\n");
            printf("---------------------- Cadastro de disciplina ----------------------\n\n ");
            printf("Disciplina: %s\n Codigo: %d\n Semestre: %d\n",lista_disciplinas[k].nome,lista_disciplinas[k].codigo,lista_disciplinas[k].semestre);
            printf("\n\n");
    }
}

void excluir_disciplina(Disciplina lista_disciplinas[], int K){
    
    int code;
    
    printf("Informe o codigo da disciplina que deseja excluir: ");
    scanf("%d", &code);
    
    int m;
    int n;
    
    for (m = 0; m < K; m++){
        if(code == lista_disciplinas[m].codigo){
            for (n = m; n < K; n++)
                lista_disciplinas[n]= lista_disciplinas[n+1];
          
            break;  
        }
    
    }

}

int incluir_aluno(Disciplina lista_disciplinas[], int QTD_DISCIPLINAS){
    
    int codigo_disciplina;
    int matricula_aluno;
    int posicao_disciplina;
    int posicao_aluno;
    
    printf("Informe o codigo da disciplina que deseja incluir o aluno: ");
    scanf("%d", &codigo_disciplina);
    
    printf("Informe a matricula do aluno a se incluso: ");
    scanf("%d", &matricula_aluno);
    
    posicao_disciplina = localizar_Disciplinas(codigo_disciplina, lista_disciplinas, QTD_DISCIPLINAS);
    
    posicao_aluno= localizar(matricula_aluno, );
    
    lista_disciplinas[posicao_disciplina].alunos_matriculados[QTD_ALUNOS] = lista_alunos[posicao_aluno].matricula; 
}

int localizar_Disciplinas(int loc_codigo, Disciplina lista_disciplinas[], int Q){
    
    int t;

    for (t = 0; t < Q; t++) {
        if (lista_disciplinas[t].codigo == loc_codigo) {
            return t;
        }
    }
}

int localizar_Alunos(){
    
    int t;

    for (t = 0; t < Q; t++) {
        if (lista_disciplinas[t].codigo == loc_codigo) {
            return t;
        }
    }
}
