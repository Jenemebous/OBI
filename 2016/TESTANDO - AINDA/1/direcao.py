def menor_angulo(direcao_amigo, direcao_oasis):
    direcoes = {'norte': 0, 'leste': 90, 'sul': 180, 'oeste': 270}
    angulo_amigo = direcoes[direcao_amigo]
    angulo_oasis = direcoes[direcao_oasis]

    diferenca = (angulo_oasis - angulo_amigo) % 360

    if diferenca <= 180:
        return diferenca
    else:
        return 360 - diferenca

# Leitura da entrada
direcao_amigo, direcao_oasis = input().split()

# Chamada da função e impressão do resultado
print(menor_angulo(direcao_amigo, direcao_oasis))
