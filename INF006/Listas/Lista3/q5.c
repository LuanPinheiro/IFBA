/* Crie um programa que dado uma string, coloque as letras dela em ordem crescente pelo algoritmo quick-sort.*/
#include <stdio.h>
#define n 25

void quicksort(char string[],int first,int last);

int main(){
	char string[n] = "teststring";
    
	quicksort(string, 0, (strlen(string)-1));
	
	for(int i = 0; string[i] != '\0'; i++){
		printf("[%c] ", string[i]);
	}
	return 0;
}

void quicksort(char string[],int first,int last){
	int i, j, pivot, temp;

	if(first<last){
		pivot=first;
		i=first;
		j=last;

		while(i<j){
			while(string[i]<=string[pivot]&&i<last){
				i++;
			}
			while(string[j]>string[pivot]){
				j--;
			}

			if(i<j){
				temp=string[i];
				string[i]=string[j];
				string[j]=temp;
			}
		}
		
		temp=string[pivot];
		string[pivot]=string[j];
		string[j]=temp;

		quicksort(string,first,j-1);
		quicksort(string,j+1,last);
	}
}