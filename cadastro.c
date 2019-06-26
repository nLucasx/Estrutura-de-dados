#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct alunos{
	char nome[40], cpf[20], sexo;
	int idade;
	struct alunos *proximo;
}dados;

dados * cadastra_aluno(dados * cabeca, char aluno[40], int idadealuno, char sexoaluno, char ncpf[20])
{
	dados *novo_aluno = malloc(sizeof(dados));
	strcpy(novo_aluno->nome, aluno);
	novo_aluno->idade = idadealuno;
	novo_aluno->sexo = sexoaluno;
	strcpy(novo_aluno->cpf, ncpf);
	novo_aluno->proximo = cabeca;
	return novo_aluno;

}
void mostra_alunos(dados *cabeca)
{
	if (cabeca == NULL)
	{
	    printf("A lista esta vazia\n");
	}
	while (cabeca != NULL)
	{
		printf("Aluno: %s", cabeca->nome);
		printf("Idade: %d\n", cabeca->idade);
		printf("Cpf: %s\n", cabeca->cpf);
		printf("Sexo: %c\n\n", cabeca->sexo);
		cabeca = cabeca->proximo;
	}
}
void imprime_aluno(int flag, dados *cabeca)
{
    if (flag)
    {
        printf("Aluno %s", cabeca->nome);
		printf("Idade: %d\n", cabeca->idade);
		printf("Cpf: %s\n", cabeca->cpf);
		printf("Sexo: %c\n\n", cabeca->sexo);            
    }
    else printf("Aluno nao encontrado\n");
}
int existe_aluno(char aluno[40], dados *cabeca)
{
	if (cabeca == NULL)
	{
	    return 0;
	}
	if (strcasecmp(cabeca->nome, aluno) == 0)
	{
		return 1;
	}
	else
	{
		if (cabeca->proximo != NULL) return existe_aluno(aluno, cabeca->proximo);
        else return 0;
	}
}
dados * retorna_posicao(char aluno[40], dados *cabeca)
{
	if (strcasecmp(cabeca->proximo->nome, aluno) == 0)
	{
		return cabeca;
	}
	retorna_posicao(aluno, cabeca->proximo);
}
void apaga_aluno(char aluno[40], dados *cabeca)
{
	cabeca = retorna_posicao(aluno,cabeca);
	dados *auxiliar;
	auxiliar = cabeca->proximo;
	cabeca->proximo = auxiliar->proximo;
	free(auxiliar);
	printf("Cadastro apagado com sucesso!\n");
	
	
}
int main()
{
	dados *cadastra = NULL;
	int qt, i, idade, escolha;
	char aluno[40], sexo, cpf[20];
	printf("Quantos alunos voce quer cadastrar?\n");
	scanf("%d", &qt);
	getchar();
	
	for (i = 0; i < qt; i++)
	{
	    system("clear");
	    printf("Digite o nome >> ");
	    fgets(aluno,40,stdin);
	    printf("Digite a idade >> ");
	    scanf("%d", &idade);
	    printf("Digite o cpf >>");
	    scanf(" %s", cpf);
	    printf("Digite o sexo >> ");
	    scanf(" %c", &sexo);
	    getchar();
	    
	    cadastra = cadastra_aluno(cadastra, aluno, idade, sexo, cpf);
	}
    system("clear");
    printf("Aluno(s) cadastrado(s) com sucesso!\n");
    inicio:
    printf("O que deseja?\n");
    printf("[1] Buscar um aluno\n");
    printf("[2] Mostrar todos os alunos\n");
    printf("[3] Apagar um aluno cadastrado\n");
    printf("[4] Cadastrar mais alunos\n");
    scanf("%d", &escolha);
    getchar();
    system("clear");
    
    if (escolha == 1)
    {
        printf("Qual aluno voce quer buscar?\n");
        fgets(aluno,40,stdin);
        system("clear");
        imprime_aluno(existe_aluno(aluno,cadastra),cadastra);
        printf("Deseja fazer outra operacao?\n");
        printf("[1] SIM\n");
        printf("[2] NAO\n");
        scanf("%d", &escolha);
        if (escolha == 1)
        {
            goto inicio;
        }
        else
        {
            printf("Saindo...\n\n");
        }
    }
    else if (escolha == 2)
    {
        system("clear");
        mostra_alunos(cadastra);
        printf("Deseja fazer outra operacao?\n");
        printf("[1] SIM\n");
        printf("[2] NAO\n");
        scanf("%d", &escolha);
        if (escolha == 1)
        {
            goto inicio;
        }
        else
        {
            printf("Saindo...\n\n");
        }
    }
    else if (escolha == 3)
    {
    	printf("De qual aluno voce quer apagar o cadastro?\n");
    	fgets(aluno,40,stdin);
    	system("clear");
    	int existe = existe_aluno(aluno, cadastra);
    	if (existe)
    	{
    		if (cadastra->proximo == NULL)
    		{
    		    cadastra = NULL;
    		    printf("Cadastro apagado com sucesso!\n");
    		    mostra_alunos(cadastra);
    		}
    		else if (strcasecmp(cadastra->nome, aluno) == 0)
    		{
    		    dados *auxiliar = cadastra;
    		    cadastra = cadastra->proximo;
    		    free(auxiliar);
    		    mostra_alunos(cadastra);
    		}
    		else
    		{
    		    apaga_aluno(aluno, cadastra);
    		    mostra_alunos(cadastra);
    		}
    	}
    	else
    	{
    	    printf("O Aluno nao esta cadastrado!\n");
    	}
        
        printf("Deseja fazer outra operacao?\n");
        printf("[1] SIM\n");
        printf("[2] NAO\n");
        scanf("%d", &escolha);
        if (escolha == 1)
        {
            goto inicio;
        }
        else
        {
            printf("Saindo...\n\n");
        }
    }
    else if (escolha == 4)
    {
        printf("Quantos alunos voce quer cadastrar?\n");
	    scanf("%d", &qt);
	    getchar();
	
	    for (i = 0; i < qt; i++)
	    {
	        system("clear");
	        printf("Digite o nome >> ");
	        fgets(aluno,40,stdin);
	        printf("Digite a idade >> ");
	        scanf("%d", &idade);
	        printf("Digite o cpf >>");
	        scanf(" %s", cpf);
	        printf("Digite o sexo >> ");
	        scanf(" %c", &sexo);
	        getchar();
	    
	        cadastra = cadastra_aluno(cadastra, aluno, idade, sexo, cpf);
	    }
	    printf("Aluno(s) cadastrado(s) com sucesso!\n");
        printf("Deseja fazer outra operacao?\n");
        printf("[1] SIM\n");
        printf("[2] NAO\n");
        scanf("%d", &escolha);
        if (escolha == 1)
        {
            goto inicio;
        }
        else
        {
            printf("Saindo...\n\n");
        }
    }
    else
    {
        system("clear");
        printf("Deseja fazer outra operacao?\n");
        printf("[1] SIM\n");
        printf("[2] NAO\n");
        scanf("%d", &escolha);
        if (escolha == 1)
        {
            goto inicio;
        }
        else
        {
            printf("Saindo...\n\n");
        }
    }

	return 0;

}
