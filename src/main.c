#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "fila.h"

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

    return 0;
}
