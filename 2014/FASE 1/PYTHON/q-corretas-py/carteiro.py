def busca_binaria(casas, casa_entrega):
    # Busca binária para encontrar a posição da casa de entrega
    esquerda, direita = 0, len(casas) - 1
    while esquerda <= direita:
        meio = (esquerda + direita) // 2
        if casas[meio] == casa_entrega:
            return meio
        elif casas[meio] < casa_entrega:
            esquerda = meio + 1
        else:
            direita = meio - 1
    return -1  # Casa de entrega não encontrada

def calcular_tempo_entrega(N, M, casas, encomendas):
    tempo_total = 0
    posicao_carteiro = 0  # Posição inicial do carteiro
    for casa_entrega in encomendas:
        posicao_entrega = busca_binaria(casas, casa_entrega)
        distancia = abs(posicao_entrega - posicao_carteiro)
        tempo_total += distancia
        posicao_carteiro = posicao_entrega
    return tempo_total

def main():
    N, M = map(int, input().split())
    casas = list(map(int, input().split()))
    encomendas = list(map(int, input().split()))

    tempo_entrega = calcular_tempo_entrega(N, M, casas, encomendas)
    print(tempo_entrega)

if __name__ == "__main__":
    main()
