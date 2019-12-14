#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int validaPosicao(char jogada[], int jogador, char grid[3][3]);

int main()
{
    int fim, jogador, i, j, valido;
    char grid[3][3], jogada[3];

    //preenchendo a grid
    for(i=0;i<3;i++)
        for (j=0;j<3;j++)
            grid[i][j]='0';

    printf("|%c|%c|%c|\n", grid[0][0], grid[0][1], grid[0][2]);
    printf("|%c|%c|%c|\n", grid[1][0], grid[1][1], grid[1][2]);
    printf("|%c|%c|%c|\n", grid[2][0], grid[2][1], grid[2][2]);

    for(fim=0;fim==0;)
    {
        for(jogador=1;jogador<3;jogador++)
        {
            do
            {
                printf("Jogador %d jogue: ",jogador);
                fgets(jogada,3,stdin);
                jogada[3]='\0';
                fflush(stdin);

                if((jogada[0]>64 && jogada[0]<68) && (jogada[1]>48 && jogada[1]<52))
                {
                    if(validaPosicao(jogada, jogador, grid)==1)
                        valido=1;
                    else
                    {
                        valido=0;
                        printf("Digite Novamente\n");
                    }
                }
                else
                {
                    valido=0;
                    printf("Digite Novamente\n");
                }
            } while (valido==0);
        }
        fim=1;
    }

    return 0;
}

int validaPosicao(char jogada[], int jogador, char grid[3][3])
{
    if(grid[0][0]!='0' && grid[0][0]!='X' && grid[0][0]!='O')
        grid[0][0]='0';
    
    int intJogada1, intJogada2;
    char aux[1];

    jogada[0]=jogada[0]-16;

    aux[0]=jogada[0];
    aux[1]='\0';
    intJogada1 = atoi(aux);

    aux[0]=jogada[1];
    intJogada2 = atoi(aux);

    printf("%d %d\n\n",intJogada1,intJogada2);
    
    intJogada1--;
    intJogada2--;

    if(grid[intJogada1][intJogada2]=='0')
    {
        if(jogador==1)
            grid[intJogada1][intJogada2]='X';
        else
            grid[intJogada1][intJogada2]='O';
        
        printf("|%c|%c|%c|\n", grid[0][0], grid[0][1], grid[0][2]);
        printf("|%c|%c|%c|\n", grid[1][0], grid[1][1], grid[1][2]);
        printf("|%c|%c|%c|\n", grid[2][0], grid[2][1], grid[2][2]);
        return 1;
    }
    else
    {
        return 0;
    }
}