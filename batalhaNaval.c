#include <stdio.h>

// Definindo as dimensões do tabuleiro e o tamanho fixo dos navios
#define LINHAS 10
#define COLUNAS 10
#define TAMANHO_NAVIO 3

/**
 * @brief Exibe o tabuleiro de Batalha Naval no console.
 *
 * @param tabuleiro A matriz 10x10 que representa o tabuleiro.
 */
void exibirTabuleiro(int tabuleiro[LINHAS][COLUNAS]) {
    int i, j;
    printf("\n--- Tabuleiro de Batalha Naval ---\n");
    
    // Imprime os números das colunas para facilitar a leitura
    printf("   ");
    for (j = 0; j < COLUNAS; j++) {
        printf(" %d", j);
    }
    printf("\n");

    // Imprime o tabuleiro, linha por linha
    for (i = 0; i < LINHAS; i++) {
        printf("%d  ", i); // Imprime o número da linha
        for (j = 0; j < COLUNAS; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief Tenta posicionar um navio no tabuleiro, validando limites e sobreposição.
 *
 * @param tabuleiro A matriz 10x10 do tabuleiro.
 * @param linha_inicio A linha inicial para o posicionamento do navio.
 * @param coluna_inicio A coluna inicial para o posicionamento do navio.
 * @param direcao O tipo de navio ('H' para horizontal, 'V' para vertical,
 * '1' para diagonal descendente, '2' para diagonal ascendente).
 */
void posicionarNavio(int tabuleiro[LINHAS][COLUNAS], int linha_inicio, int coluna_inicio, char direcao) {
    int i, j;
    int pode_posicionar = 1;

    // Primeiro, verifica se o navio cabe no tabuleiro e se não há sobreposição
    switch (direcao) {
        case 'H': // Horizontal
            if (coluna_inicio + TAMANHO_NAVIO > COLUNAS) {
                pode_posicionar = 0;
            } else {
                for (j = 0; j < TAMANHO_NAVIO; j++) {
                    if (tabuleiro[linha_inicio][coluna_inicio + j] == 3) {
                        pode_posicionar = 0;
                        break;
                    }
                }
            }
            break;
        case 'V': // Vertical
            if (linha_inicio + TAMANHO_NAVIO > LINHAS) {
                pode_posicionar = 0;
            } else {
                for (i = 0; i < TAMANHO_NAVIO; i++) {
                    if (tabuleiro[linha_inicio + i][coluna_inicio] == 3) {
                        pode_posicionar = 0;
                        break;
                    }
                }
            }
            break;
        case '1': // Diagonal (descendente)
            if (linha_inicio + TAMANHO_NAVIO > LINHAS || coluna_inicio + TAMANHO_NAVIO > COLUNAS) {
                pode_posicionar = 0;
            } else {
                for (i = 0; i < TAMANHO_NAVIO; i++) {
                    if (tabuleiro[linha_inicio + i][coluna_inicio + i] == 3) {
                        pode_posicionar = 0;
                        break;
                    }
                }
            }
            break;
        case '2': // Diagonal (ascendente)
            if (linha_inicio + TAMANHO_NAVIO > LINHAS || coluna_inicio - (TAMANHO_NAVIO - 1) < 0) {
                pode_posicionar = 0;
            } else {
                for (i = 0; i < TAMANHO_NAVIO; i++) {
                    if (tabuleiro[linha_inicio + i][coluna_inicio - i] == 3) {
                        pode_posicionar = 0;
                        break;
                    }
                }
            }
            break;
        default:
            pode_posicionar = 0; // Direção inválida
            break;
    }

    // Se a posição for válida, preenche o tabuleiro com o navio
    if (pode_posicionar) {
        printf("Navio posicionado com sucesso na posicao (%d, %d) na direcao %c.\n", linha_inicio, coluna_inicio, direcao);
        switch (direcao) {
            case 'H':
                for (j = 0; j < TAMANHO_NAVIO; j++) {
                    tabuleiro[linha_inicio][coluna_inicio + j] = 3;
                }
                break;
            case 'V':
                for (i = 0; i < TAMANHO_NAVIO; i++) {
                    tabuleiro[linha_inicio + i][coluna_inicio] = 3;
                }
                break;
            case '1':
                for (i = 0; i < TAMANHO_NAVIO; i++) {
                    tabuleiro[linha_inicio + i][coluna_inicio + i] = 3;
                }
                break;
            case '2':
                for (i = 0; i < TAMANHO_NAVIO; i++) {
                    tabuleiro[linha_inicio + i][coluna_inicio - i] = 3;
                }
                break;
        }
    } else {
        printf("Aviso: Nao foi possivel posicionar um navio na posicao (%d, %d) na direcao %c devido a limites ou sobreposicao.\n", linha_inicio, coluna_inicio, direcao);
    }
}

int main() {
    // 1. Criação e inicialização do tabuleiro
    int tabuleiro[LINHAS][COLUNAS];
    int i, j;
    
    // Inicializa todas as posições com 0
    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    
    // 2. Posicionamento dos navios com coordenadas que não se sobrepõem
    // Navio horizontal
    posicionarNavio(tabuleiro, 2, 1, 'H');
    
    // Navio vertical
    posicionarNavio(tabuleiro, 5, 8, 'V');
    
    // Navio diagonal descendente
    posicionarNavio(tabuleiro, 6, 1, '1');
    
    // Navio diagonal ascendente - COORDENADA CORRIGIDA!
    posicionarNavio(tabuleiro, 6, 7, '2');
    
    // 3. Exibição do tabuleiro completo
    exibirTabuleiro(tabuleiro);

    return 0;
}