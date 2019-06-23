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
	while (cabeca != NULL)
	{
		printf("Aluno: %s", cabeca->nome);
		printf("Idade: %d\n", cabeca->idade);
		printf("Cpf: %s\n", cabeca->cpf);
		printf("Sexo: %c\n\n", cabeca->sexo);
		cabeca = cabeca->proximo;
	}
}
void busca_aluno(char aluno[40], dados *cabeca)
{
    if (strcasecmp(cabeca->nome, aluno) == 0)
    {
        printf("Aluno %s", cabeca->nome);
		printf("Idade: %d\n", cabeca->idade);
		printf("Cpf: %s\n", cabeca->cpf);
		printf("Sexo: %c\n\n", cabeca->sexo);            
    }
    else
    {
        if (cabeca->proximo != NULL) busca_aluno(aluno, cabeca->proximo);
        else printf("Aluno nao encontrado");
    }
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
    printf("O que deseja?\n");
    printf("[1] Buscar um aluno\n");
    printf("[2] Mostrar todos os alunos\n");
    scanf("%d", &escolha);
    getchar();
    system("clear");
    
    if (escolha == 1)
    {
        printf("Qual aluno voce quer buscar?\n");
        fgets(aluno,40,stdin);
        system("clear");
        busca_aluno(aluno,cadastra);
    }
    else if (escolha == 2)
    {
        system("clear");
        mostra_alunos(cadastra);
    }
    else
    {
        printf("Saindo...\n\n");
    }

	return 0;

}
