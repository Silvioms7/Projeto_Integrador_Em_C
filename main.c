#include <stdio.h>
#include <stdbool.h>

void main ()
{
    int linha = 0;
    int coluna = 0;   
    int life  = 100;
    int mov = 0;
    int i;
    int j;
    int posicao[5][5];
    int map[5][5]  = {
        {0, 0, 1, 0, 2},
        {0, 2, 0, 1, 0},
        {1, 0, 4, 0, 2}, // 0 = espaco vazio, 1 = ouro, 2 = bomba, 3 = saida, 4 = cura
        {0, 0, 2, 1, 0},
        {0, 1, 0, 0, 3}

        /*
        Ouro:
        map[0][2]
        map[1][3]
        map[2][0]
        map[3][3]
        map[4][1]

        Cura:
        + 20 de vida
        map[2][2]

        Bomba:
        - 35 de vida
        map[0][4] 
        map[1][1]
        map[2][4]
        map[3][2]
        
        Saida:
        map[4][4]
        */
    };

    int estatisticas[3] = {0, 0, 0};

    // estatisticas[0] -> quantidade de movimentos
    // estatisticas[1] -> quantidade de ouros encontrados
    // estatisticas[2] -> quantidade de inimigos encontrados
    
    do{
        printf("\n");
        printf("==============================\n");
        printf("AVENTURA NA MATRIZ\n");
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
            printf("Encerrando o jogo...");
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
                if (((mov == 1 || mov == 3) && (linha == 0 && coluna == 0)) || ((mov == 2 || mov == 3) && (linha == 4 && coluna == 0)) || ((mov == 2 || mov == 4) && (linha == 4 &&  coluna == 4)) || ((mov == 1 || mov == 4) && (linha == 0 && coluna == 4)))
                    {
                        printf("Movivementacao invalida. Jogar novamente! \n");
                        break;
                    }
                else
                {
                    if (mov == 1)
                    {
                        linha -= 1;
                        estatisticas[0] = estatisticas[0]+1;
                        break;
                    }
                    else
                    {
                        if (mov == 2){
                            linha += 1;
                            estatisticas[0] = estatisticas[0]+1;
                            break;
                        }
                        else 
                        {
                            if (mov == 3)
                            {
                                coluna -= 1;
                                estatisticas[0] = estatisticas[0]+1;
                                break;
                            }
                            else
                            {
                                if (mov == 4)
                                {
                                    coluna += 1;
                                    estatisticas[0] = estatisticas[0]+1;
                                    break;
                                }
                                else
                                {
                                    printf("Opcao invalida!");
                                    break;
                                }
                            }
                        }
                    }
                }
                break;
            case 2:
                printf("Posicao atual: (%d, %d)\n", linha, coluna);
                printf("Vida: %d\n", life);
                printf("Movimentos realizados: %d\n", estatisticas[0]);
                printf("Ouros encontrados: %d\n", estatisticas[1]);
                printf("Inimigos encontrados: %d\n", estatisticas[2]);
                break;
            case 3:
                for (i = 0; i < 5; i++)
                {
                    for (j = 0; j < 5; j++)
                    {
                        if (i == linha && j == coluna)
                        {
                            printf("P ");   
                        }
                        else
                        {
                            printf("%d ", map[i][j]);
                        }
                    }
                    printf("\n");
                }
                break;
            default:
                printf("Opção inválida!\n");
        }

        if(map[linha][coluna] == 1){
        if (linha == 0 && coluna == 2) 
        {
            estatisticas[1] += 1;
            map[0][2] = 0;
        }
        else
        {
            if (linha == 1 && coluna == 3)
            {
               estatisticas[1] += 1; 
               map[1][3] = 0;
            }
            else
            {
                if (linha == 2 && coluna == 0)
                {
                    estatisticas[1] += 1;
                    map[2][0] = 0;
                }
                else
                {
                    if (linha == 3 && coluna == 3)
                    {
                        estatisticas[1] += 1;
                        map[3][3] = 0;
                    }
                    else
                    {
                        if (linha == 4 && coluna == 1 &&)
                        {
                            estatisticas[1] += 1;
                            map[4][1] = 0;
                        }
                    }
                }
            }
        }
    }
        if (map[linha][coluna] == 2)
        {
            if (linha == 0 && coluna == 4) 
        {
            life -= 35;
            estatisticas[2] += 1;
            map[0][4] = 0;
        }
        else
        {
            if (linha == 1 && coluna == 1)
            {
                life -= 35;
                estatisticas[2] += 1;
                map[1][1] = 0;
            }
            else
            {
                if (linha == 2 && coluna == 4)
                {
                    life -= 35;
                    estatisticas[2] += 1;
                    map[2][4] = 0;
                }
                else
                {
                    if (linha == 3 && coluna == 2)
                    {
                        life -= 35;
                        estatisticas[2] += 1;
                        map[3][2] = 0;
                    }
                }
            }
        }
    }
    if (life <= 0)
    {
        printf("Game Over!");
        life = 0;
        break;
    }
    }while(true);

    printf("Vida: %d\n", life);
    printf("Movimentos realizados: %d\n", estatisticas[0]);
    printf("Ouros encontrados: %d\n", estatisticas[1]);
    printf("Inimigos encontrados: %d\n", estatisticas[2]);
}