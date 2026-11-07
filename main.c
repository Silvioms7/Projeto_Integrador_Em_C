#include <stdio.h>
#include <stdbool.h>

void main()
{
    int linha = 0;
    int coluna = 0;
    int vida = 100;
    int dano = 0;
    int mov = 0;
    int opcao = 0;
    int i;
    int j;
    int mapa_jogador[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};
    int mapa[5][5] = {
        {0, 0, 1, 0, 2},
        {0, 2, 0, 1, 0},
        {1, 0, 4, 0, 2}, // 0 = espaco vazio, 1 = ouro, 2 = bomba, 3 = saida, 4 = cura
        {0, 0, 2, 1, 0},
        {0, 1, 0, 0, 3}

        /*
        1 - Cima\n");
        2 - Baixo\n");
        3 - Esquerda\n");
        4 - Direita\n");

        Ouro:
        mapa[0][2]
        mapa[1][3]
        mapa[2][0]
        mapa[3][3]
        mapa[4][1]

        Cura:
        + 20 de vida
        mapa[2][2]

        Bomba:
        - 35 de vida
        mapa[0][4]
        mapa[1][1]
        mapa[2][4]
        mapa[3][2]

        Saida:
        mapa[4][4]
        */
    };
    int mapa_default[5][5];

    int estatisticas[3] = {0, 0, 0};

    // estatisticas[0] -> quantidade de movimentos
    // estatisticas[1] -> quantidade de ouros encontrados
    // estatisticas[2] -> quantidade de bombas encontradas

    printf("\n\nParabens forasteiro\n");
    printf("Você chegou nas catacumbas da matriz\n");
    printf("Atravesse a sala se conseguir\n");
    printf("Mas cuidado pois cada piso é uma surpresa, podendo conter bombas, ouro, ou uma cura\n");
    printf("Boa sorte!!\n");
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            mapa_default[i][j] = mapa[i][j];
        }
    }

    do
    {
        printf("\n");
        printf("==============================\n");
        printf("     CATACUMBA DA MATRIZ\n");
        printf("==============================\n");
        printf("1 - Movimentar personagem\n");
        printf("2 - Consultar status\n");
        printf("3 - Mostrar mapa\n");
        printf("4 - Encerrar jogo\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        printf("\n");

        if (opcao == 4)
        {
            printf("Encerrando o jogo...\n\n");

            printf("==========================================\n");
            printf("          O JOGO FOI ENCERRADO!           \n");
            printf("==========================================\n");

            printf("Quantidade de movimentos feitos: %d\n", estatisticas[0]);
            printf("Quantidade de ouro pego: %d\n", estatisticas[1]);
            printf("Quantidade de dano tomado: %d\n", dano);
            printf("Quantidade de bombas encontradas: %d\n\n", estatisticas[2]);
            break;
        }

        switch (opcao)
        {
        case 1:
            printf("1 - Cima\n");
            printf("2 - Baixo\n");
            printf("3 - Esquerda\n");
            printf("4 - Direita\n");
            printf("\nEscolha uma opcao: ");
            scanf("%d", &mov);
            if (((mov == 1 || mov == 3) && linha == 0 && coluna == 0) || ((mov == 1 || mov == 4) && linha == 0 && coluna == 4) || ((mov == 1 && linha == 0 && coluna >= 0) || ((mov == 3) && linha == 4 && coluna == 0) || ((mov == 3) && linha >= 0 && coluna == 0)) || ((mov == 4 || mov == 2) && linha == 4 && coluna == 4) || ((mov == 2) && linha == 4 && coluna >= 0) || ((mov == 4) && coluna == 4 && linha >= 0))
            {
                printf("\nMovivementacao invalida. Jogar novamente! \n");
                break;
            }
            else
            {
                if (mov == 1)
                {
                    linha -= 1;
                    estatisticas[0] = estatisticas[0] + 1;
                    break;
                }
                else
                {
                    if (mov == 2)
                    {
                        linha += 1;
                        estatisticas[0] = estatisticas[0] + 1;
                        break;
                    }
                    else
                    {
                        if (mov == 3)
                        {
                            coluna -= 1;
                            estatisticas[0] = estatisticas[0] + 1;
                            break;
                        }
                        else
                        {
                            if (mov == 4)
                            {
                                coluna += 1;
                                estatisticas[0] = estatisticas[0] + 1;
                                break;
                            }
                            else
                            {
                                printf("Opcao indisponivel!");
                                break;
                            }
                        }
                    }
                }
            }
            break;
        case 2:
            printf("\n############## STATUS ##############\n");
            printf("Posicao atual: (%d, %d)\n", linha, coluna);
            printf("Vida: %d\n", vida);
            printf("Movimentos feitos: %d\n", estatisticas[0]);
            printf("Ouros encontrados: %d\n", estatisticas[1]);
            printf("Bombas encontradas: %d\n", estatisticas[2]);
            printf("####################################\n");
            break;
        case 3:
            printf("---------------\n");
            for (i = 0; i < 5; i++)
            {
                printf("|  ");
                for (j = 0; j < 5; j++)
                {

                    if (i == linha && j == coluna)
                    {
                        printf("P ");
                    }
                    else
                    {
                        printf("%d ", mapa_jogador[i][j]);
                    }
                }
                printf(" |");
                printf("\n");
            }
            printf("---------------");
            break;
        default:
            printf("Opção indisponivel!\n");
        }

        if (mapa[linha][coluna] == 1)
        {
            if (linha == 0 && coluna == 2)
            {
                estatisticas[1] += 1;
                mapa[0][2] = 0;
            }
            else
            {
                if (linha == 1 && coluna == 3)
                {
                    estatisticas[1] += 1;
                    mapa[1][3] = 0;
                }
                else
                {
                    if (linha == 2 && coluna == 0)
                    {
                        estatisticas[1] += 1;
                        mapa[2][0] = 0;
                    }
                    else
                    {
                        if (linha == 3 && coluna == 3)
                        {
                            estatisticas[1] += 1;
                            mapa[3][3] = 0;
                        }
                        else
                        {
                            if (linha == 4 && coluna == 1)
                            {
                                estatisticas[1] += 1;
                                mapa[4][1] = 0;
                            }
                        }
                    }
                }
            }
        }

        if (mapa[linha][coluna] == 4)
        {
            vida += 20;
            printf("Parabens você encontrou uma cura. Vida atual: %d", vida);
            mapa[linha][coluna] = 0;
        }
        if (mapa[linha][coluna] == 2)
        {
            vida -= 35;
            if (vida < 0)
            {
                vida = 0;
            }
            printf("\nBOOOM!! você pisou em uma bomba.\nVida restante = %d \n", vida);
            dano += 35;
            estatisticas[2] += 1;
            mapa[linha][coluna] = 0;
        }
        if (mapa[linha][coluna] == 3)
        {
            printf("==========================================\n");
            printf("   PARABÉNS VOCẼ CONSEGUIU ATRAVESSAR!!!\n");
            printf("==========================================\n");

            printf("Quantidade de movimentos feitos: %d\n", estatisticas[0]);
            printf("Quantidade de ouro pego: %d\n", estatisticas[1]);
            printf("Quantidade de dano tomado: %d\n", dano);
            printf("Quantidade de bombas encontradas: %d\n", estatisticas[2]);
            do
            {
                printf("\nDigite 1 para retornar ao menu: ");
                scanf("%d", &opcao);
                if (opcao != 1)
                {
                    printf("\n\nOpção indisponivel tente novamente!\n\n");
                    opcao = 0;
                }
            } while (opcao != 1);

            // Restaurar mapa para o mapa padrão
            for (i = 0; i < 5; i++)
            {
                for (j = 0; j < 5; j++)
                {
                    mapa[i][j] = mapa_default[i][j];
                }
            }

            // Restaurar posição do jogador para a posição inicial
            linha = 0;
            coluna = 0;

            // Voltar a vida cheia
            vida = 100;

            // Restaurar a Variavel de dano recebido
            dano = 0;

            // Restauras estatisticas
            estatisticas[0] = 0;
            estatisticas[1] = 0;
            estatisticas[2] = 0;
            continue;
        }
        if (vida <= 0)
        {
            vida = 0;
            printf("\n===============================\n");
            printf("          Game Over!\n");
            printf("===============================\n");
            printf("Quantidade de movimentos feitos: %d\n", estatisticas[0]);
            printf("Quantidade de ouro pego: %d\n", estatisticas[1]);
            printf("Quantidade de dano sofrido: %d\n", dano);
            printf("Quantidade de bombas encontradas: %d\n", estatisticas[2]);

            do
            {
                printf("\nDigite 1 para retornar ao menu: ");
                scanf("%d", &opcao);
                if (opcao != 1)
                {
                    printf("\n\nOpção indisponivel tente novamente!\n\n");
                    opcao = 0;
                }
            } while (opcao != 1);

            for (i = 0; i < 5; i++)
            {
                for (j = 0; j < 5; j++)
                {
                    mapa[i][j] = mapa_default[i][j];
                }
            }

            linha = 0;
            coluna = 0;

            vida = 100;

            dano = 0;

            estatisticas[0] = 0;
            estatisticas[1] = 0;
            estatisticas[2] = 0;
            continue;
        }
    } while (true);
}
