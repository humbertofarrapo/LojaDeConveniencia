#include <stdio.h>
#include <stdlib.h>
#include "funcoescomplementares.h"
#include "arvorebinaria.h"

int main()
{
	int matricula, tipo;
	float preco;
	
	int opcao = 1;
	
	Produto* p = init();
	
	//telalogin();
	
	do {
		opArvBin();
		scanf("%d", &opcao);
		system("clear || cls");

		switch (opcao)
		{
			case 1://inserir
				break;
			case 2://remover
				break;
			case 3://alterar
				break;
			case 4://buscar
				break;
			case 5://vender
				break;
			case 6://relatorio - tipo
				break;
			case 7://vendas
				break;
			case 0:
				printf("Até mais!\n");
				break;
			default:	
				printf("Digite uma opção válida!\n");
		}
	} while (opcao);
	return 0;
}
