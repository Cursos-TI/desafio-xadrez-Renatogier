#include <stdio.h>

// Definicao de constantes globais para a quantidade de movimentos
const int MOVIMENTOS_BISPO = 5;
const int MOVIMENTOS_TORRE = 5;
const int MOVIMENTOS_RAINHA = 8;
const int CAVALO_VERTICAL = 2;
const int CAVALO_HORIZONTAL = 1;

// =============================================================================
// FUNÇÕES RECURSIVAS
// =============================================================================

/**
 * Movimentacao recursiva da Torre: imprime "Direita" a cada chamada ate que o contador chegue a zero.
 * @param casasRestantes Numero de casas que a peca ainda precisa mover.
 */
void moverTorreRecursivo(int casasRestantes) {
    if (casasRestantes <= 0) {
        return; // Caso base: encerra a recursao
    }
    printf("Direita\n");
    moverTorreRecursivo(casasRestantes - 1); // Chamada recursiva decrementando uma casa
}

/**
 * Movimentacao recursiva da Rainha: imprime "Esquerda" a cada chamada.
 * @param casasRestantes Numero de casas que a peca ainda precisa mover.
 */
void moverRainhaRecursivo(int casasRestantes) {
    if (casasRestantes <= 0) {
        return; // Caso base: encerra a recursao
    }
    printf("Esquerda\n");
    moverRainhaRecursivo(casasRestantes - 1); // Chamada recursiva
}

/**
 * Movimentacao recursiva do Bispo: imprime a combinacao "Cima, Direita" em cada nível da recursao.
 * @param casasRestantes Numero de casas que a peca ainda precisa mover na diagonal.
 */
void moverBispoRecursivo(int casasRestantes) {
    if (casasRestantes <= 0) {
        return; // Caso base: encerra a recursao
    }
    printf("Cima, Direita\n");
    moverBispoRecursivo(casasRestantes - 1); // Chamada recursiva
}

// =============================================================================
// FUNÇÃO PRINCIPAL
// =============================================================================

int main() {
    printf("=========================================\n");
    printf("       MOVIMENTAÇÃO XADREZ (AVANÇADO)    \n");
    printf("=========================================\n\n");

    // -------------------------------------------------------------------------
    // 1. TORRE (Recursividade)
    // -------------------------------------------------------------------------
    printf("--- Movimentacao da Torre (Recursiva: %d casas para a Direita) ---\n", MOVIMENTOS_TORRE);
    moverTorreRecursivo(MOVIMENTOS_TORRE);

    // -------------------------------------------------------------------------
    // 2. BISPO (Recursividade e Loops Aninhados)
    // -------------------------------------------------------------------------
    printf("\n--- Movimentacao do Bispo (Recursiva: %d casas Diagonal) ---\n", MOVIMENTOS_BISPO);
    moverBispoRecursivo(MOVIMENTOS_BISPO);

    printf("\n--- Movimentacao do Bispo (Loops Aninhados: %d casas Diagonal) ---\n", MOVIMENTOS_BISPO);
    // Loop externo: controla a movimentacao vertical
    for (int v = 0; v < MOVIMENTOS_BISPO; v++) {
        printf("Cima\n");
        // Loop interno: controla a movimentacao horizontal associada ao passo vertical
        for (int h = 0; h < 1; h++) {
            printf("Direita\n");
        }
    }

    // -------------------------------------------------------------------------
    // 3. RAINHA (Recursividade)
    // -------------------------------------------------------------------------
    printf("\n--- Movimentacao da Rainha (Recursiva: %d casas para a Esquerda) ---\n", MOVIMENTOS_RAINHA);
    moverRainhaRecursivo(MOVIMENTOS_RAINHA);

    // -------------------------------------------------------------------------
    // 4. CAVALO (Loops Complexos com Múltiplas Variáveis, Break e Continue)
    // -------------------------------------------------------------------------
    printf("\n--- Movimentacao do Cavalo (Loops Complexos em L: 2 Cima, 1 Direita) ---\n");
    
    // Loop externo e interno estruturados com controle de fluxo avancado
    for (int passoV = 0, passoH = 0; passoV < CAVALO_VERTICAL || passoH < CAVALO_HORIZONTAL; ) {
        // Etapa 1: executa o deslocamento vertical (2 casas para Cima)
        if (passoV < CAVALO_VERTICAL) {
            printf("Cima\n");
            passoV++;
            continue; // Pula diretamente para a proxima iteracao sem executar o codigo abaixo
        }

        // Etapa 2: executa o deslocamento horizontal (1 casa para a Direita)
        while (passoH < CAVALO_HORIZONTAL) {
            printf("Direita\n");
            passoH++;
            break; // Sai do loop while imediatamente apos imprimir
        }
    }

    return 0;
}