#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GeraSenha(char* s, char tipo, int tam)
{
	int var;
	int contador = 0;
	
	if(tipo == 'a')
	{
		while(contador < tam)
		{
			var = (rand()%10)+48;
			s[contador] = var;
			contador += 1;
		}
	}
	else if (tipo == 'b')
	{
		while(contador < tam)
		{
			var = rand()%2;
			
			if(var == 0)
			{
				var = (rand()%26)+65;
				s[contador] = var;
			}
			else
			{
				var = (rand()%26)+97;
				s[contador] = var;	
			}
			contador += 1;
		}
	}
	else if (tipo == 'c')
	{
		while(contador < tam)
		{
			var = rand()%2;
			
			if(var == 0)
			{
				var = (rand()%10)+48;
				s[contador] = var;
			}
			else
			{
				var = (rand()%26)+65;
				s[contador] = var;	
			}
			contador += 1;
		}
	}
	else if (tipo == 'd')
	{
		while(contador < tam)
		{
			var = rand()%3;
			
			if(var == 0)
			{
				var = (rand()%10)+48;
				s[contador] = var;
			}
			else if (var == 1)
			{
				var = (rand()%26)+65;
				s[contador] = var;
			}else
			{
				var = (rand()%26)+97;
				s[contador] = var;
			}
			contador += 1;
		}
	}
	else
	{
		while(contador < tam)
		{
			var = rand()%5;
			
			if(var == 0)
			{
				var = (rand()%10)+48;
				s[contador] = var;
			}
			else if (var == 1)
			{
				var = (rand()%26)+65;
				s[contador] = var;
			}
			else if (var == 2)
			{
				var = (rand()%26)+97;
				s[contador] = var;
			}
			else if (var == 3)
			{
				var = (rand()%14)+33;
				s[contador] = var;
			}
			else
			{
				var = (rand()%7)+58;
				s[contador] = var;
			}
			contador += 1;
		}
	}
	s[contador] = '\0';
}
	
int main(void)
{		
	char tipo;
	int tam;
	
	printf("\ta. Numerica = contera apenas algarismos\n");
	printf("\tb. Alfabetica = conterá apenas letras maiúsculas e minusculas\n");
	printf("\tc. Alfanumerica 1 = contera letras maiusculas e algarismos\n");
	printf("\td. Alfanumerica 2 = contera letras maiusculas, minusculas e algarismos\n");
	printf("\te. Geral = contera letras maiusculas, minusculas, algarismos e os caracteres -, _ , :, @, #, $, &, ?\n\n");
	printf("\tDigite um formato de senha: ");
	scanf("%c%*c",&tipo);
	
	while(tipo != 'a' && tipo != 'b' && tipo != 'c' && tipo != 'd' && tipo != 'e')
	{
		printf("\n\n\tPossiveis resultados (a,b,c,d,e)\n");
		printf("\tDigite um formato de senha: ");
		scanf("%c%*c",&tipo);
	}
	
	printf("\n\n\tDigite o tamanho da senha: ");
	scanf("%d",&tam);
	
	while(tam < 1 || tam > 30)
	{
		printf("\n\tO tamanho da senha deve ser de 1 a 30: ");
		scanf("%d",&tam);
	}
	
	FILE  *arq;
	FILE  *arqm;
	
	char senha[31];
	int matricula;
	
	arq = fopen("SENHAS.txt", "wt");
	arqm = fopen("MATR.txt", "rt");
	
	while((fscanf(arqm,"%d",&matricula)) != EOF)
	{
		GeraSenha(senha, tipo, tam);
		fprintf(arq,"%d;%s\n",matricula,senha);
	}
	
	fclose(arq);
	fclose(arqm);
	
	return 0;
}
