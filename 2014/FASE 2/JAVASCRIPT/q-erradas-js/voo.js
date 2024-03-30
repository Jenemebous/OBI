function calcularDuracaoEFusoHorario(idaPartida, voltaChegada) {
    // Extrair as horas e minutos dos horários de ida e volta
    const [idaHora, idaMinuto] = idaPartida.split(':').map(Number);
    const [voltaHora, voltaMinuto] = voltaChegada.split(':').map(Number);

    // Calcular a duração do voo em minutos
    const duracaoVoo = (voltaHora * 60 + voltaMinuto) - (idaHora * 60 + idaMinuto);

    // Determinar a diferença de fusos horários
    let diferencaFusos = voltaHora - idaHora;

    // Ajustar a diferença de fusos horários se ultrapassar os limites (-12 < delta ≤ 12)
    if (diferencaFusos > 12) {
        diferencaFusos -= 24;
    } else if (diferencaFusos <= -12) {
        diferencaFusos += 24;
    }

    return [duracaoVoo, diferencaFusos];
}

// Função para converter a diferença de fusos horários para formato de texto
function formatarDiferencaFusos(diferencaFusos) {
    if (diferencaFusos > 0) {
        return `${diferencaFusos}`;
    } else if (diferencaFusos < 0) {
        return `-${Math.abs(diferencaFusos)}`;
    } else {
        return '0';
    }
}

// Leitura da entrada
const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('', (entrada) => {
    const [idaPartida, voltaChegada, voltaPartida, idaChegada] = entrada.split(' ');

    // Calcular a duração do voo e a diferença de fusos horários
    const [duracaoVoo, diferencaFusos] = calcularDuracaoEFusoHorario(idaPartida, voltaChegada);

    // Imprimir a duração do voo em minutos e a diferença entre os fusos horários
    console.log(`${duracaoVoo} ${formatarDiferencaFusos(diferencaFusos)}`);

    rl.close();
});
