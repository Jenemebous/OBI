#include <iostream>
#include <cmath>
using namespace std;

// Função para calcular o número de divisores de N
int countDivisors(int N) {
    int count = 1; // Começa com 1 porque todo número tem pelo menos 1 divisor, que é ele mesmo

    // Inicia o loop para encontrar os divisores
    for (int i = 2; i * i <= N; i++) {
        int expoente = 0;
        while (N % i == 0) {
            N /= i;
            expoente++;
        }
        count *= (expoente + 1); // Multiplica o número de divisores pelo (expoente + 1)
    }

    // Se N ainda for maior que 1, significa que ele é um primo maior que a raiz quadrada de N
    // Nesse caso, seu expoente é 1 e precisa ser considerado
    if (N > 1) {
        count *= 2;
    }

    return count;
}

int main() {
    int N;
    cin >> N;

    int count = countDivisors(N);

    cout << count << endl;

    return 0;
}
