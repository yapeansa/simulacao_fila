#ifndef FILA
#define FILA
#define TAM 10

typedef struct fila
{
    int vet[TAM];
    int fim; // onde entra o próximo
} fila;

typedef struct guiche
{
    int ocupado;
    int atendimentos;
} guiche;

int Random(int low, int high);
void initGuiche(guiche **g);
void initFila(fila **f);
int poe(fila *f, int v);
void desloca(fila *f);
int pega(fila *f);
void trataGuiche(guiche *g, fila *f, int t);
void trataCliente(fila *f);
void imprime(fila *f);

#endif
