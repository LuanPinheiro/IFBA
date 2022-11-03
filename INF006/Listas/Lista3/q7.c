/* Faça uma função que, dado um valor inteiro N
positivo, aloque dinamicamente um vetor de Aluno, leia do teclado os N pares de valores (Matricula, Nota)
e retorne o vetor alocado.
Imprima, ao final do programa, duas listas: 
(1) alunos ordenados por nota final 
(2) alunos ordenados por número de matrícula.
Utilize algoritmos de ordenação vistos em aula e justifique as suas escolhas.*/
#include <stdio.h>
#define n 3

typedef struct _pessoa_ {
    unsigned int Matricula;
    float Nota;
} Aluno;

void cadastrar(Aluno alunos[]);
void printAlunos(Aluno alunos[]);
void printAlunosNota(Aluno alunos[]);
void printAlunosMatricula(Aluno alunos[]);
void quickSort(Aluno alunos[], int first, int last, int flag);
// Ordenando por quicksort, pois tem O(n*LogN) na maioria dos casos, e possui baixa complexidade espacial O(n).
// Diferente do mergeSort que seria O(n*LogN), mas teria maior complexidade expacial O(n*LogN).

int main(){
    Aluno alunos[n];
    int index;

    cadastrar(alunos);
    printAlunosNota(alunos);
    printAlunosMatricula(alunos);
    
    return 0;
}

void cadastrar(Aluno alunos[]){
    for(int index = 0; index < n; index++){
        printf("Digite a Matricula do Aluno %d: ", index+1);
        scanf("%d", &alunos[index].Matricula);
        getchar();

        printf("Digite a Nota do Aluno %d: ", index+1);
        scanf("%f", &alunos[index].Nota);
        getchar();
        printf("\n\n");
    }
}

void printAlunos(Aluno alunos[]){
    for(int i = 0; i < n; i++){
        printf("Matricula: %d\n", alunos[i].Matricula);
        printf("Nota: %.1f\n\n", alunos[i].Nota);
    }
}

void printAlunosNota(Aluno alunos[]){
    quickSort(alunos, 0, n-1, 0);
    printf("ORDENADO POR NOTA:\n");
    printAlunos(alunos);
}

void printAlunosMatricula(Aluno alunos[]){
    quickSort(alunos, 0, n-1, 1);
    printf("ORDENADO POR MATRICULA:\n");
    printAlunos(alunos);
}

void quickSort(Aluno alunos[], int first, int last, int flag){
    // Se a flag for 0, ordenar Notas, se for 1, ordenar Matriculas
	int i, j, pivot, tempMatricula;
    float tempNota;

	if(first<last){
		pivot = first;
		i = first;
		j = last;

		while(i<j){
            if(flag == 0){
                while(alunos[i].Nota <= alunos[pivot].Nota && i < last){
                    i++;
                }
                while(alunos[j].Nota > alunos[pivot].Nota){
                    j--;
                }

                if(i < j){
                    tempNota = alunos[i].Nota;
                    alunos[i].Nota = alunos[j].Nota;
                    alunos[j].Nota = tempNota;
                }
            }
            else{
                while(alunos[i].Matricula <= alunos[pivot].Matricula && i < last){
                    i++;
                }
                while(alunos[j].Matricula > alunos[pivot].Matricula){
                    j--;
                }

                if(i < j){
                    tempMatricula = alunos[i].Matricula;
                    alunos[i].Matricula = alunos[j].Matricula;
                    alunos[j].Matricula = tempMatricula;
                }
            }
		}
		
        if(flag == 0){
            tempNota = alunos[pivot].Nota;
            alunos[pivot].Nota = alunos[j].Nota;
            alunos[j].Nota = tempNota;
        }
        else{
            tempMatricula = alunos[pivot].Matricula;
            alunos[pivot].Matricula = alunos[j].Matricula;
            alunos[j].Matricula = tempMatricula;
        }
		
		quickSort(alunos, first, j-1, flag);
		quickSort(alunos, j+1, last, flag);
	}
}