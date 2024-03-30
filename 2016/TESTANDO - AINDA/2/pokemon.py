# Lendo a entrada
N = int(input())  # Número de doces disponíveis
X = int(input())  # Doces necessários para a primeira pô-que-mão evoluir
Y = int(input())  # Doces necessários para a segunda pô-que-mão evoluir
Z = int(input())  # Doces necessários para a terceira pô-que-mão evoluir

# Calculando o máximo de pô-que-mãos que podem evoluir
max_pokemon = min(N // X, N // Y, N // Z)

# Imprimindo o resultado
print(max_pokemon)
