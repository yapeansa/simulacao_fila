#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int cliente = 1;
int contaTempoAtendimento = 1; // variável para a contagem do tempo de atendimento.

int Random(int low, int high)
{
    int k;
    double d;
    d = (double)rand() / ((double)RAND_MAX + 1);
    k = d * (high - low + 1);
    return low + k;
}

void initGuiche(guiche **g)
{
    *g = malloc(sizeof(guiche));
    (*g)->atendimentos = 0;
    (*g)->ocupado = 0;
}

void initFila(fila **f)
{
    *f = malloc(sizeof(fila));
    (*f)->fim = 0;
}

int filaCheia(fila *f)
{
    if (f->fim == TAM)
        return 1;

    return 0;
}

int poe(fila *f, int v)
{
    if (filaCheia(f))
    {
        // Escreve no arquivo informando uma eventual ocorrência de fila cheia para um tempo t.
        fprintf(arq, "Fila cheia \n");
        contaFilaCheia++;
        printf("Fila cheia!\n");
        return 0;
    }
    else
    {
        // Escreve no arquivo informando que chegou um cliente em um tempo t.
        fprintf(arq, "Chegou cliente %d\n", cliente);
        printf("Chegou cliente %d\n", cliente);
        f->vet[f->fim] = v;
        f->fim++;
        return 1;
    }
}

// reaproveitamento por deslocamento
void desloca(fila *f)
{
    for (int i = 1; i < f->fim; i++)
    {
        f->vet[i - 1] = f->vet[i];
    }
    f->fim--;
}

// retorna -1 se fila vazia
int pega(fila *f)
{
    int ret = -1;

    if (f->fim != 0)
    {
        ret = f->vet[0];
        desloca(f);
    }
    else
    {
        printf("Fila vazia!\n");
    }
    return ret;
}

void trataGuiche(guiche *g, fila *f, int t)
{
    if (f->fim > 0)
    {
        if (g->ocupado <= contaTempoAtendimento)
        {
            int ret = pega(f);
            /* A condição if (f->fim > 0) já garante que a fila não está vazia.
            Lembrando que pega(f) retorna -1 apenas no caso em que a fila está vazia.
            if (ret != -1)
            {
            Escreve no arquivo informando que um cliente foi chamado para atendimento. */
            fprintf(arq, "Próximo, senha %d \n", ret);
            printf("Proximo, senha %d \n", ret);
            g->ocupado = Random(2, t + 5); // Sorteia o tempo de atendimento para um determinado cliente.
            g->atendimentos++;
            // Escreve no arquivo a informação do tempo de atendimento sorteado para um determinado cliente.
            fprintf(arq, "Tempo de atendimento: %d \n", g->ocupado);
            printf("Tempo de atendimento: %d \n", g->ocupado);
            // }
            contaTempoAtendimento = 0; // Zera a contagem do tempo de atendimento.
        }
        else
            contaTempoAtendimento++; // Contagem do tempo de atendimento.
    }
    else
    {
        /* No início, quando a fila tem apenas um cliente, o mesmo é atendido imediatamente
        Como consequência a fila fica vazia e este trecho de código garante que a contagem do tempo
        atendimento continue e que, quando o próximo cliente chegar na fila vazia,
        ele também seja atendido imediatamente. */
        if (g->ocupado != 0 && contaTempoAtendimento < g->ocupado)
            contaTempoAtendimento++;
    }
}

void trataCliente(fila *f, int t)
{
    if (Random(0, 100) <= (10 * t))
        if (poe(f, cliente))
            cliente++;
}

void imprime(fila *f)
{
    printf("Fila: ");
    for (int i = 0; i < f->fim; i++)
        printf(" %d", f->vet[i]);
    printf("\n");
}

// Função para liberar memória alocada para fila
void liberaFila(fila *f)
{
    free(f);
}

// Função para liberar memória alocada para guichê
void liberaGuiche(guiche *g)
{
    free(g);
}
