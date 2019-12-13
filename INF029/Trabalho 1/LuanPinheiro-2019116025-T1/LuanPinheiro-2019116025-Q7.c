#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int acabou=0, jogador, i, j, valido;
    char grid[3][3], jogada[2];

    //preenchendo a grid
    for(i=0;i<3;i++)
        for (j=0;j<3;j++)
            grid[i][j]='0';

    while(acabou==0);
    {
        for(jogador=1;jogador<3;jogador++)
        {
            do
            {
                valido=1;
                printf("Digite sua jogada: ");
                fgets(jogada,2,stdin);
                if(strlen(jogada)<2)
                {
                    valido=0;
                }
                else
                {
                    if(jogada[0]<65 && jogada[0]>67)
                        valido=0;
                    else
                    {
                        if(jogada[1]<49 && jogada[1]>51)
                            valido=0;
                    }
                }
            } while (valido==0);
        }
    }

    return 0;
}