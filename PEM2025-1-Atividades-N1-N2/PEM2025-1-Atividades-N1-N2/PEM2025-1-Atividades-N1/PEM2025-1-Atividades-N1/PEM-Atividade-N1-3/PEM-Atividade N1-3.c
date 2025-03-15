/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Refatoração da atividade N1-2    *
* Data - 15/03/2025                                      * 
* Autor: Henrique de Castro Pereira; 2040482422035       *
*--------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

#define C 10 // Código do produto
#define R 3  // Número de ruas
#define G 10 // Número de gôndolas

void GuardarProduto(char armazem[R][G][C], int quantidade[R][G], char *codigo) {
    char rua[R] = {'A', 'B', 'C'};
    
    printf("\nDigite o codigo do produto que deseja armazenar: ");
    scanf("%s", codigo);
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < G; j++) {
            if (strcmp(armazem[i][j], codigo) == 0) {
                quantidade[i][j]++;
                printf("\nProduto %s já existe na rua %c, gôndola %d. Quantidade aumentada para %d\n", codigo, rua[i], j + 1, quantidade[i][j]);
                return;
            }
        }
    }
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < G; j++) {
            if (armazem[i][j][0] == '\0') {
                strcpy(armazem[i][j], codigo);
                quantidade[i][j] = 1;
                printf("\nProduto %s armazenado na rua %c, gôndola %d\n", codigo, rua[i], j + 1);
                return;
            }
        }
    }
    printf("\nNão há mais espaço disponível no estoque.\n");
}

void RetirarProduto(char armazem[R][G][C], int quantidade[R][G], char *codigo) {
    printf("\nDigite o código do produto a ser retirado: ");
    scanf("%s", codigo);
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < G; j++) {
            if (strcmp(armazem[i][j], codigo) == 0) {
                if (quantidade[i][j] > 0) {
                    quantidade[i][j]--;
                    printf("\nProduto %s retirado da rua %c, gôndola %d. Quantidade restante: %d\n", codigo, 'A' + i, j + 1, quantidade[i][j]);
                    if (quantidade[i][j] == 0) {
                        armazem[i][j][0] = '\0';
                    }
                    return;
                }
                printf("\nProduto %s esgotado na rua %c, gôndola %d.\n", codigo, 'A' + i, j + 1);
                return;
            }
        }
    }
    printf("\nO produto %s não foi encontrado no estoque.\n", codigo);
}

void ExibirEstoque(char armazem[R][G][C], int quantidade[R][G]) {
    printf("\nExibindo todo o estoque:\n");
    for (int i = 0; i < R; i++) {
        printf("Rua %c:\n", 'A' + i);
        for (int j = 0; j < G; j++) {
            if (armazem[i][j][0] != '\0') {
                printf("  Gôndola %d -> Produto: %s | Quantidade: %d\n", j + 1, armazem[i][j], quantidade[i][j]);
            } else {
                printf("  Gôndola %d -> Vazia\n", j + 1);
            }
        }
    }
}

void Menu() {
    int quantidade[R][G] = {0};
    char codigo[C];
    char armazem[R][G][C] = {0};
    int decisao;
    
    do {
        printf("\nESTOQUE:\n\n (1) Guardar produto\n (2) Retirar produto\n (3) Exibir todo o estoque\n (4) Sair\n\nDigite uma opção: ");
        scanf("%d", &decisao);
        
        switch (decisao) {
            case 1:
                GuardarProduto(armazem, quantidade, codigo);
                break;
            case 2:
                RetirarProduto(armazem, quantidade, codigo);
                break;
            case 3:
                ExibirEstoque(armazem, quantidade);
                break;
            case 4:
                printf("Desligando...\n");
                break;
            default:
                printf("Digite uma opção válida.\n");
        }
    } while (decisao != 4);
}

int main() {
    Menu();
    return 0;
}
