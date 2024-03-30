def catador_de_conchas(N, M, quantidades, operacoes):
    total_conchas = sum(quantidades)  # Total de conchas inicialmente

    for indice in operacoes:
        conchas_no_baldes = quantidades[indice - 1]  # Quantidade de conchas no balde atual

        # Remover uma concha de cada balde dentro do alcance especificado
        for j in range(max(1, indice - conchas_no_baldes), min(N + 1, indice + conchas_no_baldes + 1)):
            quantidades[j - 1] -= 1

    # Calcular o total de conchas restantes
    total_conchas_restantes = sum(quantidades)

    return total_conchas_restantes

# Leitura da entrada
N, M = map(int, input().split())  # Número de baldes e operações
quantidades = list(map(int, input().split()))  # Quantidades de conchas em cada balde
operacoes = list(map(int, input().split()))  # Índices das operações

# Chamar a função e imprimir o resultado
print(catador_de_conchas(N, M, quantidades, operacoes))
