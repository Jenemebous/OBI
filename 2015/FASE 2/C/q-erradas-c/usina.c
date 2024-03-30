#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int A, B, D;
} Escorregador;

int main(void) {
    int N, M, C, K;
    scanf("%d %d %d %d", &N, &M, &C, &K);

    int salas_pessoas[C];
    for (int i = 0; i < C; i++) {
        if (scanf("%d", &salas_pessoas[i]) != 1) {
            fprintf(stderr, "Erro ao ler as salas com pessoas\n");
            return EXIT_FAILURE;
        }
    }

    Escorregador escorregadores[M];
    for (int i = 0; i < M; i++) {
        if (scanf("%d %d %d", &escorregadores[i].A, &escorregadores[i].B, &escorregadores[i].D) != 3) {
            fprintf(stderr, "Erro ao ler os escorregadores\n");
            return EXIT_FAILURE;
        }
    }

    // Implemente o restante do seu código aqui

    return 0;
}
