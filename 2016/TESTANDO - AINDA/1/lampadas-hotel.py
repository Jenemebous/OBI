def min_interruptores(IA, IB, FA, FB):
    if IA == FA == IB == FB:  # Se os estados iniciais e finais forem iguais, precisamos apertar um interruptor duas vezes
        return 1
    elif (IA == FA and IB == FB) or (IA != FA and IB != FB):  # Se os estados iniciais e finais forem iguais ou diferentes, precisamos apertar dois interruptores uma vez cada
        return 2
    else:  # Se os estados iniciais e finais forem diferentes entre si, precisamos apertar dois interruptores uma vez cada
        return 2

# Leitura da entrada
IA, IB, FA, FB = map(int, input().split())

# Chamada da função e impressão do resultado
print(min_interruptores(IA, IB, FA, FB))
