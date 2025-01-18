#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "fila.h"

FILE *arq;
int contaFilaCheia;

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

    // faz o loop até que se tenh zero ocorrência de fila cheia em um guichê
    int i = 1;
    do
    {
        sprintf(nomeiaArquivo, "fila%d.txt", i); // Formata o nome do arquivo de arcordo com o loop.
        arq = fopen(nomeiaArquivo, "w");         // Abre o arquivo para escrever os dados.

        // Escreve os parâmetros determinados pelo usuário
        fprintf(arq, "Parâmetros para sorteio. Tempo de chegada: %d; Tempo de atendimento: %d\n\n", sorteiaTempoChegada, sorteiaTempoAtendimento);

        // Estabelece condições iniciais para cada iteração do loop.
        tempo = 0;
        initFila(&f1);
        initGuiche(&g1);
        contaFilaCheia = 0;

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
        liberaFila(&f1);   // libera fila.
        liberaGuiche(&g1); // libera guichê;

        i++;

    } while (contaFilaCheia != 0 /* && i <= 9*/);

    return 0;
}
