typedef struct pilha{
    int tam_atual;
    char empilha[tam_max];
}pilha;

pilha * cria_pilha()
{
	pilha *nova_pilha = malloc(sizeof(pilha));
	nova_pilha->tam_atual = 0;
	return nova_pilha;
}
int is_empty(pilha *pilha)
{
	return pilha->tam_atual == 0 ? 1 : 0;
}
void push(pilha *pilha, char item)
{
    pilha->empilha[pilha->tam_atual] = item;
	  pilha->tam_atual++;
}
int pop(pilha *pilha)
{
	if (!is_empty(pilha))
	{
        pilha->tam_atual--;
        return pilha->empilha[pilha->tam_atual];
	}
}
