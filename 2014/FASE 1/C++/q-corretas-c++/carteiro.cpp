#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> houses(N);
    vector<int> orders(M);

    // Leitura das casas
    for (int i = 0; i < N; ++i) {
        cin >> houses[i];
    }

    // Leitura das encomendas
    for (int i = 0; i < M; ++i) {
        cin >> orders[i];
    }

    int time = 0;
    int current_house = 0;

    // Para cada encomenda
    for (int i = 0; i < M; ++i) {
        // Encontra a posição da casa onde a encomenda deve ser entregue
        int target_house = find(houses.begin(), houses.end(), orders[i]) - houses.begin();

        // Calcula o tempo necessário para ir até essa casa
        time += abs(target_house - current_house);

        // Atualiza a posição atual
        current_house = target_house;
    }

    cout << time << endl;

    return 0;
}

