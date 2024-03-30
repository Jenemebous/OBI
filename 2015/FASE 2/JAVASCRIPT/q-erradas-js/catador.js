// Função para ler a entrada usando scanf
function scanf(format, ...args) {
    const input = readline().split(' ');
    let argIndex = 0;
    for (let i = 0; i < format.length; i++) {
        if (format[i] === '%d') {
            args[argIndex++] = parseInt(input[i]);
        }
    }
    return args;
}

// Função para escrever a saída usando printf
function printf(format, ...args) {
    let output = format;
    for (let i = 0; i < args.length; i++) {
        output = output.replace(/%d/, args[i]);
    }
    console.log(output);
}

// Lê a entrada
let [N, M] = scanf("%d%d");

let buckets = [];
let operations = [];

// Lê a quantidade de conchas em cada balde
buckets = scanf("%d".repeat(N));

// Lê a sequência de índices das operações
operations = scanf("%d".repeat(M));

// Função para contar conchas
function countConches(buckets, index) {
    let count = 0;
    const C = buckets[index - 1];
    for (let i = Math.max(1, index - C); i <= Math.min(N, index + C); i++) {
        if (i !== index) {
            count += 1;
            buckets[i - 1] -= 1;
        }
    }
    return count;
}

// Executa as operações e conta as conchas restantes
let totalConches = 0;
for (let i = 0; i < M; i++) {
    totalConches += countConches(buckets, operations[i]);
}

// Escreve o resultado
printf("%d", totalConches);
