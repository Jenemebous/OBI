#include <stdio.h>

int main() {
    int N, M;
    
    // Leitura do número de casas e número de encomendas
    scanf("%d %d", &N, &M);
    
    // Declaração e leitura dos números das casas
    int casas[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &casas[i]);
    }
    
    // Declaração e leitura dos números das casas das encomendas
    int encomendas[M];
    for (int i = 0; i < M; i++) {
        scanf("%d", &encomendas[i]);
    }
    
    // Variável para armazenar o tempo total
    int tempo = 0;
    
    // Índice da próxima casa a ser entregue
    int proxima_casa = 0;
    
    // Percorre as encomendas e calcula o tempo total
    for (int i = 0; i < M; i++) {
        // Procura a casa correspondente à encomenda
        while (casas[proxima_casa] != encomendas[i]) {
            proxima_casa++;
        }
        
        // Calcula o tempo para entregar a encomenda na casa correspondente
        tempo += proxima_casa;
    }
    
    // Saída do tempo total
    printf("%d\n", tempo);
    
    return 0;
}
