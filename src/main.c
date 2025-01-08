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
    int tempo = 0,
        sorteiaTempoChegada,
        sorteiaTempoAtendimento;
    char nomeArquivo[12];
    fila *f1;
    initFila(&f1);
    guiche *g1;
    initGuiche(&g1);

    // Parâmetro para sortear o tempo de chegada de clientes
    do
    {
        printf("Parâmetro para o tempo de chegada: ");
        scanf("%d", &sorteiaTempoChegada);
    } while (sorteiaTempoChegada < 0 || sorteiaTempoChegada > 100);

    // Parâmetro para sortear o tempo de atendimento de clientes
    do
    {
        printf("Parâmetro para o tempo de atendimento (valor de 5 a 10): ");
        scanf("%d", &sorteiaTempoAtendimento);
    } while (sorteiaTempoAtendimento < 5 || sorteiaTempoAtendimento > 10);

    // Abre o arquivo para escrever os dados
    arq = fopen("dados.txt", "a");

    // loop
    while (tempo <= 100)
    {
        // trata chegada de cliente
        trataCliente(f1, sorteiaTempoChegada);
        // trata atendimento
        trataGuiche(g1, f1, sorteiaTempoAtendimento);
        sleep(1);
        fprintf(arq, "===> Tempo %d\n", tempo);
        printf("===> Tempo %d\n", tempo++);
        imprime(f1);
        fprintf(arq, "\n");
        printf("\n");
    };

    // Escreve no arquivo imprimindo no final o número de atendimentos
    fprintf(arq, "Número de atendimentos: %d\n", g1->atendimentos);
    fprintf(arq, "Ocorrências de fila cheia: %d\n", contaFilaCheia);

    // Fecha o arquivo
    fclose(arq);
    return 0;
}
