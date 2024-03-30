import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class metro {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt(); // Número total de estações
        int M = scanner.nextInt(); // Número de ligações entre pares de estações

        // Lista de adjacência para representar as conexões entre as estações
        ArrayList<ArrayList<Integer>> adjList = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            adjList.add(new ArrayList<>());
        }

        // Lendo as ligações entre as estações
        for (int i = 0; i < M; i++) {
            int P = scanner.nextInt();
            int Q = scanner.nextInt();
            adjList.get(P - 1).add(Q - 1);
            adjList.get(Q - 1).add(P - 1); // A lista é bidirecional
        }

        // Encontrando o número de estações pelas quais passa a linha circular
        int circularStations = bfs(adjList, N);

        System.out.println(circularStations);

        scanner.close();
    }

    // Busca em largura (BFS) para encontrar o número de estações pela linha circular
    public static int bfs(ArrayList<ArrayList<Integer>> adjList, int N) {
        boolean[] visited = new boolean[N];
        Queue<Integer> queue = new LinkedList<>();
        int circularStations = 0;

        // Iniciando a BFS da estação 0
        visited[0] = true;
        queue.add(0);

        while (!queue.isEmpty()) {
            int currentStation = queue.poll();
            circularStations++;

            // Visitando todas as estações conectadas à atual
            for (int neighbor : adjList.get(currentStation)) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.add(neighbor);
                }
            }
        }

        return circularStations;
    }
}
