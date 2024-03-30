#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Função para determinar a distância do quadrado Q para o quadrado mais próximo de tom 0
int findDistance(vector<vector<char>>& grid, int row, int col, int N) {
    // Matriz de movimentos ortogonais: cima, baixo, esquerda, direita
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    queue<pair<int, int>> q;
    vector<vector<bool>> visited(N, vector<bool>(N, false));

    q.push({row, col});
    visited[row][col] = true;
    int distance = 0;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            if (grid[r][c] == '0')
                return distance;

            // Verifica os movimentos ortogonais
            for (auto& dir : directions) {
                int nr = r + dir.first;
                int nc = c + dir.second;
                if (nr >= 0 && nr < N && nc >= 0 && nc < N && !visited[nr][nc]) {
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }
        distance++;
    }

    return 9; // Se não encontrar nenhum quadrado colorido com o tom 0, retorna 9
}

int main() {
    int N;
    cin >> N;

    // Leitura da matriz
    vector<vector<char>> grid(N, vector<char>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }

    // Coloração da matriz
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (grid[i][j] == '*') {
                int distance = findDistance(grid, i, j, N);
                grid[i][j] = distance + '0';
            }
        }
    }

    // Impressão da matriz colorida
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}
