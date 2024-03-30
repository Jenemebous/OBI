function contarDivisores(numero) {
    let count = 1;
    for (let i = 2; i * i <= numero; i++) {
        let expoente = 0;
        while (numero % i === 0) {
            expoente++;
            numero /= i;
        }
        count *= (expoente + 1);
    }
    if (numero > 1) {
        count *= 2;
    }
    return count;
}

// Função para leitura de entrada
function main(input) {
    const N = parseInt(input.trim());
    const resultado = contarDivisores(N);
    console.log(resultado);
}

// Exemplo de uso
const entrada = "660";
main(entrada);
