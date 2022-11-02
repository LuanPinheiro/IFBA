/* Dados três vetores ordenados, implemente uma função que intercala e retorne o vetor resultante ordenado.
Implemente uma função merge3_sort, que faça ordenação em um vetor utilizando a sua função de intercalação
(sugestão: se baseie no algoritmo do merge-sort original). Qual a complexidade desse algoritmo?*/
#include <stdio.h>
#define n 8

void merge(int arr[], int l, int m, int r);
void merge3_Sort(int vetOrdenado[], int vet1[], int vet2[], int vet3[]);

int main(){
	int vet1[n] = {1, 4, 5, 6, 7, 8, 11, 13};
    int vet2[n] = {2, 3, 13, 14, 15, 16, 17, 18};
    int vet3[n] = {21, 22, 23, 24, 25, 26, 27, 28};
    int vetOrdenado[n*3];

	merge3_Sort(vetOrdenado, vet1, vet2, vet3);
	
	for(int i = 0; i < 3*n; i++){
		printf("[%d] ", vetOrdenado[i]);
	}
	return 0;
}

void merge3_Sort(int vetOrdenado[], int vet1[], int vet2[], int vet3[])
{
    for(int i = 0, loop = 1, index = 0; i < 3*n; i++, index++){
        if(index == n){
            index = 0;
            loop++;
        }

        if(loop == 1){
            vetOrdenado[i] = vet1[index];
        }
        else if(loop == 2){
            vetOrdenado[i] = vet2[index];
        }
        else{
            vetOrdenado[i] = vet3[index];
        }
    }
    mergeSort(vetOrdenado, 0, (3*n-1));
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    const int n1 = m - l + 1;
    const int n2 = r - m;
  
    // Create temp arrays
    int L[n1], R[n2];
  
    // Copy data to temp arrays 
    // L[] and R[] 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
  
    // Merge the temp arrays back 
    // into arr[l..r]
    // Initial index of first subarray
    i = 0; 
  
    // Initial index of second subarray
    j = 0; 
  
    // Initial index of merged subarray
    k = l; 
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
        {
            arr[k] = L[i];
            i++;
        }
        else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
  
    // Copy the remaining elements 
    // of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
  
    // Copy the remaining elements of 
    // R[], if there are any 
    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r) 
    {
        // Same as (l+r)/2, but avoids 
        // overflow for large l and h
        int m = l + (r - l) / 2;
  
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
  
        merge(arr, l, m, r);
    }
}