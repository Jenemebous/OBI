import java.util.Scanner;

public class voo {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        // Lê os horários de partida e chegada do voo de ida e volta
        String[] horarios = in.nextLine().split(" ");
        String partidaIda = horarios[0];
        String chegadaVolta = horarios[1];
        String partidaVolta = horarios[2];
        String chegadaIda = horarios[3];

        // Calcula a duração do voo de ida e volta
        int duracaoIda = calcularDuracao(partidaIda, chegadaIda);
        int duracaoVolta = calcularDuracao(partidaVolta, chegadaVolta);

        // Calcula a diferença entre os fusos horários
        int diferencaFusos = calcularDiferencaFusos(partidaIda, partidaVolta);

        // Escreve o resultado
        System.out.println(duracaoIda + " " + diferencaFusos);
    }

    // Função para calcular a duração do voo em minutos
    public static int calcularDuracao(String partida, String chegada) {
        String[] horaPartida = partida.split(":");
        String[] horaChegada = chegada.split(":");
        int horaPartidaInt = Integer.parseInt(horaPartida[0]);
        int minutoPartida = Integer.parseInt(horaPartida[1]);
        int horaChegadaInt = Integer.parseInt(horaChegada[0]);
        int minutoChegada = Integer.parseInt(horaChegada[1]);

        int duracao = (horaChegadaInt * 60 + minutoChegada) - (horaPartidaInt * 60 + minutoPartida);
        if (duracao < 0) // Se a chegada for no dia seguinte
            duracao += 24 * 60;
        return duracao;
    }

    // Função para calcular a diferença entre os fusos horários
    public static int calcularDiferencaFusos(String partidaIda, String partidaVolta) {
        String[] horaPartidaIda = partidaIda.split(":");
        String[] horaPartidaVolta = partidaVolta.split(":");
        int horaPartidaIdaInt = Integer.parseInt(horaPartidaIda[0]);
        int horaPartidaVoltaInt = Integer.parseInt(horaPartidaVolta[0]);

        int diferenca = horaPartidaVoltaInt - horaPartidaIdaInt;
        if (diferenca < -12)
            diferenca += 24; // Tratamento para casos em que a diferença é negativa
        return diferenca;
    }
}

