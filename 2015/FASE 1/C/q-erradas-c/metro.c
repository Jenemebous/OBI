#include <stdio.h>
#include <stdbool.h>

#define MAX_STATIONS 20001
#define MAX_CONNECTIONS 20101

bool visited[MAX_STATIONS];
int adjacency[MAX_STATIONS][MAX_STATIONS];

void bfs(int start) {
    int queue[MAX_STATIONS];
    int front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];

        for (int i = 1; i < MAX_STATIONS; i++) {
            if (adjacency[current][i] && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    // Inicialização
    for (int i = 0; i < MAX_STATIONS; i++) {
        visited[i] = false;
        for (int j = 0; j < MAX_STATIONS; j++) {
            adjacency[i][j] = 0;
        }
    }

    // Leitura das ligações entre as estações
    for (int i = 0; i < M; i++) {
        int P, Q;
        scanf("%d %d", &P, &Q);
        adjacency[P][Q] = 1;
        adjacency[Q][P] = 1;
    }

    // Realiza a busca em largura a partir da estação 1 (central)
    bfs(1);

    // Conta quantas estações foram visitadas (alcançáveis)
    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (visited[i]) {
            count++;
        }
    }

    // Escreve o resultado
    printf("%d\n", count);

    return 0;
}
