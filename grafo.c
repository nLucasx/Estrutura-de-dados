#include <stdio.h>
#include <stdlib.h>
#define MAX 20
typedef struct no{
    int item;
    struct no * proximo;
}no;

typedef struct grafo{
    no *elementos[MAX];
    int visitados[MAX];
}grafo;

grafo *cria_grafo()
{
    grafo *novo_grafo = malloc(sizeof(grafo));
    int i;
    for (i = 0; i < MAX; i++)
    {
        novo_grafo->elementos[i] = NULL;
        novo_grafo->visitados[i] = 0;
    }
    return novo_grafo;
}
no *cria_vertice(int valor)
{
    no *novo_vertice = malloc(sizeof(no));
    novo_vertice->proximo = NULL;
    novo_vertice->item = valor;
    return novo_vertice;
}
void add_aresta(grafo *grafo, int vertice1, int vertice2)
{
    no *novo_vertice = cria_vertice(vertice2);
    novo_vertice->proximo = grafo->elementos[vertice1];
    grafo->elementos[vertice1] = novo_vertice;

    novo_vertice = cria_vertice(vertice1);
    novo_vertice->proximo = grafo->elementos[vertice2];
    grafo->elementos[vertice2] = novo_vertice;
}
void dfs(grafo *grafo, int vertice)
{
    grafo->visitados[vertice] = 1;
    printf("%d\n", vertice);

    no *aresta = grafo->elementos[vertice];

    while (aresta != NULL)
    {
        if (!grafo->visitados[aresta->item])
        {
            dfs(grafo, aresta->item);
        }
        aresta = aresta->proximo;
    }
}
int main()
{
    grafo *grafo = cria_grafo();
    add_aresta(grafo, 6, 4);
    add_aresta(grafo, 9, 1);
    add_aresta(grafo, 9, 2);
    add_aresta(grafo, 9, 6);
    add_aresta(grafo, 1, 5);
    add_aresta(grafo, 1, 3);

    dfs(grafo, 6);
}