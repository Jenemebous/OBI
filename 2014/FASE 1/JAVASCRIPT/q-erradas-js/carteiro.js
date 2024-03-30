function calcularTempoEntrega(N, M, casas, encomendas) {
    let tempoTotal = 0;
    let posicaoAtual = 1; // Começa na casa de menor número

    for (let i = 0; i < M; i++) {
        const casaDestino = encomendas[i];
        const indiceCasaDestino = casas.indexOf(casaDestino) + 1; // Índice da casa destino

        // Calcular distância entre a casa atual e a casa de destino
        const distancia = Math.abs(indiceCasaDestino - posicaoAtual);

        // Adicionar a distância ao tempo total
        tempoTotal += distancia;

        // Atualizar a posição atual para a casa destino
        posicaoAtual = indiceCasaDestino;
    }

    return tempoTotal;
}

// Leitura da entrada
const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let N, M;
let casas = [];
let encomendas = [];

rl.question('', (entradaN) => {
    [N, M] = entradaN.split(' ').map(Number);

    rl.question('', (entradaCasas) => {
        casas = entradaCasas.split(' ').map(Number);

        rl.question('', (entradaEncomendas) => {
            encomendas = entradaEncomendas.split(' ').map(Number);

            // Calcular e imprimir o tempo total necessário para entregar todas as encomendas
            const tempoTotal = calcularTempoEntrega(N, M, casas, encomendas);
            console.log(tempoTotal);

            rl.close();
        });
    });
});
