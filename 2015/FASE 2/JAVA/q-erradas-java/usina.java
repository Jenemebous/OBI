import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Queue;
import java.util.Scanner;

public class usina {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Lê a entrada
        int N = scanner.nextInt(); // Número de salas
        int M = scanner.nextInt(); // Número de escorregadores
        int C = scanner.nextInt(); // Número de salas com pessoas
        int K = scanner.nextInt(); // Distância máxima de audição nos escorregadores

        HashSet<Integer> salasComPessoas = new HashSet<>();
        for (int i = 0; i < C; i++) {
            salasComPessoas.add(scanner.nextInt());
        }

        ArrayList<int[]>[] escorregadores = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++) {
            escorregadores[i] = new ArrayList<>();
        }

        for (int i = 0; i < M; i++) {
            int A = scanner.nextInt();
            int B = scanner.nextInt();
            int D = scanner.nextInt();
            escorregadores[A].add(new int[]{B, D});
        }

        // Calcula o menor tempo necessário para prevenir o acidente
        int tempo = menorTempoPrevenirAcidente(N, M, C, K, salasComPessoas, escorregadores);

        // Escreve o resultado
        System.out.println(tempo);
    }

    // Função para calcular o menor tempo necessário para prevenir o acidente
    public static int menorTempoPrevenirAcidente(int N, int M, int C, int K, HashSet<Integer> salasComPessoas, ArrayList<int[]>[] escorregadores) {
        Queue<int[]> fila = new ArrayDeque<>();
        fila.add(new int[]{1, 0}); // [sala, tempo]

        HashSet<Integer> visitado = new HashSet<>();
        visitado.add(1);

        while (!fila.isEmpty()) {
            int[] info = fila.poll();
            int sala = info[0];
            int tempo = info[1];

            // Verifica se alguma pessoa está na sala atual
            if (salasComPessoas.contains(sala)) {
                return tempo;
            }

            // Verifica se é possível ouvir alguém gritando nesta sala
            if (tempo <= K) {
                for (int vizinho : salasComPessoas) {
                    if (!visitado.contains(vizinho)) {
                        fila.add(new int[]{vizinho, tempo + 1});
                        visitado.add(vizinho);
                    }
                }
            }

            // Tenta descer pelos escorregadores
            for (int[] escorregador : escorregadores[sala]) {
                int proximaSala = escorregador[0];
                int distancia = escorregador[1];
                if (!visitado.contains(proximaSala) && tempo + distancia <= K) {
                    fila.add(new int[]{proximaSala, tempo + distancia});
                    visitado.add(proximaSala);
                }
            }
        }

        return -1; // Não é possível prevenir o acidente
    }
}
