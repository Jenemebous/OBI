import java.util.Scanner;

public class lapis_de_cor {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        scanner.nextLine(); // Consuming newline character

        char[][] grid = new char[N][N];

        // Reading the grid
        for (int i = 0; i < N; i++) {
            String line = scanner.nextLine();
            for (int j = 0; j < N; j++) {
                grid[i][j] = line.charAt(j);
            }
        }

        // Coloring the grid
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] != '0') {
                    grid[i][j] = (char) ('0' + nearestColorDistance(grid, i, j, N));
                }
            }
        }

        // Printing the colored grid
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                System.out.print(grid[i][j]);
            }
            System.out.println();
        }

        scanner.close();
    }

    // Method to find the nearest color distance
    public static int nearestColorDistance(char[][] grid, int row, int col, int N) {
        int minDistance = Integer.MAX_VALUE;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == '0') {
                    int distance = Math.abs(i - row) + Math.abs(j - col);
                    minDistance = Math.min(minDistance, distance);
                }
            }
        }

        return Math.min(minDistance, 9); // Return the minimum between minDistance and 9
    }
}
