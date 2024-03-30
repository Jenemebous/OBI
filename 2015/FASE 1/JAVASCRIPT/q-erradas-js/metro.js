function contarEstacoesMetro(N, ligações) {
    // Construir um grafo direcionado a partir das ligações
    const grafo = {};
    for (let i = 1; i <= N; i++) {
        grafo[i] = [];
    }
    for (const [origem, destino] of ligações) {
        grafo[origem].push(destino);
    }

    // Função para percorrer o grafo e contar estações
    function dfs(estação, visitados) {
        if (visitados[estação]) return 0;
        visitados[estação] = true;
        let contagem = 1;
        for (const próximaEstação of grafo[estação]) {
            contagem += dfs(próximaEstação, visitados);
        }
        return contagem;
    }

    // Contar estações a partir de cada estação
    let maxEstações = 0;
    for (let i = 1; i <= N; i++) {
        const visitados = {};
        const estaçãoAtual = dfs(i, visitados);
        maxEstações = Math.max(maxEstações, estaçãoAtual);
    }

    return maxEstações;
}

// Exemplo de uso
const N1 = 6;
const ligações1 = [
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
console.log(contarEstacoesMetro(N1, ligações1)); // Saída: 5

const N2 = 12;
const ligações2 = [
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
console.log(contarEstacoesMetro(N2, ligações2)); // Saída: 8
