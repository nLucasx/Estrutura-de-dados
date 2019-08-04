#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 300
typedef struct heap
{
    int tam_atual, dados[MAX];
}HEAP;

HEAP *cria_heap()
{
    HEAP *nova_heap = malloc(sizeof(HEAP));
    nova_heap->tam_atual = 0;
    return nova_heap;
}
int indice_pai(int i)
{
    return i/2;
}
int indice_esquerda(int i)
{
    return 2*i;
}
int indice_direita(int i)
{
    return (2*i) + 1;
}
void maxheapify(HEAP *heap, int i)
{
    int iesq = indice_esquerda(i), idir = indice_direita(i), maior, temp;
    if (iesq <= heap->tam_atual && heap->dados[iesq] > heap->dados[i]) maior = iesq;
    else maior = i;

    if (idir <= heap->tam_atual && heap->dados[idir] > heap->dados[maior]) maior = idir;

    if  (heap->dados[i] != heap->dados[maior])
    {
        temp = heap->dados[i];
        heap->dados[i] = heap->dados[maior];
        heap->dados[maior] = temp;
        maxheapify(heap, maior);
    }
}
void enqueue(HEAP *heap, int valor)
{
    int temp;
    if (heap->tam_atual < MAX)
    {
        heap->dados[++heap->tam_atual] = valor;
        int i = heap->tam_atual;
        int ipai = indice_pai(i);
        while (ipai >= 1 && heap->dados[i] > heap->dados[ipai])
        {
            temp = heap->dados[i];
            heap->dados[i] = heap->dados[ipai];
            heap->dados[ipai] = temp;

            i = ipai;
            ipai = indice_pai(i);
        }
    }
}
int dequeue(HEAP *heap)
{
    if (heap->tam_atual > 0)
    {
        int valor = heap->dados[1];
        heap->dados[1] = heap->dados[heap->tam_atual];
        heap->tam_atual--;
        max_heapify(heap, 1);
	return valor;
    }
}
