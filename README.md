# Catacumba da Matriz

> Jogo de exploração em uma matriz 5 × 5, desenvolvido em linguagem C.

## Sobre o jogo

Você é um forasteiro que chegou às catacumbas e precisa atravessar uma sala formada por 25 posições até encontrar a saída. Durante o caminho, poderá encontrar ouro, bombas e uma cura. O objetivo é chegar até a saída, localizada na posição `[4][4]`, sem deixar a vida chegar a zero.

## Como jogar

O jogo funciona por meio de um menu principal com quatro opções:

1. **Movimentar personagem:** permite escolher uma direção para andar.
2. **Consultar status:** mostra a posição atual, a vida e as estatísticas da partida.
3. **Mostrar mapa:** exibe a posição atual do personagem, representada pela letra `P`.
4. **Encerrar jogo:** finaliza a execução e apresenta o resumo da partida.

Ao escolher movimentar o personagem, utilize os seguintes comandos:

| Tecla | Direção |
|---|---|
| `1` | Cima |
| `2` | Baixo |
| `3` | Esquerda |
| `4` | Direita |

O personagem começa na posição `[0][0]` e não pode ultrapassar os limites da matriz. Caso seja escolhida uma movimentação inválida, o programa informa o erro e permite tentar novamente.

## Elementos e regras

Cada posição do mapa possui um valor que representa o elemento encontrado:

| Valor | Elemento | O que acontece |
|---:|---|---|
| `0` | Casa vazia | Nada acontece. |
| `1` | Ouro | Aumenta em 1 o contador de ouros encontrados. |
| `2` | Bomba | Retira 35 pontos de vida. |
| `3` | Saída | Finaliza a partida com vitória. |
| `4` | Cura | Recupera 20 pontos de vida. |

A vida começa em **100 pontos**. O ouro é contabilizado nas estatísticas, mas não altera a vida do personagem.

Depois que o jogador encontra ouro, bomba ou cura, a posição correspondente passa a ser considerada vazia. Isso impede que o mesmo elemento seja contabilizado mais de uma vez.

Se a vida chegar a zero, aparece a mensagem **Game Over**. Caso o jogador alcance a saída, é apresentada uma mensagem de vitória.

Nos dois casos, o programa mostra as estatísticas da partida e permite retornar ao menu principal. Ao iniciar uma nova partida, o mapa, a posição do personagem, a vida e os contadores são restaurados.

## Posições dos itens

As coordenadas seguem o formato `[linha][coluna]`, começando pelo índice zero:

- **Ouro:** `[0][2]`, `[1][3]`, `[2][0]`, `[3][3]` e `[4][1]`.
- **Bombas:** `[0][4]`, `[1][1]`, `[2][4]` e `[3][2]`.
- **Cura:** `[2][2]`.
- **Saída:** `[4][4]`.
- **Posição inicial:** `[0][0]`.

## Como o código funciona

O mapa principal é armazenado na matriz `mapa[5][5]`. Cada posição guarda um número que representa o elemento presente naquela casa.

As variáveis `linha` e `coluna` indicam a posição atual do personagem. Já a matriz `mapa_default` mantém uma cópia do cenário original, utilizada para restaurar os elementos quando uma nova partida começa.

### Por que foi utilizada uma matriz?

A matriz foi escolhida porque o cenário possui cinco linhas e cinco colunas. Com ela, fica mais fácil organizar os elementos do jogo e identificar a posição de cada um. Além disso, utilizando os índices de linha e coluna, o programa consegue verificar o que existe em cada casa conforme o personagem se movimenta.

### Utilização do vetor de estatísticas

O vetor `estatisticas[3]` armazena três informações importantes da partida:

- `estatisticas[0]`: quantidade de movimentos realizados.
- `estatisticas[1]`: quantidade de ouros encontrados.
- `estatisticas[2]`: quantidade de bombas encontradas.

O vetor foi utilizado para reunir essas informações em uma única estrutura, evitando a necessidade de criar uma variável separada para cada contador. O dano acumulado pelo personagem é registrado separadamente na variável `dano`.

### Estruturas utilizadas

Durante o desenvolvimento, foram utilizadas diferentes estruturas da linguagem C:

- **`do...while`:** mantém o menu principal funcionando enquanto o jogo não for encerrado. Também é utilizado para repetir a solicitação de retorno ao menu.
- **`for`:** percorre as linhas e colunas das matrizes, sendo utilizado para copiar e restaurar o mapa e para exibir sua representação.
- **`switch`:** organiza as opções do menu principal, executando a funcionalidade correspondente à escolha do jogador.
- **`if` e `else`:** verificam as condições do jogo, como os limites de movimentação, os elementos encontrados, a vida do personagem e a chegada à saída.

## Dificuldades encontradas

Durante o desenvolvimento, alguns pontos exigiram mais atenção, principalmente o controle da movimentação do personagem. Foi necessário criar verificações para impedir que ele ultrapassasse os limites do mapa, evitando que o programa acessasse posições inválidas da matriz.

Outro cuidado foi garantir que os elementos encontrados fossem contabilizados apenas uma vez. Para resolver isso, depois que o jogador encontra ouro, bomba ou cura, o valor daquela posição é alterado para zero.

Também foi necessário implementar uma maneira de restaurar o cenário após uma vitória ou um Game Over. Para isso, foi criada uma cópia do mapa original, permitindo recuperar os elementos e reiniciar as informações da partida sem precisar executar o programa novamente.

## Compilar e executar

Para executar o jogo, é necessário ter o compilador GCC instalado.

Abra o terminal na pasta onde está localizado o arquivo `main.c` e execute os comandos:

```bash
gcc main.c -o catacumba
./catacumba
```

O primeiro comando compila o código e gera o executável. O segundo inicia o jogo.

## Sobre a opção "Mostrar mapa"

A visualização utiliza uma matriz auxiliar chamada `mapa_jogador`. Nela, a posição atual do personagem é representada pela letra `P`, enquanto as demais casas aparecem com o valor `0`.

Por esse motivo, os itens que ainda estão escondidos no mapa principal não são revelados nessa opção.
