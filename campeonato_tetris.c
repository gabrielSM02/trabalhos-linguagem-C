#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char nome[16];
    int pontuacoes[12];
    int pontuacao_final;
    int classificacao;
} Jogador;

int compararJogadores(const void *a, const void *b) {
    const Jogador *jogadorA = (const Jogador *)a;
    const Jogador *jogadorB = (const Jogador *)b;

    if (jogadorB->pontuacao_final != jogadorA->pontuacao_final) {
        return jogadorB->pontuacao_final - jogadorA->pontuacao_final;
    } else {
        return strcmp(jogadorA->nome, jogadorB->nome);
    }
}

int main() {
    int teste = 1;
    int J;

    printf("Digite o número de jogadores (J): ");
    scanf("%d", &J);

    while (J != 0) {
        Jogador jogadores[J];

        for (int i = 0; i < J; i++) {
            printf("Nome do jogador #%d (até 15 letras): ", i + 1);
            scanf("%s", jogadores[i].nome);

            printf("Pontuações (12 números separados por espaço): ");
            for (int j = 0; j < 12; j++) {
                scanf("%d", &jogadores[i].pontuacoes[j]);
            }
        }

        for (int i = 0; i < J; i++) {
            qsort(jogadores[i].pontuacoes, 12, sizeof(int), compararJogadores);

            jogadores[i].pontuacao_final = 0;
            for (int j = 1; j < 11; j++) {
                jogadores[i].pontuacao_final += jogadores[i].pontuacoes[j];
            }
        }

        qsort(jogadores, J, sizeof(Jogador), compararJogadores);

        printf("Teste %d\n", teste++);
        int classificacao = 1;

        for (int i = 0; i < J; i++) {
            if (i > 0 && jogadores[i].pontuacao_final != jogadores[i - 1].pontuacao_final) {
                classificacao = i + 1;
            }
            printf("%d %d %s\n", classificacao, jogadores[i].pontuacao_final, jogadores[i].nome);
        }

        printf("\n");

        printf("Digite o número de jogadores (J): ");
        scanf("%d", &J);
    }

    return 0;
}
