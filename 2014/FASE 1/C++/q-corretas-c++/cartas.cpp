#include <iostream>
using namespace std;

int main() {
    int cards[5];
    
    // Leitura das cartas
    for (int i = 0; i < 5; ++i) {
        cin >> cards[i];
    }
    
    // Verificação da ordenação
    bool crescente = true, decrescente = true;
    for (int i = 1; i < 5; ++i) {
        if (cards[i] > cards[i - 1]) {
            decrescente = false;
        } else if (cards[i] < cards[i - 1]) {
            crescente = false;
        }
    }
    
    // Saída do resultado
    if (crescente) {
        cout << "C" << endl;
    } else if (decrescente) {
        cout << "D" << endl;
    } else {
        cout << "N" << endl;
    }
    
    return 0;
}
