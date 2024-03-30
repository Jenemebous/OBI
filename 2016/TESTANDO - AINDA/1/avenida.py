def menor_desapropriacao(N, M, quadras):
    menor_valor = float('inf')  # Inicializamos o menor valor com infinito
    
    # Percorrendo todas as ruas no sentido Norte-Sul
    for i in range(N):
        valor_rua = sum(quadras[i])  # Calculando o valor total das quadras para a rua atual
        menor_valor = min(menor_valor, valor_rua)  # Atualizando o menor valor encontrado
    
    return menor_valor

# Leitura da entrada
N, M = map(int, input().split())
quadras = [list(map(int, input().split())) for _ in range(N)]

# Chamada da função e impressão do resultado
print(menor_desapropriacao(N, M, quadras))
