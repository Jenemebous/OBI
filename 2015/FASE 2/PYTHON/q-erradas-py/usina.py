from collections import deque

def menor_tempo_para_prevenir_acidente(N, M, C, K, salas_com_pessoas, escorregadores):
    # Construir o grafo de adjac�ncia representando a usina
    grafo = [[] for _ in range(N + 1)]
    for a, b, d in escorregadores:
        grafo[a].append((b, d))

    # Inicializa��o da busca em largura
    visitados = set()
    fila = deque([(1, 0)])  # (sala, tempo)

    while fila:
        sala, tempo = fila.popleft()

        # Verificar se chegamos perto o suficiente do t�cnico
        if sala == N:
            return tempo

        # Verificar se h� pessoas nesta sala e propagar o aviso
        if sala in salas_com_pessoas:
            for vizinho, dist in grafo[sala]:
                if dist <= K and vizinho not in visitados:
                    visitados.add(vizinho)
                    fila.append((vizinho, tempo + 1))

    return -1  # N�o foi poss�vel prevenir o acidente

# Lendo entrada
N, M, C, K = map(int, input().split())
salas_com_pessoas = set(map(int, input().split()))
escorregadores = [tuple(map(int, input().split())) for _ in range(M)]

# Chamando a fun��o e imprimindo o resultado
print(menor_tempo_para_prevenir_acidente(N, M, C, K, salas_com_pessoas, escorregadores))
