typedef struct cadProf
{
    char nome[50];
    struct dataNascimento dtnasc;
    char CPF[15];
    int matricula;
    char sexo;
} Lista_Prof;

void listar_Professor(Lista_Prof Professores[]);
void listar_Professor_sexo(Lista_Prof Professores[]);
void status_Professor(Lista_Prof Professores[]);
void retirar_Professor(int qtd,Lista_Prof Professores[]);
int matricula_Professor(int qtd,Lista_Prof Professores[]);
int menu_opcoesP();
int cadastroProf(int qtdprof, Lista_Prof Professor[]);