import java.util.Scanner;

public class carteiro {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        // Lê o número de casas e o número de encomendas
        int N = in.nextInt();
        int M = in.nextInt();

        // Lê os números das casas
        int[] casas = new int[N];
        for (int i = 0; i < N; i++) {
            casas[i] = in.nextInt();
        }

        // Lê os números das casas onde as encomendas devem ser entregues
        int[] encomendas = new int[M];
        for (int i = 0; i < M; i++) {
            encomendas[i] = in.nextInt();
        }

        // Calcula o tempo necessário para entregar todas as encomendas
        int tempo = 0;
        int posicaoAtual = 0; // Começa na primeira casa
        for (int i = 0; i < M; i++) {
            // Encontra a posição da casa onde a encomenda deve ser entregue
            int posicaoEncomenda = encontrarPosicao(casas, encomendas[i]);

            // Calcula o tempo necessário para chegar na casa da encomenda
            tempo += Math.abs(posicaoEncomenda - posicaoAtual);

            // Atualiza a posição atual
            posicaoAtual = posicaoEncomenda;
        }

        // Escreve o resultado
        System.out.println(tempo);
    }

    // Função para encontrar a posição de uma casa no array de casas
    public static int encontrarPosicao(int[] casas, int casa) {
        for (int i = 0; i < casas.length; i++) {
            if (casas[i] == casa) {
                return i;
            }
        }
        return -1; // Caso não encontre a casa (não deveria ocorrer)
    }
}

