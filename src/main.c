#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "fila.h"

FILE *arq;
extern int contaFilaCheia;

int main()
{
    srand(time(NULL));
    int tempo, sorteiaTempoChegada, sorteiaTempoAtendimento;
    char nomeiaArquivo[12];
    fila *f1;
    guiche *g1;

    // Parâmetro para sortear o tempo de chegada de clientes.
    do
    {
        printf("Parâmetro para o tempo de chegada: ");
        scanf("%d", &sorteiaTempoChegada);
    } while (sorteiaTempoChegada < 0 || sorteiaTempoChegada > 100);

    // Parâmetro para sortear o tempo de atendimento de clientes.
    do
    {
        printf("Parâmetro para o tempo de atendimento (valor de 5 a 10): ");
        scanf("%d", &sorteiaTempoAtendimento);
    } while (sorteiaTempoAtendimento < 5 || sorteiaTempoAtendimento > 10);

    int i = 1;
    do
    {
        sprintf(nomeiaArquivo, "fila%d.txt", i);
        arq = fopen(nomeiaArquivo, "a"); // Abre o arquivo para escrever os dados.
        tempo = 0;
        initFila(&f1);
        initGuiche(&g1);

        // loop
        while (tempo <= 100)
        {
            // trata chegada de cliente
            trataCliente(f1, sorteiaTempoChegada);
            // trata atendimento
            trataGuiche(g1, f1, sorteiaTempoAtendimento);
            sleep(1);
            fprintf(arq, "===> Tempo %d\n", tempo); // Escreve no arquivo o tempo atual.
            printf("===> Tempo %d\n", tempo++);
            imprime(f1);
            fprintf(arq, "\n");
            printf("\n");
        };

        // Escreve no arquivo imprimindo no final o número de atendimentos.
        fprintf(arq, "Número de atendimentos: %d\n", g1->atendimentos);
        // Escreve no arquivo imprimindo no final o número de ocorrências de fila cheia.
        fprintf(arq, "Ocorrências de fila cheia: %d\n", contaFilaCheia);
        i++;

    } while (contaFilaCheia != 0 && i <= 5);

    fclose(arq);      // Fecha o arquivo.
    liberaFila(f1);   // libera fila.
    liberaGuiche(g1); // libera guichê;
    return 0;
}
