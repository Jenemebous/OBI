from collections import defaultdict

def dfs(graph, start, visited):
    visited.add(start)
    for neighbor in graph[start]:
        if neighbor not in visited:
            dfs(graph, neighbor, visited)

def main():
    N, M = map(int, input().split())

    # Criando um grafo para representar as conexões entre as estações
    graph = defaultdict(list)
    for _ in range(M):
        P, Q = map(int, input().split())
        graph[P].append(Q)
        graph[Q].append(P)

    # Encontrando a estação central (a estação com o maior número de conexões)
    central_station = max(graph, key=lambda k: len(graph[k]))

    # Realizando uma busca em profundidade a partir da estação central
    visited = set()
    dfs(graph, central_station, visited)

    # O número de estações visitadas menos 1 (já que a estação central é contada duas vezes)
    print(len(visited) - 1)

if __name__ == "__main__":
    main()
