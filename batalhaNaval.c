#include <stdio.h>

// Tamanho do tabuleiro
#define TAM 10

int main() {
    int tabuleiro[TAM][TAM]; // Matriz do tabuleiro
    int navio1[3] = {3, 3, 3}; // Navio horizontal (3 posições)
    int navio2[3] = {3, 3, 3}; // Navio vertical (3 posições)

    // Inicializa o tabuleiro com 0 (representando água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Coordenadas de início dos navios
    int linha_navio1 = 2, coluna_navio1 = 3; // Para o navio horizontal
    int linha_navio2 = 5, coluna_navio2 = 6; // Para o navio vertical

    // Validação dos limites do navio horizontal
    if (coluna_navio1 + 2 < TAM) {
        // Verifica sobreposição antes de posicionar o navio horizontal
        int sobrepoe = 0;
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha_navio1][coluna_navio1 + i] != 0) {
                sobrepoe = 1;
                break;
            }
        }
        if (!sobrepoe) {
            for (int i = 0; i < 3; i++) {
                tabuleiro[linha_navio1][coluna_navio1 + i] = navio1[i];
            }
        }
    }

    // Validação dos limites do navio vertical
    if (linha_navio2 + 2 < TAM) {
        // Verifica sobreposição antes de posicionar o navio vertical
        int sobrepoe = 0;
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha_navio2 + i][coluna_navio2] != 0) {
                sobrepoe = 1;
                break;
            }
        }
        if (!sobrepoe) {
            for (int i = 0; i < 3; i++) {
                tabuleiro[linha_navio2 + i][coluna_navio2] = navio2[i];
            }
        }
    }

    // Impressão do tabuleiro
    printf("Tabuleiro Batalha Naval (0 = Água, 3 = Parte do Navio):\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
