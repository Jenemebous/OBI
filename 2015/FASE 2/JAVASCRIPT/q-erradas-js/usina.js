function menorTempoParaPrevenirAcidente(N, M, C, K, salasComPessoas, escorregadores) {
    const adjacencias = Array.from({ length: N + 1 }, () => []);
    for (let [A, B, D] of escorregadores) {
        adjacencias[A].push([B, D]);
    }

    const visitado = new Set();
    const fila = [];
    fila.push([1, 0]); // [sala, tempo]

    while (fila.length > 0) {
        const [sala, tempo] = fila.shift();
        if (sala === N) return tempo; // Técnico alcançado

        for (let [vizinho, distancia] of adjacencias[sala]) {
            if (!visitado.has(vizinho) && tempo + distancia <= K) {
                visitado.add(vizinho);
                fila.push([vizinho, tempo + distancia]);
            }
        }

        // Verificar se o som se propaga para outras salas
        for (let salaComPessoa of salasComPessoas) {
            if (!visitado.has(salaComPessoa)) {
                visitado.add(salaComPessoa);
                fila.push([salaComPessoa, tempo + 1]); // Grito leva 1 segundo para propagar
            }
        }
    }

    return -1; // Não é possível prevenir o acidente
}

// Lê a entrada
const entrada = readline().split(' ').map(Number);
const N = entrada[0];
const M = entrada[1];
const C = entrada[2];
const K = entrada[3];

const salasComPessoas = readline().split(' ').map(Number);
const escorregadores = [];
for (let i = 0; i < M; i++) {
    escorregadores.push(readline().split(' ').map(Number));
}

// Calcula o menor tempo necessário para prevenir o acidente
const tempo = menorTempoParaPrevenirAcidente(N, M, C, K, salasComPessoas, escorregadores);

// Escreve o resultado
console.log(tempo);
