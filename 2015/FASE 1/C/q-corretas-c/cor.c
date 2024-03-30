#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 1001

// Função para calcular a distância entre dois pontos (quadrados)
int distance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    int N;
    scanf("%d", &N);

    char grid[MAX_SIZE][MAX_SIZE];

    // Leitura da folha quadriculada
    for (int i = 0; i < N; i++) {
        scanf("%s", grid[i]);
    }

    // Iteração sobre cada quadrado
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] != '0') { // Se o quadrado não está colorido com o tom 0
                int min_dist = INT_MAX;

                // Verifica a distância para todos os quadrados de tom 0
                for (int x = 0; x < N; x++) {
                    for (int y = 0; y < N; y++) {
                        if (grid[x][y] == '0') {
                            int dist = distance(i, j, x, y);
                            if (dist < min_dist) {
                                min_dist = dist;
                            }
                        }
                    }
                }

                // Colorir o quadrado com o tom correspondente à distância mínima
                if (min_dist >= 9) {
                    grid[i][j] = '9';
                } else {
                    grid[i][j] = min_dist + '0';
                }
            }
        }
    }

    // Imprime a folha quadriculada totalmente colorida
    for (int i = 0; i < N; i++) {
        printf("%s\n", grid[i]);
    }

    return 0;
}
