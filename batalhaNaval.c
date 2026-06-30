#include <stdio.h>
#include <stdlib.h> // Necessário para a função abs() no Octaedro

int main() {
    // Matriz 10x10 representando o tabuleiro principal
    int tabuleiro[10][10];
    int tamanhoNavio = 3;

    // === 1. INICIALIZAÇÃO DO TABULEIRO (Água = 0) ===
    for (int l = 0; l < 10; l++) {
        for (int c = 0; c < 10; c++) {
            tabuleiro[l][c] = 0;
        }
    }

    // === 2. POSICIONAMENTO DOS NAVIOS DO NÍVEL ANTERIOR (Valor = 3) ===
    int linhaH = 1, colunaH = 2;
    int linhaV = 4, colunaV = 8;
    
    // Navio Horizontal
    for (int i = 0; i < tamanhoNavio; i++) tabuleiro[linhaH][colunaH + i] = 3;
    // Navio Vertical
    for (int i = 0; i < tamanhoNavio; i++) tabuleiro[linhaV + i][colunaV] = 3;


    // === 3. CONFIGURAÇÃO DAS HABILIDADES ESPECIAIS ===
    // Tamanho da área da habilidade (5x5) e seu respectivo centro (2,2)
    int dimaoe = 5;
    int centro = 2; 

    // Pontos de Origem (Alvos) no Tabuleiro 10x10
    int origemConeL = 2, origemConeC = 2;       // Centro do Cone
    int origemCruzL = 7, origemCruzC = 3;       // Centro da Cruz
    int origemOctaL = 5, origemOctaC = 5;       // Centro do Octaedro

    // --- GERANDO E SOBREPOSTANDO O CONE ---
    // Loops aninhados para percorrer a matriz local 5x5 da habilidade
    for (int l = 0; l < dimaoe; l++) {
        for (int c = 0; c < dimaoe; c++) {
            // Condicional dinâmico para formar o Cone apontando para baixo
            if (c >= (centro - l) && c <= (centro + l) && l <= centro) {
                
                // Mapeia a coordenada local 5x5 para a coordenada global 10x10 do tabuleiro
                int tabuleiroL = origemConeL + (l - centro);
                int tabuleiroC = origemConeC + (c - centro);

                // Validação de Limites: Só aplica se estiver dentro do tabuleiro 10x10
                if (tabuleiroL >= 0 && tabuleiroL < 10 && tabuleiroC >= 0 && tabuleiroC < 10) {
                    // Valor 5 representa a área afetada pela habilidade (Requisito Funcional)
                    tabuleiro[tabuleiroL][tabuleiroC] = 5;
                }
            }
        }
    }

    // --- GERANDO E SOBREPOSTANDO A CRUZ ---
    for (int l = 0; l < dimaoe; l++) {
        for (int c = 0; c < dimaoe; c++) {
            // Condicional dinâmico para formar a Cruz (linha central ou coluna central)
            if (l == centro || c == centro) {
                
                int tabuleiroL = origemCruzL + (l - centro);
                int tabuleiroC = origemCruzC + (c - centro);

                if (tabuleiroL >= 0 && tabuleiroL < 10 && tabuleiroC >= 0 && tabuleiroC < 10) {
                    tabuleiro[tabuleiroL][tabuleiroC] = 5;
                }
            }
        }
    }

    // --- GERANDO E SOBREPOSTANDO O OCTAEDRO (LOSANGO) ---
    for (int l = 0; l < dimaoe; l++) {
        for (int c = 0; c < dimaoe; c++) {
            // Condicional utilizando a distância de Manhattan para criar o Losango
            if (abs(l - centro) + abs(c - centro) <= centro) {
                
                int tabuleiroL = origemOctaL + (l - centro);
                int tabuleiroC = origemOctaC + (c - centro);

                if (tabuleiroL >= 0 && tabuleiroL < 10 && tabuleiroC >= 0 && tabuleiroC < 10) {
                    tabuleiro[tabuleiroL][tabuleiroC] = 5;
                }
            }
        }
    }


    // === 4. EXIBIÇÃO DO TABULEIRO FINAL MESTRE ===
    printf("=========================================\n");
    printf("     TABULEIRO MESTRE: HABILIDADES AOE   \n");
    printf("=========================================\n");
    printf("    0 1 2 3 4 5 6 7 8 9\n");
    printf("    -------------------\n");

    for (int l = 0; l < 10; l++) {
        printf("%d | ", l);
        for (int c = 0; c < 10; c++) {
            // Exibição baseada nos valores numéricos determinados
            // 0 = Água, 3 = Navio, 5 = Habilidade Especial
            printf("%d ", tabuleiro[l][c]);
        }
        printf("\n");
    }
    printf("=========================================\n");
    printf("Legenda: 0 = Agua | 3 = Navio | 5 = Efeito AoE\n");
    printf("=========================================\n");

    return 0;