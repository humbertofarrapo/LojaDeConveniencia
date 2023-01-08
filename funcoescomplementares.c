#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoescomplementares.h"

int validarcpf(char cp_f[])
{
	int i, j, digito1 = 0, digito2 = 0;
	if (strlen(cp_f) != 11)
	{
		return 0;
	}
	else if ((strcmp(cp_f, "00000000000") == 0) || (strcmp(cp_f, "11111111111") == 0) || (strcmp(cp_f, "22222222222") == 0) ||
		(strcmp(cp_f, "33333333333") == 0) || (strcmp(cp_f, "44444444444") == 0) || (strcmp(cp_f, "55555555555") == 0) ||
		(strcmp(cp_f, "66666666666") == 0) || (strcmp(cp_f, "77777777777") == 0) || (strcmp(cp_f, "88888888888") == 0) ||
		(strcmp(cp_f, "99999999999") == 0))
	{
		return 0;
	}
	else
	{
		for (i = 0, j = 10; i < strlen(cp_f) - 2; i++, j--)
		{
			digito1 += (cp_f[i] - 48) *j;
		}
		digito1 %= 11;
		if (digito1 < 2)
		{
			digito1 = 0;
		}
		else
		{
			digito1 = 11 - digito1;
		}
		if ((cp_f[9] - 48) != digito1)
		{
			return 0;
		}
		else
		{
			for (i = 0, j = 11; i < strlen(cp_f) - 1; i++, j--)
			{
				digito2 += (cp_f[i] - 48) *j;
			}
			digito2 %= 11;
		}
		if (digito2 < 2)
		{
			digito2 = 0;
		}
		else
		{
			digito2 = 11 - digito2;
		}
		if ((cp_f[10] - 48) != digito2)
		{
			return 0;
		}
	}
	return 1;
}

int validarsenha(char senha[])
{
	int invalido = 0, valido = 0;
	if (strlen(senha) != 4)
	{
		invalido = 1;
	}
	else
	{
		for (int i = 0; i < strlen(senha); i++)
		{
			if ((senha[i] >= '0') && (senha[i] <= '9'))
			{
				valido = 1;
			}
		}
	}
	if(invalido == 1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void telalogin(){
    char cpf[12];
    char senha[5];
    int login_efetuado = 0;

	system("clear || cls");
    while(!login_efetuado)
    {
        printf("Digite seu CPF: ");
        scanf("%s", cpf);

        printf("Digite seu senha de 4 dígitos: ");
        scanf("%s", senha);

        if (validarcpf(cpf) == 1 && validarsenha(senha) == 1)
		{
			system("clear || cls");
            printf("Login efetuado com sucesso! :)\n\n");
            login_efetuado = 1;
        }
        else
		{	
			system("clear || cls");
            printf("DADOS INVALIDOS!\n\n");    
		}
	}
}

void opArvBin()
{
    printf("**************BEM VINDO**************\n\n");
	printf("1. INSERIR\n");
	printf("2. REMOVER\n");
	printf("3. ALTERAR\n");
	printf("4. BUSCAR\n");
	printf("5. VENDER\n");
	printf("6. RELATORIO POR TIPO\n");
	printf("7. RELATORIO DE VENDAS\n");
	printf("0. SAIR\n\n");
	printf("Opção selecionada: ");
}
