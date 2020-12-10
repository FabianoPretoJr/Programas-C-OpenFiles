#include <stdio.h>
#include <stdlib.h>

int main() 
{  
    int codProd[1000], quant[1000], c, q, i = 0, codBusca = 1;
    double pUnit[1000], p, pTotal = 0, vTotal;
    
    FILE *fp;
	fp = fopen("Vendas.txt","r");
	
	if(fp==NULL){
		printf("\nErro na abertura");
		exit(0);
	}
	
	while(fscanf(fp, "%d;%d;%lf\n", &c, &q, &p) != EOF)
	{	
		codProd[i] = c;
		quant[i] = q;
		pUnit[i] = p;
		
		pTotal = pTotal + (quant[i] * pUnit[i]);
		
		i++;
	}
	
	printf("\tTotal geral vendido: R$ %.2lf\n", pTotal);
	
	while(codBusca != 0)
	{
		printf("\n\tDigite o codigo: ");
		scanf("%d", &codBusca);
		
		if(codBusca == 0)
		{
			printf("\tFim do programa\n\n");
			exit(0);	
		}
		else if(codBusca >= 10000 && codBusca <= 21000)
		{
			vTotal = 0;
			
			for(i = 0; i < 1000; i++)
			{
				if(codProd[i] == codBusca)
				{
					vTotal = vTotal + (quant[i] * pUnit[i]);
				}	
			}
			printf("\tTotal vendido do produto %d = R$ %.2lf\n", codBusca, vTotal);
		}
		else
		{
			printf("\t%d Codigo invalido (deve ser entre 10000 e 21000)\n", codBusca);
		}
	}
	
	return 0;
}
