#include <stdio.h>
#include <stdlib.h>

int main()
{
	double P1, P2, MT, MF;
    char NOME[50];
    int MATRICULA;
	
	FILE *fp;
	fp = fopen("Alunos.txt","r");
	
	if(fp==NULL){
		printf("\nErro na abertura");
		exit(0);
	}
	
	printf("\tMatricula\t\tNome do Aluno\t\tMedia Final\t\tSituacao\n\n");
	while(fscanf(fp, "%d;%lf;%lf;%lf;%[^\n]\n", &MATRICULA, &P1, &P2, &MT, NOME) != EOF)
	{			
		MF = ((P1 * 4) + (P2 * 4) + (MT * 2)) / 10;
		
		if(MF >= 6.0)
		{
			printf("\t%-9d\t\t%-20s\t%.1lf\t\t\tAPROVADO\n", MATRICULA, NOME, MF);
		}
		else
		{
			printf("\t%-9d\t\t%-20s\t%.1lf\t\t\tREPROVADO\n", MATRICULA, NOME, MF);
		}
	}
	fclose(fp);
	
	printf("\n\n");

	return 0;
}
