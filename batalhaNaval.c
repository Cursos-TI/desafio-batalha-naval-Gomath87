#include <stdio.h>

int main() {
    // Matriz 10x10 representando o tabuleiro (Requisito Funcional)
    int tabuleiro[10][10];
    
    // Tamanho fixo de todos os navios
    int tamanhoNavio = 3;

    // === COORDENADAS INICIAIS DOS NAVIOS (Definidas no código) ===
    
    // 1. Navio Horizontal (Linha fixa 1, Colunas 2, 3, 4)
    int linhaH = 1, colunaH = 2;

    // 2. Navio Vertical (Coluna fixa 8, Linhas 4, 5, 6)
    int linhaV = 4, colunaV = 8;

    // 3. Navio Diagonal Principal (\) - Começa na Linha 2, Coluna 5
    // Ocupará: [2][5], [3][6], [4][7]
    int linhaD1 = 2, colunaD1 = 5;

    // 4. Navio Diagonal Secundária (/) - Começa na Linha 7, Coluna 3
    // Ocupará: [7][3], [8][2], [9][1]
    int linhaD2 = 7, colunaD2 = 3;

    // === 1. INICIALIZAÇÃO DO TABULEIRO (Água = 0) ===
    for (int l = 0; l < 10; l++) {
        for (int c = 0; c < 10; c++) {
            tabuleiro[l][c] = 0;
        }
    }

    // === 2. VALIDAÇÃO DE LIMITES (Requisito Funcional) ===
    // Valida Navio Horizontal
    if (linhaH >= 10 || colunaH + tamanhoNavio > 10) {
        printf("Erro: Navio Horizontal fora dos limites!\n");
        return 0;
    }
    // Valida Navio Vertical
    if (linhaV + tamanhoNavio > 10 || colunaV >= 10) {
        printf("Erro: Navio Vertical fora dos limites!\n");
        return 0;
    }
    // Valida Diagonal Principal (Linha e Coluna crescem)
    if (linhaD1 + tamanhoNavio > 10 || colunaD1 + tamanhoNavio > 10) {
        printf("Erro: Navio Diagonal 1 fora dos limites!\n");
        return 0;
    }
    // Valida Diagonal Secundária (Linha cresce, Coluna diminui)
    if (linhaD2 + tamanhoNavio > 10 || colunaD2 - (tamanhoNavio - 1) < 0) {
        printf("Erro: Navio Diagonal 2 fora dos limites!\n");
        return 0;
    }

    // === 3. POSICIONAMENTO DOS NAVIOS (Valor = 3) ===
    
    // Posicionando Navio Horizontal
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaH][colunaH + i] = 3;
    }

    // Posicionando Navio Vertical
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaV + i][colunaV] = 3;
    }

    // Posicionando Navio Diagonal Principal (\)
    // Linha aumenta, Coluna aumenta
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaD1 + i][colunaD1 + i] = 3;
    }

    // Posicionando Navio Diagonal Secundária (/)
    // Linha aumenta, Coluna diminui
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaD2 + i][colunaD2 - i] = 3;
    }

    // === 4. EXIBIÇÃO DO TABULEIRO ===
    printf("=========================================\n");
    printf("     TABULEIRO AVANÇADO (DIAGONAIS)     \n");
    printf("=========================================\n");
    
    // Cabeçalho indicador de colunas
    printf("    0 1 2 3 4 5 6 7 8 9\n");
    printf("    -------------------\n");

    for (int l = 0; l < 10; l++) {
        // Indicador de linhas
        printf("%d | ", l);
        
        for (int c = 0; c < 10; c++) {
            printf("%d ", tabuleiro[l][c]);
        }
        printf("\n");
    }
    printf("=========================================\n");

    return 0;
}