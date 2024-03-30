import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Lendo as cinco cartas da sequência
        int[] cartas = new int[5];
        for (int i = 0; i < 5; i++) {
            cartas[i] = scanner.nextInt();
        }

        // Verificando se a sequência está ordenada
        if (isOrdenadaCrescente(cartas)) {
            System.out.println("C");
        } else if (isOrdenadaDecrescente(cartas)) {
            System.out.println("D");
        } else {
            System.out.println("N");
        }
        
        scanner.close();
    }

    // Função para verificar se a sequência está ordenada crescentemente
    public static boolean isOrdenadaCrescente(int[] cartas) {
        for (int i = 0; i < 4; i++) {
            if (cartas[i] >= cartas[i + 1]) {
                return false;
            }
        }
        return true;
    }

    // Função para verificar se a sequência está ordenada decrescentemente
    public static boolean isOrdenadaDecrescente(int[] cartas) {
        for (int i = 0; i < 4; i++) {
            if (cartas[i] <= cartas[i + 1]) {
                return false;
            }
        }
        return true;
    }
}

