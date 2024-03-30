import java.util.HashMap;
import java.util.Scanner;

public class numeronapolitano {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Lê a cadeia de caracteres
        String S = scanner.nextLine();

        // Calcula o valor do número napolitano
        int valor = calcularValorNapolitano(S);

        // Escreve o resultado
        System.out.println(valor);
    }

    // Função para calcular o valor do número napolitano
    public static int calcularValorNapolitano(String S) {
        HashMap<Character, Integer> valores = new HashMap<>();
        valores.put('I', 1);
        valores.put('V', 5);
        valores.put('X', 10);
        valores.put('L', 50);
        valores.put('C', 100);
        valores.put('D', 500);
        valores.put('M', 1000);

        int valor = 0;
        int i = 0;

        while (i < S.length()) {
            int atual = valores.get(S.charAt(i));
            int proximo = i < S.length() - 1 ? valores.get(S.charAt(i + 1)) : 0;

            if (atual < proximo) {
                valor += proximo - atual;
                i += 2;
            } else {
                valor += atual;
                i++;
            }
        }

        return valor;
    }
}
