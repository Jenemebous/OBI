def verificar_ordem(cartas):
    if cartas == sorted(cartas):
        return 'C'
    elif cartas == sorted(cartas, reverse=True):
        return 'D'
    else:
        return 'N'

def main():
    cartas = list(map(int, input().split()))
    resultado = verificar_ordem(cartas)
    print(resultado)

if __name__ == "__main__":
    main()
