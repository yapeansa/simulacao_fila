# Simulação de Filas

Simulação de Filas: Modificar o código pegando os parâmetros do problema ( probabilidades). Gerar dados em arquivo (para importação para planilha e fazer gráficos) sobre tempo de atendimento, ocorrências de fila cheia e número de clientes atendidos.

## Função Principal `main()`

Inicialmente pede-se ao usuário dois parâmetros, sendo o primeiro relativo ao sorteio do tempo de chagada do cliente (de 1 até 10) e o segundo relativo ao sorteio do tempo de atendimento para os clientes (de 0 até 10).

Em seguida, iniciamos um loop que será executado até que haja 0 ocorrências de fila cheia em alguma fila. Cada iteração desse loop é referente à uma fila específica e para cada uma delas é gerado um arquivo para o registro das informações. Além disso, o loop estabelece as condições iniciais para uma fila.

