def valor_napolitano(S):
    valores = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
    resultado = 0
    max_valor = 0

    for c in reversed(S):
        valor_atual = valores[c]
        if valor_atual < max_valor:
            resultado -= valor_atual
        else:
            resultado += valor_atual
            max_valor = valor_atual

    return resultado

def main():
    S = input().strip()
    resultado = valor_napolitano(S)
    print(resultado)

if __name__ == "__main__":
    main()
