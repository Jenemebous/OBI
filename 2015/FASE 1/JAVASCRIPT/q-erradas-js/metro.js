function contarEstacoesMetro(N, liga��es) {
    // Construir um grafo direcionado a partir das liga��es
    const grafo = {};
    for (let i = 1; i <= N; i++) {
        grafo[i] = [];
    }
    for (const [origem, destino] of liga��es) {
        grafo[origem].push(destino);
    }

    // Fun��o para percorrer o grafo e contar esta��es
    function dfs(esta��o, visitados) {
        if (visitados[esta��o]) return 0;
        visitados[esta��o] = true;
        let contagem = 1;
        for (const pr�ximaEsta��o of grafo[esta��o]) {
            contagem += dfs(pr�ximaEsta��o, visitados);
        }
        return contagem;
    }

    // Contar esta��es a partir de cada esta��o
    let maxEsta��es = 0;
    for (let i = 1; i <= N; i++) {
        const visitados = {};
        const esta��oAtual = dfs(i, visitados);
        maxEsta��es = Math.max(maxEsta��es, esta��oAtual);
    }

    return maxEsta��es;
}

// Exemplo de uso
const N1 = 6;
const liga��es1 = [
    [1, 6],
    [1, 3],
    [4, 1],
    [3, 4],
    [5, 4],
    [3, 5],
    [2, 5],
    [3, 2],
    [6, 3],
    [2, 6]
];
console.log(contarEstacoesMetro(N1, liga��es1)); // Sa�da: 5

const N2 = 12;
const liga��es2 = [
    [7, 1],
    [9, 3],
    [5, 1],
    [7, 12],
    [7, 3],
    [4, 10],
    [3, 2],
    [6, 8],
    [10, 5],
    [7, 6],
    [2, 11],
    [7, 10],
    [12, 4],
    [8, 9],
    [3, 12],
    [1, 8],
    [7, 4]
];
console.log(contarEstacoesMetro(N2, liga��es2)); // Sa�da: 8
