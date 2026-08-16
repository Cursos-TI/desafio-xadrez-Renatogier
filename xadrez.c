#include <stdio.h>

// Definicao de constantes globais para a quantidade de movimentos
const int MOVIMENTOS_BISPO = 5;
const int MOVIMENTOS_TORRE = 5;
const int MOVIMENTOS_RAINHA = 8;

int main() {
    printf("=========================================\n");
    printf("       NIVEL NOVATO      \n");
    printf("=========================================\n\n");

    // Movimentacao do Bispo: 5 casas na diagonal superior direita
    printf("--- Movimentacao do Bispo (5 casas Diagonal Superior Direita) ---\n");
    for (int i = 0; i < MOVIMENTOS_BISPO; i++) {
        printf("Cima, Direita\n");
    }

    // Movimentacao da Torre: 5 casas para a direita
    printf("\n--- Movimentacao da Torre (5 casas para a Direita) ---\n");
    int contadorTorre = 0;
    while (contadorTorre < MOVIMENTOS_TORRE) {
        printf("Direita\n");
        contadorTorre++;
    }

    // Movimentacao da Rainha: 8 casas para a esquerda
    printf("\n--- Movimentacao da Rainha (8 casas para a Esquerda) ---\n");
    int contadorRainha = 0;
    do {
        printf("Esquerda\n");
        contadorRainha++;
    } while (contadorRainha < MOVIMENTOS_RAINHA);

    return 0;
}