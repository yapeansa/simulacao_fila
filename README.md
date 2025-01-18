# Simulação de Filas

Simulação de Filas: Modificar o código pegando os parâmetros do problema (probabilidades). Gerar dados em arquivo (para importação para planilha e fazer gráficos) sobre tempo de atendimento, ocorrências de fila cheia e número de clientes atendidos. A seguir está um resumo das implementações feitas no código base do trabalho.

## Função Principal `main()`

Inicialmente pede-se ao usuário dois parâmetros, sendo o primeiro relativo ao sorteio do tempo de chagada do cliente (de 1 até 10) e o segundo relativo ao sorteio do tempo de atendimento para os clientes (de 0 até 10).

Em seguida, iniciamos um loop que será executado até que haja 0 ocorrências de fila cheia em alguma fila. Cada iteração desse loop é referente à uma fila específica e para cada uma delas é gerado um arquivo para o registro das informações. Além disso, o loop estabelece as condições iniciais para uma fila, envolvendo as funções `initFila()`, `initGuiche()`, e variáveis para tempo e contagem de fila cheia.

Logo em seguida, no interior do loop anterior, inicia-se um novo loop. Esse novo loop, que representa a fila, é executado do tempo 0 até o tempo 100. A cada tempo t, duas funções são executadas: `trataCliente()` e `trataGuiche()`. A função trataCliente() recebe dois parâmetros: a fila e o parâmetro fornecido pelo usuário para o sorteio da chegada de clientes. Já a função trataGuiche(), recebe três parâmetros: o guichê, a fila e um parâmetro fornecido pelo usuário para sorteio do tempo de atendimento. Além disso, imprime-se na tela informações como tempo e os elementos a fila. Após o loop, escreve-se em arquivo informações sobre o número de atendimentos para determinada fila e a contagem de ocorrências de fila cheia. Além disso, o arquivo é fechado e libera-se a memória que foi alocada para o guichê e para a fila.

## Função `initFila()`

A função initFila() recebe por parâmetro a fila (por referência). Esta função é responsável por alocar memória dinâmicamente para a fila e inicializá-la, isto é, inicializa o campo `fim` com o valor 0.

## Função `initGuiche()`

A função initGuiche() recebe por parâmetro o guichê (também por referência). Então a memória é alocada dinamicamente para o guichê e os campos `atendimentos` e `ocupado` são ambos inicializados com o valor 0.

## Função `trataCliente()`

...

## Função `trataGuiche()`

...

## `liberaFila()`

Precisamos liberar a memória alocada dinamicamente para cada fila na execução do primeiro loop da função principal. Desta forma, a função liberaFila() recebe como parâmetro a fila para que a memória seja desalocada.

## `liberaGuiche()`

Do mesmo modo precisamos deslocar a memória alocada para o guichê. A função em questão recebe como parâmetro o guichê para a memória seja liberada.
