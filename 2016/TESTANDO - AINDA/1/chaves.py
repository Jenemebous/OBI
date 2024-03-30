def chaves_balanceadas(N, codigo):
    pilha = []

    for linha in codigo:
        for caractere in linha:
            if caractere == "\\":
                pilha.append(caractere)
            elif caractere == "/":
                if pilha and pilha[-1] == "\\":
                    pilha.pop()
                else:
                    return "N"

    if not pilha:
        return "S"
    else:
        return "N"

# Leitura da entrada
N = int(input())
codigo = [input() for _ in range(N)]

# Chamada da função e impressão do resultado
print(chaves_balanceadas(N, codigo))
