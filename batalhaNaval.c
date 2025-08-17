#include <stdio.h>

// Definindo as dimensões do tabuleiro e o tamanho dos navios
#define LINHAS 10
#define COLUNAS 10
#define TAMANHO_NAVIO 3

int main() {
    // 1. Representar o tabuleiro com uma matriz 10x10 e inicializar com 0 (água)
    int tabuleiro[LINHAS][COLUNAS];
    int i, j;

    // Loop para inicializar todas as posições do tabuleiro com 0
    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2. Posicionar os navios
    // Coordenadas e direção do primeiro navio (Horizontal)
    int navio1_linha_inicio = 2;
    int navio1_coluna_inicio = 3;
    
    // Coordenadas e direção do segundo navio (Vertical)
    int navio2_linha_inicio = 5;
    int navio2_coluna_inicio = 7;

    // Posicionando o navio horizontal (valor 3)
    // Verificando se o navio cabe no tabuleiro
    if (navio1_coluna_inicio + TAMANHO_NAVIO <= COLUNAS) {
        for (j = 0; j < TAMANHO_NAVIO; j++) {
            tabuleiro[navio1_linha_inicio][navio1_coluna_inicio + j] = 3;
        }
    } else {
        printf("Erro: O navio horizontal nao cabe no tabuleiro!\n");
    }

    // Posicionando o navio vertical (valor 3)
    // Verificando se o navio cabe no tabuleiro e não se sobrepõe
    // O requisito de não-sobreposição é simplificado neste nível, mas a verificação de limites é essencial.
    if (navio2_linha_inicio + TAMANHO_NAVIO <= LINHAS) {
        for (i = 0; i < TAMANHO_NAVIO; i++) {
            // Verificação básica para não sobrepor o primeiro navio
            // Nota: Uma verificação mais robusta seria necessária para um jogo completo.
            if (tabuleiro[navio2_linha_inicio + i][navio2_coluna_inicio] != 3) {
                 tabuleiro[navio2_linha_inicio + i][navio2_coluna_inicio] = 3;
            } else {
                printf("Aviso: Tentativa de sobreposicao de navios ignorada na posicao (%d, %d).\n",
                       navio2_linha_inicio + i, navio2_coluna_inicio);
            }
        }
    } else {
        printf("Erro: O navio vertical nao cabe no tabuleiro!\n");
    }

    // 3. Exibir o tabuleiro no console
    printf("--- Tabuleiro de Batalha Naval ---\n");
    
    // Imprimindo cabeçalho das colunas para facilitar a leitura
    printf("  "); // Espaço para a linha do lado
    for(j = 0; j < COLUNAS; j++) {
        printf(" %d", j);
    }
    printf("\n");

    // Loop para percorrer a matriz e imprimir seus valores
    for (i = 0; i < LINHAS; i++) {
        printf("%d ", i); // Imprimindo o número da linha
        for (j = 0; j < COLUNAS; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    // 4. Exibir as coordenadas dos navios
    printf("\n--- Coordenadas dos Navios ---\n");

    printf("Navio Horizontal (Tamanho %d):\n", TAMANHO_NAVIO);
    for (j = 0; j < TAMANHO_NAVIO; j++) {
        printf("  Parte %d: (%d, %d)\n", j + 1, navio1_linha_inicio, navio1_coluna_inicio + j);
    }

    printf("Navio Vertical (Tamanho %d):\n", TAMANHO_NAVIO);
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        printf("  Parte %d: (%d, %d)\n", i + 1, navio2_linha_inicio + i, navio2_coluna_inicio);
    }

    return 0;
}