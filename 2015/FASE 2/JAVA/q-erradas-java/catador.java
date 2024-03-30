import java.util.Scanner;

public class catador {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Lê o número de baldes e o número de operações
        int N = scanner.nextInt();
        int M = scanner.nextInt();

        // Lê a quantidade de conchas em cada balde
        int[] baldes = new int[N];
        for (int i = 0; i < N; i++) {
            baldes[i] = scanner.nextInt();
        }

        // Lê a sequência de índices das operações
        int[] operacoes = new int[M];
        for (int i = 0; i < M; i++) {
            operacoes[i] = scanner.nextInt();
        }

        // Calcula a quantidade total de conchas ao final das operações
        int totalConchas = calcularTotalConchas(N, M, baldes, operacoes);

        // Escreve o resultado
        System.out.println(totalConchas);
    }

    // Função para calcular a quantidade total de conchas ao final das operações
    public static int calcularTotalConchas(int N, int M, int[] baldes, int[] operacoes) {
        int totalConchas = 0;
        for (int i = 0; i < M; i++) {
            int indice = operacoes[i] - 1; // Índice começa em 1, ajusta para começar em 0
            int quantidade = baldes[indice]; // Quantidade de conchas no balde
            totalConchas += quantidade; // Adiciona a quantidade de conchas ao total

            // Retira uma concha (se houver) de cada balde j, tal que |j-i| ≤ quantidade
            for (int j = Math.max(0, indice - quantidade); j < Math.min(N, indice + quantidade + 1); j++) {
                baldes[j]--; // Retira uma concha do balde j
            }
        }
        return totalConchas;
    }
}
