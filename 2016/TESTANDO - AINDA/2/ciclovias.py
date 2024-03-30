from collections import defaultdict

def dfs(graph, visited, start):
    visited[start] = True
    max_path_length = 0
    for neighbor in graph[start]:
        if not visited[neighbor]:
            max_path_length = max(max_path_length, dfs(graph, visited, neighbor))
    visited[start] = False
    return max_path_length + 1

def encontrar_maior_caminho(N, M, ruas):
    graph = defaultdict(list)
    for a, b in ruas:
        graph[a].append(b)

    max_path_lengths = [0] * (N + 1)
    for i in range(1, N + 1):
        visited = [False] * (N + 1)
        max_path_lengths[i] = dfs(graph, visited, i)
    
    return max_path_lengths[1:]

# Leitura da entrada
N, M = map(int, input().split())
ruas = [tuple(map(int, input().split())) for _ in range(M)]

# Chamada da função para encontrar o maior caminho para cada interseção
resultados = encontrar_maior_caminho(N, M, ruas)

# Impressão dos resultados
print(*resultados)
