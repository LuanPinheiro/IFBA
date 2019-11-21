void aniversariantesA(int mesAtual,int qtdAlunos, Lista_aluno Aluno[])
{
    int x;
    
    printf("\n###ANIVERSARIANTES DO MES###\n")

    for(x=0;x<qtdAlunos;x++)
    {
        if(Aluno[x].dataNascimento.mes==mesAtual)
        {
            printf("%s\n",Aluno[x].nome);
        }
    }
    printf("\n");
}