def is_pinheiro(P):
    # Verificar se o ângulo P2P1P3 é agudo
    produto_escalar = (P[1][0] - P[0][0]) * (P[2][0] - P[0][0]) + (P[1][1] - P[0][1]) * (P[2][1] - P[0][1])
    if produto_escalar <= 0:
        return False
    
    # Verificar se os segmentos P1P2 e P1P3 têm o mesmo comprimento
    dist1 = (P[1][0] - P[0][0])**2 + (P[1][1] - P[0][1])**2
    dist2 = (P[2][0] - P[0][0])**2 + (P[2][1] - P[0][1])**2
    if dist1 != dist2:
        return False
    
    # Verificar se os pontos P2, P3, P4 e P5 são colineares
    produto_vetorial = (P[2][0] - P[1][0]) * (P[4][1] - P[3][1]) - (P[4][0] - P[3][0]) * (P[2][1] - P[1][1])
    if abs(produto_vetorial) > 10**-9:
        return False
    
    # Verificar se os pontos médios dos segmentos P2P3 e P4P5 são coincidentes
    meio1_x = (P[1][0] + P[2][0]) / 2
    meio1_y = (P[1][1] + P[2][1]) / 2
    meio2_x = (P[3][0] + P[4][0]) / 2
    meio2_y = (P[3][1] + P[4][1]) / 2
    if abs(meio1_x - meio2_x) > 10**-9 or abs(meio1_y - meio2_y) > 10**-9:
        return False
    
    # Verificar se o segmento P2P3 tem comprimento maior que o segmento P4P5
    dist3 = (P[2][0] - P[1][0])**2 + (P[2][1] - P[1][1])**2
    dist4 = (P[4][0] - P[3][0])**2 + (P[4][1] - P[3][1])**2
    if dist3 <= dist4:
        return False
    
    # Verificar se os segmentos P4P6 e P5P7 são perpendiculares ao segmento P2P3
    produto_escalar1 = (P[4][0] - P[3][0]) * (P[2][0] - P[1][0]) + (P[4][1] - P[3][1]) * (P[2][1] - P[1][1])
    produto_escalar2 = (P[6][0] - P[5][0]) * (P[2][0] - P[1][0]) + (P[6][1] - P[5][1]) * (P[2][1] - P[1][1])
    if abs(produto_escalar1) > 10**-9 or abs(produto_escalar2) > 10**-9:
        return False
    
    # Verificar se os segmentos P4P6 e P5P7 têm o mesmo comprimento
    dist5 = (P[4][0] - P[3][0])**2 + (P[4][1] - P[3][1])**2
    dist6 = (P[6][0] - P[5][0])**2 + (P[6][1] - P[5][1])**2
    if dist5 != dist6:
        return False
    
    # Verificar se os pontos P1 e P6 estão separados pela reta que contém o segmento P2
