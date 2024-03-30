#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int p_A_hour, p_A_minute, c_B_hour, c_B_minute, p_B_hour, p_B_minute, c_A_hour, c_A_minute;
    char colon;
    
    // Leitura dos horários
    cin >> p_A_hour >> colon >> p_A_minute >> c_B_hour >> colon >> c_B_minute >> p_B_hour >> colon >> p_B_minute >> c_A_hour >> colon >> c_A_minute;

    // Cálculo da duração do voo
    int departure_time_A = p_A_hour * 60 + p_A_minute;
    int arrival_time_B = c_B_hour * 60 + c_B_minute;
    int flight_duration_AB = (arrival_time_B - departure_time_A + 1440) % 1440;

    // Cálculo da diferença de fusos horários
    int departure_time_B = p_B_hour * 60 + p_B_minute;
    int arrival_time_A = c_A_hour * 60 + c_A_minute;
    int flight_duration_BA = (arrival_time_A - departure_time_B + 1440) % 1440;
    int time_zone_difference = (flight_duration_BA - flight_duration_AB) / 60;

    cout << flight_duration_AB << " " << time_zone_difference << endl;

    return 0;
}

