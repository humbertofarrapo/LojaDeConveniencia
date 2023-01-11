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
			case 1:
				printf("Digite a matricula do produto a ser inserido: ");
				scanf("%d", &matricula);
				printf("Digite o tipo do produto a ser inserido: ");
				scanf("%d", &tipo);
				printf("Digite o preco do produto a ser inserido: ");
				scanf("%f", &preco);
				p = insere(p, matricula, tipo, preco);
				system("cls || clear");
				printf("Produto inserido com sucesso!\n\n");
				break;
			case 2:
				printf("Digite a matricula do produto a ser removido: ");
				scanf("%d", &matricula);
				p = retira(p, matricula);
				system("cls || clear");
				printf("Produto removido com sucesso!\n\n");
				break;
			case 3://alterar
				break;
			case 4:
				printf("Digite a matricula do produto a ser buscado: ");
				scanf("%d", &matricula);
				if(busca(p, matricula))
				{
					system("cls || clear");
					printf("\nMATRICULA: %d --- TIPO: %d --- PRECO: R$ %.2f\n\n", matricula, tipo, preco);
				}
				else
				{
					system("cls || clear");
					printf("Produto nao encontrado!\n\n");
				}
				printf("\n");
				break;
			case 5://vender
				break;
			case 6://relatorio - tipo
				break;
			case 7://vendas
				break;
			case 0:
				libera(p);
				printf("Até mais!\n");
				break;
			default:	
				printf("Digite uma opção válida!\n");
		}
	} while (opcao);
	return 0;
}
