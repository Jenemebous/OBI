def calcular_penalidades(N, coordenadas):
    penalidades = [0]  # A primeira flecha não tem penalidade
    max_distancias = []  # Lista para armazenar as maiores distâncias para cada flecha
    
    # Percorrendo as coordenadas das flechas
    for i in range(1, N):
        distancias = []  # Lista para armazenar as distâncias para cada flecha
        
        # Calculando as distâncias das flechas anteriores à flecha atual
        for j in range(i):
            distancia = (coordenadas[i][0] - coordenadas[j][0]) ** 2 + (coordenadas[i][1] - coordenadas[j][1]) ** 2
            distancias.append(distancia)
        
        # Contando as flechas mais próximas ou à mesma distância
        penalidade = sum(1 for d in distancias if d <= max_distancias[j])
        penalidades.append(penalidade)
        max_distancias.append(max(distancias))
    
    return penalidades

# Leitura da entrada
N = int(input())
coordenadas = [list(map(int, input().split())) for _ in range(N)]

# Chamada da função para calcular as penalidades
penalidades = calcular_penalidades(N, coordenadas)

# Impressão das penalidades
for penalidade in penalidades:
    print(penalidade)
