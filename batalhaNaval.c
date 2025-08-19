#include <stdio.h>

// --- Constantes do Código Original ---
#define LINHAS 10
#define COLUNAS 10
#define TAMANHO_NAVIO 3

// NOVO: Constante para o tamanho do tabuleiro de habilidades
#define HABILIDADE_TAMANHO 15

// --- Protótipos das Funções ---
void exibirTabuleiro(int tabuleiro[LINHAS][COLUNAS]);
void posicionarNavio(int tabuleiro[LINHAS][COLUNAS], int linha_inicio, int coluna_inicio, char direcao);

// NOVO: Protótipos para as funções do Nível Mestre
void exibirTabuleiroHabilidades(int tabuleiro[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO]);
void demonstrarHabilidadesCombinadas();


/**
 * @brief Exibe o tabuleiro de Batalha Naval no console.
 * (Função original mantida sem alterações)
 */
void exibirTabuleiro(int tabuleiro[LINHAS][COLUNAS]) {
    int i, j;
    printf("\n--- Tabuleiro de Batalha Naval ---\n");
    
    // Imprime os números das colunas para facilitar a leitura
    printf("    ");
    for (j = 0; j < COLUNAS; j++) {
        printf(" %d", j);
    }
    printf("\n");

    // Imprime o tabuleiro, linha por linha
    for (i = 0; i < LINHAS; i++) {
        printf("%d   ", i); // Imprime o número da linha
        for (j = 0; j < COLUNAS; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief Tenta posicionar um navio no tabuleiro, validando limites e sobreposição.
 * (Função original mantida sem alterações)
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


// --- INÍCIO DAS NOVAS FUNÇÕES (NÍVEL MESTRE) ---

/**
 * @brief Exibe o tabuleiro de habilidades de 15x15.
 * @param tabuleiro A matriz 15x15 a ser exibida.
 */
void exibirTabuleiroHabilidades(int tabuleiro[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO]) {
    for (int i = 0; i < HABILIDADE_TAMANHO; i++) {
        for (int j = 0; j < HABILIDADE_TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief Cria e exibe a matriz única com as 3 habilidades.
 */
void demonstrarHabilidadesCombinadas() {
    // Cria uma matriz 15x15 e inicializa todas as posições com 0.
    int tabuleiro_habilidades[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO] = {0};

    // 1. Desenhar a habilidade em CONE (no topo, ao centro)
    tabuleiro_habilidades[1][7] = 1;
    tabuleiro_habilidades[2][6] = 1; tabuleiro_habilidades[2][7] = 1; tabuleiro_habilidades[2][8] = 1;
    tabuleiro_habilidades[3][5] = 1; tabuleiro_habilidades[3][6] = 1; tabuleiro_habilidades[3][7] = 1; tabuleiro_habilidades[3][8] = 1; tabuleiro_habilidades[3][9] = 1;

    // 2. Desenhar a habilidade em CRUZ (em baixo, à esquerda)
    int cruz_centro_linha = 10;
    int cruz_centro_coluna = 4;
    tabuleiro_habilidades[cruz_centro_linha - 2][cruz_centro_coluna] = 1;
    tabuleiro_habilidades[cruz_centro_linha - 1][cruz_centro_coluna] = 1;
    tabuleiro_habilidades[cruz_centro_linha][cruz_centro_coluna - 2] = 1;
    tabuleiro_habilidades[cruz_centro_linha][cruz_centro_coluna - 1] = 1;
    tabuleiro_habilidades[cruz_centro_linha][cruz_centro_coluna] = 1;
    tabuleiro_habilidades[cruz_centro_linha][cruz_centro_coluna + 1] = 1;
    tabuleiro_habilidades[cruz_centro_linha][cruz_centro_coluna + 2] = 1;
    tabuleiro_habilidades[cruz_centro_linha + 1][cruz_centro_coluna] = 1;
    tabuleiro_habilidades[cruz_centro_linha + 2][cruz_centro_coluna] = 1;

    // 3. Desenhar a habilidade em OCTAEDRO (em baixo, à direita)
    int octa_centro_linha = 10;
    int octa_centro_coluna = 10;
    tabuleiro_habilidades[octa_centro_linha - 2][octa_centro_coluna] = 1;
    tabuleiro_habilidades[octa_centro_linha - 1][octa_centro_coluna - 1] = 1;
    tabuleiro_habilidades[octa_centro_linha - 1][octa_centro_coluna] = 1;
    tabuleiro_habilidades[octa_centro_linha - 1][octa_centro_coluna + 1] = 1;
    tabuleiro_habilidades[octa_centro_linha][octa_centro_coluna - 2] = 1;
    tabuleiro_habilidades[octa_centro_linha][octa_centro_coluna - 1] = 1;
    tabuleiro_habilidades[octa_centro_linha][octa_centro_coluna] = 1;
    tabuleiro_habilidades[octa_centro_linha][octa_centro_coluna + 1] = 1;
    tabuleiro_habilidades[octa_centro_linha][octa_centro_coluna + 2] = 1;
    tabuleiro_habilidades[octa_centro_linha + 1][octa_centro_coluna - 1] = 1;
    tabuleiro_habilidades[octa_centro_linha + 1][octa_centro_coluna] = 1;
    tabuleiro_habilidades[octa_centro_linha + 1][octa_centro_coluna + 1] = 1;
    tabuleiro_habilidades[octa_centro_linha + 2][octa_centro_coluna] = 1;
    
    // Exibe o resultado final do Nível Mestre
    printf("\n\n--- Nivel Mestre: Habilidades Especiais Combinadas ---\n");
    printf("Legenda: 1 = Area Afetada\n\n");
    exibirTabuleiroHabilidades(tabuleiro_habilidades);
}
// --- FIM DAS NOVAS FUNÇÕES ---


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
    
    // 2. Posicionamento dos navios (Nível Novato e Aventureiro)
    printf("--- Niveis Novato & Aventureiro: Posicionando a Frota ---\n");
    posicionarNavio(tabuleiro, 2, 1, 'H');
    posicionarNavio(tabuleiro, 5, 8, 'V');
    posicionarNavio(tabuleiro, 6, 1, '1');
    posicionarNavio(tabuleiro, 6, 7, '2');
    
    // 3. Exibição do tabuleiro completo
    exibirTabuleiro(tabuleiro);

    // 4. MODIFICADO: Exibição das habilidades (Nível Mestre)
    demonstrarHabilidadesCombinadas();

    return 0;
}