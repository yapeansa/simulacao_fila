#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "fila.h"

FILE *arq;
extern int contaFilaCheia; // variável utilizada no arquivo fila.c para contagem de ocorrências de fila cheia

int main()
{
    srand(time(NULL));
    int tempo, sorteiaTempoChegada, sorteiaTempoAtendimento;
    char nomeiaArquivo[10];
    fila *f1;
    guiche *g1;

    // Parâmetro para sortear o tempo de chegada de clientes.
    do
    {
        printf("Parâmetro para o tempo de chegada (valor de 1 a 10): ");
        scanf("%d", &sorteiaTempoChegada);
    } while (sorteiaTempoChegada < 1 || sorteiaTempoChegada > 10);

    // Parâmetro para sortear o tempo de atendimento de clientes.
    do
    {
        printf("Parâmetro para o tempo de atendimento (valor de 0 a 10): ");
        scanf("%d", &sorteiaTempoAtendimento);
    } while (sorteiaTempoAtendimento < 0 || sorteiaTempoAtendimento > 10);

    int i = 1;
    do
    {
        sprintf(nomeiaArquivo, "fila%d.txt", i);
        arq = fopen(nomeiaArquivo, "a"); // Abre o arquivo para escrever os dados.
        tempo = 0;
        initFila(&f1);
        initGuiche(&g1);

        // loop (faz a fila andar)
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

        // Escreve no final do arquivo imprimindo o número de atendimentos.
        fprintf(arq, "Número de atendimentos: %d\n", g1->atendimentos);
        // Escreve no final do arquivo imprimindo o número de ocorrências de fila cheia.
        fprintf(arq, "Ocorrências de fila cheia: %d\n", contaFilaCheia);

        fclose(arq);      // Fecha o arquivo.
        liberaFila(f1);   // libera fila.
        liberaGuiche(g1); // libera guichê;

        i++;

    } while (contaFilaCheia != 0 && i <= 9);

    return 0;
}
