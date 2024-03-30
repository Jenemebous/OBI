#include <stdio.h>

// Função que retorna o valor associado a um caractere napolitano
int valor(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int main() {
    char S[1000005];
    scanf("%s", S);

    int resultado = 0;
    int i;
    for (i = 0; S[i] != '\0'; ++i) {
        int valor_atual = valor(S[i]);
        int proximo_valor = valor(S[i + 1]);
        if (proximo_valor > valor_atual) {
            resultado -= valor_atual;
        } else {
            resultado += valor_atual;
        }
    }

    printf("%d\n", resultado);

    return 0;
}
