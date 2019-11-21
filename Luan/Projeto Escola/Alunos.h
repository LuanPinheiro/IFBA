#define TAMANHO_LISTA 10

struct dataNascimento
{
    int dia;
    int mes;
    int ano;
};

typedef struct cadAluno
{
    char nome[50];
    struct dataNascimento dtnasc;
    char CPF[15];
    int matricula;
    char sexo;
} Lista_aluno;

int cadastroAluno(int qtdaluno, Lista_aluno Aluno[]);
int validarnome(char nm[50]);
int validardtnasc(int d, int m, int a);
int validarcpf(char c[15]);
int validarsexo(char s);
int validarmatricula(int mat);
int matricula_Aluno(int qtd,Lista_aluno Alunos[]);
int menu_opcoes();
void listar_aluno(Lista_aluno Alunos[]);
void listar_aluno_sexo(Lista_aluno Alunos[]);
void status_aluno(Lista_aluno Alunos[]);
void retirar_aluno(Lista_aluno Alunos[]);
void aniversariantesA(int mesAtual,int qtdAlunos, Lista_aluno Aluno[]);
void alterar_aluno(Lista_aluno Alunos[]);