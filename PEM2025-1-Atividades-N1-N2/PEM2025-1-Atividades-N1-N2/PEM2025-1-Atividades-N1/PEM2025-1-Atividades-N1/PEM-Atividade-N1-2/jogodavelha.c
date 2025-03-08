/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Jogo da Velha                    *
* Data - 05/03/2025                                      * 
* Autor: Henrique de Castro Pereira; 2040482422035       *
*--------------------------------------------------------*/

#include <stdio.h>
#include <stdbool.h>

#define TAMANHO 3

void ExibirTabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    printf("\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < TAMANHO - 1) printf("|");
        }
        printf("\n");
        if (i < TAMANHO - 1) printf("-----------\n");
    }
    printf("\n");
}

bool VerificarVencedor(char tabuleiro[TAMANHO][TAMANHO], char jogador) {
    if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador)
        return true;
    if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador)
        return true;
    for (int i = 0; i < TAMANHO; i++) {
        if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador)
            return true;
        if (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador)
            return true;
    }

    return false;
}

bool TemEspacoVazio(char tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == ' ')
                return true;
        }
    }
    return false;
}

int main() {
    char tabuleiro[TAMANHO][TAMANHO] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ' , ' '}
    };
    char jogador_atual = 'X';
    bool vencedor = false;
    int linha, coluna;

    while (TemEspacoVazio(tabuleiro) && !vencedor) {
        ExibirTabuleiro(tabuleiro);
        printf("E a vez do jogador %c\n", jogador_atual);
        printf("Escolha a linha (1 a 3): ");
        scanf("%d", &linha);
        printf("Escolha a coluna (1 a 3): ");
        scanf("%d", &coluna);

        if (linha >= 1 && linha <= 3 && coluna >= 1 && coluna <= 3 && tabuleiro[linha - 1][coluna - 1] == ' ') {
            tabuleiro[linha - 1][coluna - 1] = jogador_atual;

            if (VerificarVencedor(tabuleiro, jogador_atual)) {
                ExibirTabuleiro(tabuleiro);
                printf("O jogador %c venceu\n", jogador_atual);
                vencedor = true;
            } else {
                jogador_atual = (jogador_atual == 'X') ? 'O' : 'X';
            }
        } else {
            printf("Essa posição ja esta ocupada ou e invalida. Tente novamente.\n");
        }
    }

    if (!vencedor) {
        ExibirTabuleiro(tabuleiro);
        printf("O jogo terminou em empate.\n");
    }

    return 0;
}
