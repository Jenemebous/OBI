#include <stdio.h>

int main() {
    int N;
    int count = 1; // Inicialmente 1, pois todo número tem pelo menos 1 divisor (ele mesmo)

    // Lê o número N
    scanf("%d", &N);

    // Calcula o número de divisores
    for (int i = 2; i * i <= N; i++) {
        int exponent = 0;
        while (N % i == 0) {
            N /= i;
            exponent++;
        }
        count *= (exponent + 1);
    }
    if (N > 1) {
        count *= 2; // Se sobrar um primo maior que 1, seu expoente será 1
    }

    // Escreve o resultado
    printf("%d\n", count);

    return 0;
}
