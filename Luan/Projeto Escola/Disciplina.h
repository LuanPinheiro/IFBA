#define TAM_DISCIPLINAS 3
#define LIMITE_ALUNOS 5
#define SUCESSO_CADASTRO 1
#define ERRO_CADASTRO_CODIGO 2
#define ERRO_CADASTRO_SEMESTRE 4
#define ERRO_LIMITE_DISCIPLINAS 6
#define NAO_LOCALIZADO -1


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