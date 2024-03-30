// Função para calcular o valor do número napolitano
function calcularValorNapolitano(S) {
    const valores = { 'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000 };
    let total = 0;
    let valorAnterior = 0;

    for (let i = 0; i < S.length; i++) {
        const valorAtual = valores[S[i]];
        total += valorAtual;

        if (valorAnterior < valorAtual) {
            total -= 2 * valorAnterior;
        }

        valorAnterior = valorAtual;
    }

    return total;
}

// Lê a entrada
const S = readline();

// Calcula o valor do número napolitano
const valor = calcularValorNapolitano(S);

// Escreve o resultado
console.log(valor);
