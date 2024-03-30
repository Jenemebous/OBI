#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int baldes[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &baldes[i]);
    }

    int operacoes[M];
    for (int i = 0; i < M; ++i) {
        scanf("%d", &operacoes[i]);
    }

    int total_conchas = 0;
    for (int i = 0; i < M; ++i) {
        int index = operacoes[i] - 1;
        int c = baldes[index];
        total_conchas += c;
        for (int j = index - 1; j >= 0 && j >= index - c; --j) {
            baldes[j] = (baldes[j] > 0) ? baldes[j] - 1 : 0;
        }
        for (int j = index + 1; j < N && j <= index + c; ++j) {
            baldes[j] = (baldes[j] > 0) ? baldes[j] - 1 : 0;
        }
    }

    printf("%d\n", total_conchas);

    return 0;
}

