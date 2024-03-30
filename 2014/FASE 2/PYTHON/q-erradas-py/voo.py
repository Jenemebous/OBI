def converter_horario_para_minutos(horario):
    # Converter o horário para minutos desde a meia-noite
    horas, minutos = map(int, horario.split(':'))
    return horas * 60 + minutos

def calcular_duracao_voo(p_A, c_B, p_B, c_A):
    # Converter horários para minutos
    partida_A = converter_horario_para_minutos(p_A)
    chegada_B = converter_horario_para_minutos(c_B)
    partida_B = converter_horario_para_minutos(p_B)
    chegada_A = converter_horario_para_minutos(c_A)

    # Calcular a duração do voo
    duracao_voo = chegada_B - partida_A

    # Calcular a diferença de fusos horários entre as cidades A e B
    diferenca_fusos = (partida_B - chegada_A) // 60

    # Determinar se B está à frente ou atrás de A em termos de fusos horários
    if chegada_B < partida_A:
        diferenca_fusos -= 1

    return duracao_voo, diferenca_fusos

def main():
    # Ler os horários dos voos
    p_A, c_B, p_B, c_A = input().split()

    # Calcular a duração do voo e a diferença de fusos horários
    duracao_voo, diferenca_fusos = calcular_duracao_voo(p_A, c_B, p_B, c_A)

    # Imprimir resultado
    print(duracao_voo, diferenca_fusos)

if __name__ == "__main__":
    main()
