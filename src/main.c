#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define TAM 10

typedef struct
{
    int vet[TAM];
    int fim; // onde entra o próximo
} fila;

typedef struct
{
    int ocupado;
    int atendimentos;
} guiche;

int cliente = 1;

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

int poe(fila *f, int v)
{
    if (f->fim == TAM)
    {
        printf("Fila cheia!\n");
        return 0;
    }
    else
    {
        printf("Chegou cliente %d\n", cliente);
        f->vet[f->fim] = v;
        f->fim++;
        return 1;
    }
}

// reaproveitamento por deslocamento
void desloca(fila *f)
{
    int i;
    for (i = 1; i < f->fim; i++)
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
        if (g->ocupado < t)
        {
            int ret = pega(f);
            if (ret != -1)
            {
                printf("Proximo, senha %d \n", ret);
                g->ocupado = Random(2, 15) + t;
                g->atendimentos++;
            }
        }
    }
}

void trataCliente(fila *f)
{
    if (Random(0, 100) <= 25)
        if (poe(f, cliente))
            cliente++;
}

void imprime(fila *f)
{
    printf("Fila: ");
    int i;
    for (i = 0; i < f->fim; i++)
        printf(" %d", f->vet[i]);
    printf("\n");
}

int main()
{
    srand(time(NULL));
    int tempo = 0;
    fila *f1;
    initFila(&f1);
    guiche *g1;
    initGuiche(&g1);
    // loop
    while (tempo <= 100)
    {
        // trata chegada de cliente
        trataCliente(f1);
        // trata atendimento
        trataGuiche(g1, f1, tempo);
        sleep(2);
        printf("===> Tempo %d\n", tempo++);
        imprime(f1);
    };
    printf("Numero de atendimentos: %d \n", g1->atendimentos);
    return 0;
}
