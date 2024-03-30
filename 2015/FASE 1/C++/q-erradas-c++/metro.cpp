#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Função para a busca em largura (BFS) para encontrar o número de estações pela linha circular
int bfs(vector<vector<int>>& adjList, int N) {
    vector<bool> visited(N, false);
    queue<int> q;
    int circularStations = 0;

    // Iniciando a BFS da estação 0
    visited[0] = true;
    q.push(0);

    while (!q.empty()) {
        int currentStation = q.front();
        q.pop();
        circularStations++;

        // Visitando todas as estações conectadas à atual
        for (int neighbor : adjList[currentStation]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return circularStations;
}

int main() {
    int N, M;
    cin >> N >> M;

    // Lista de adjacência para representar as conexões entre as estações
    vector<vector<int>> adjList(N);

    // Lendo as ligações entre as estações
    for (int i = 0; i < M; i++) {
        int P, Q;
        cin >> P >> Q;
        adjList[P - 1].push_back(Q - 1);
        adjList[Q - 1].push_back(P - 1); // A lista é bidirecional
    }

    // Encontrando o número de estações pelas quais passa a linha circular
    int circularStations = bfs(adjList, N);

    cout << circularStations << endl;

    return 0;
}
