// Alunos:
// Juliana Ribeiro 
// Luan Pinheiro

//Disciplina: Estrutura de Dados
//Data:02/12/19
#include <stdio.h>


void bubbleSort(int vet[], int tam)
{
    int i , j ,aux, menor;//Acrescentado variável - menor
    
    for(i=0; i<tam-1;i++)
    {
        menor = i;//variável menor inicia como i
        for(j=i+1;j<tam;j++)
        {
            if(vet[j]<vet[menor])
            {
            menor = j;
            }//caso encontre outro valor menor, armazenar na variável - menor
        }   // retirado a troca de valores do 2º for(j)
        if(menor!=i)//se a variável menor sofrer variação ocorrerá troca
        {
            aux=vet[i];
            vet[i]=vet[menor];
            vet[menor]=aux;
        }
    }
//Imprime vetor ordenado

    for(i=0;i<tam;i++)
    {
        printf("%d",vet[i]);
    }
    printf("\n");
}



int main()
{
    int x,tam;
    
    scanf("%d" , &tam);// ler o maximo de algarismo do vetor
    
    printf(" Insira os valores\n");
    
     int vet[tam];
     
    for(x=0;x<tam;x++)
        scanf("%d" , &vet[x]);
            
    bubbleSort(vet,tam);

    return 0;
    
}
