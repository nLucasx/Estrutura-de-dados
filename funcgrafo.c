GRAFO *cria_grafo()
{
    GRAFO *novo_grafo = malloc(sizeof(GRAFO));
    int i;
    for (i = 0; i < MAX; i++)
    {
        novo_grafo->elementos[i] = NULL;
        novo_grafo->visitados[i] = 0;
    }
    return novo_grafo;
}
NODE *cria_vertice(int valor)
{
    NODE *novo_no = malloc(sizeof(NODE));
    novo_no->item = valor;
    novo_no->proximo = NULL;
    return novo_no;
}
void add_aresta(GRAFO *grafo, int vertice1, int vertice2)
{
    NODE *novo_vertice2 = cria_vertice(vertice2);
    novo_vertice2->proximo = grafo->elementos[vertice1];
    grafo->elementos[vertice1] = novo_vertice2;

    NODE *novo_vertice1 = cria_vertice(vertice1);
    novo_vertice1->proximo = grafo->elementos[vertice2];
    grafo->elementos[vertice2] = novo_vertice1;
}
void dfs(graph *graph, int source)
{
    graph->visited[source] = 1;
    printf("%d\n", source);
    adj_list *adj_list = graph->vertices[source];
    while (adj_list != NULL) {
      if (!graph->visited[adj_list->item]) {
        dfs(graph, adj_list->item);
      }
    adj_list = adj_list->next;
    }
}
void bfs(GRAFO *grafo, int inicio)
{
    FILA *fila = cria_fila();
    int desenfileirado,i;
    NODE *vertice = grafo->elementos[inicio];
    grafo->visitados[inicio] = 1;
    enfileira(fila, inicio);
    while(fila->tam_atual > 0)
    {
        desenfileirado = desenfileira(fila);
        vertice = grafo->elementos[desenfileirado];
        while (vertice != NULL)
        {
            if (!grafo->visitados[vertice->item])
            {
                grafo->visitados[vertice->item] = 1;
                enfileira(fila, vertice->item);
            }
            vertice = vertice->proximo;
        }
    }
    free(fila);
}
