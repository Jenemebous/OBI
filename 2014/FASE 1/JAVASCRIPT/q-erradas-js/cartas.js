function verificarOrdenacao(cartas) {
    let crescente = true;
    let decrescente = true;

    // Verificar se a sequência está ordenada crescentemente
    for (let i = 1; i < cartas.length; i++) {
        if (cartas[i] <= cartas[i - 1]) {
            crescente = false;
            break;
        }
    }

    // Verificar se a sequência está ordenada decrescentemente
    for (let i = 1; i < cartas.length; i++) {
        if (cartas[i] >= cartas[i - 1]) {
            decrescente = false;
            break;
        }
    }

    // Determinar o resultado
    if (crescente) {
        return 'C'; // Sequência ordenada crescentemente
    } else if (decrescente) {
        return 'D'; // Sequência ordenada decrescentemente
    } else {
        return 'N'; // Sequência não ordenada
    }
}

// Leitura da entrada
const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('', (entrada) => {
    const cartas = entrada.split(' ').map(Number);

    // Verificar a ordenação e imprimir o resultado
    const resultado = verificarOrdenacao(cartas);
    console.log(resultado);

    rl.close();
});
