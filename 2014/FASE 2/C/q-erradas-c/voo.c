#include <stdio.h>

int main() {
    int p_A_h, p_A_m, c_B_h, c_B_m, p_B_h, p_B_m, c_A_h, c_A_m;
    
    // Leitura dos horários
    scanf("%d:%d %d:%d %d:%d %d:%d", &p_A_h, &p_A_m, &c_B_h, &c_B_m, &p_B_h, &p_B_m, &c_A_h, &c_A_m);
    
    // Cálculo da duração do voo em minutos
    int duracao_voo = ((c_B_h * 60 + c_B_m) - (p_A_h * 60 + p_A_m) + 1440) % 1440; // adição de 1440 para lidar com horários "negativos"
    
    // Cálculo da diferença de fusos horários
    int diff_fusos = ((c_A_h * 60 + c_A_m) - (p_B_h * 60 + p_B_m) + 1440) % 1440; // adição de 1440 para lidar com horários "negativos"
    
    // Converte a diferença de fusos horários para horas inteiras
    int diff_fusos_horas = diff_fusos / 60;
    
    // Saída da duração do voo em minutos e diferença de fusos horários em horas
    printf("%d %d\n", duracao_voo, diff_fusos_horas);
    
    return 0;
}
