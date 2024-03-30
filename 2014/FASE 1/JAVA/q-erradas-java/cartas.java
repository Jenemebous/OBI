import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Lendo as cinco cartas da sequ�ncia
        int[] cartas = new int[5];
        for (int i = 0; i < 5; i++) {
            cartas[i] = scanner.nextInt();
        }

        // Verificando se a sequ�ncia est� ordenada
        if (isOrdenadaCrescente(cartas)) {
            System.out.println("C");
        } else if (isOrdenadaDecrescente(cartas)) {
            System.out.println("D");
        } else {
            System.out.println("N");
        }
        
        scanner.close();
    }

    // Fun��o para verificar se a sequ�ncia est� ordenada crescentemente
    public static boolean isOrdenadaCrescente(int[] cartas) {
        for (int i = 0; i < 4; i++) {
            if (cartas[i] >= cartas[i + 1]) {
                return false;
            }
        }
        return true;
    }

    // Fun��o para verificar se a sequ�ncia est� ordenada decrescentemente
    public static boolean isOrdenadaDecrescente(int[] cartas) {
        for (int i = 0; i < 4; i++) {
            if (cartas[i] <= cartas[i + 1]) {
                return false;
            }
        }
        return true;
    }
}

