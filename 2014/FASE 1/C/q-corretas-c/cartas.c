#include <stdio.h>

int main() {
    int cards[5];
    
    // Leitura das cartas
    for (int i = 0; i < 5; i++) {
        scanf("%d", &cards[i]);
    }
    
    // Verificação da ordenação
    int crescente = 1, decrescente = 1;
    for (int i = 1; i < 5; i++) {
        if (cards[i] > cards[i - 1]) {
            decrescente = 0;
        } else if (cards[i] < cards[i - 1]) {
            crescente = 0;
        }
    }
    
    // Saída de acordo com a ordenação
    if (crescente) {
        printf("C\n");
    } else if (decrescente) {
        printf("D\n");
    } else {
        printf("N\n");
    }
    
    return 0;
}
