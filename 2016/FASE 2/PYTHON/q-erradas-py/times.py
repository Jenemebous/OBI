from collections import deque

def divide_times(N, dislikes):
    # Inicialização dos times
    team1 = [1]  # O aluno 1 sempre estará no primeiro time
    team2 = []
    
    # Lista de visitados para evitar repetições
    visited = [False] * (N + 1)
    visited[1] = True
    
    # BFS para formar os times
    queue = deque([1])
    while queue:
        current = queue.popleft()
        current_team = team1 if current in team1 else team2
        
        for person in dislikes[current]:
            if not visited[person]:
                visited[person] = True
                current_team.append(person)
                queue.append(person)
    
    return sorted(team1), sorted(team2)

# Lendo a entrada
N = int(input())  # Número de alunos
dislikes = {}  # Dicionário para armazenar quem não gosta de quem
for i in range(1, N + 1):
    _, *disliked_by_i = map(int, input().split())
    dislikes[i] = disliked_by_i

# Formando os times
team1, team2 = divide_times(N, dislikes)

# Imprimindo os times
print(*team1)
print(*team2)
