#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> baldes(N);
    for (int i = 0; i < N; ++i) {
        cin >> baldes[i];
    }

    vector<int> operacoes(M);
    for (int i = 0; i < M; ++i) {
        cin >> operacoes[i];
    }

    int totalConchas = 0;
    for (int i = 0; i < M; ++i) {
        int indice = operacoes[i] - 1;
        int C = baldes[indice];
        totalConchas += C;
        int inicio = max(0, indice - C);
        int fim = min(N - 1, indice + C);
        for (int j = inicio; j <= fim; ++j) {
            baldes[j] = max(0, baldes[j] - 1);
        }
    }

    cout << totalConchas << endl;

    return 0;
}
