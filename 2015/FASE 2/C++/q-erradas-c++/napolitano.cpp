#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    string s;
    cin >> s;

    unordered_map<char, int> valores = {
        {'I', 1}, {'V', 5}, {'X', 10},
        {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int valor = 0;
    int lastValue = 0;

    for (int i = 0; i < s.length(); ++i) {
        int current = valores[s[i]];
        
        if (i > 0 && current > lastValue) {
            valor += current - 2 * lastValue;
        } else {
            valor += current;
        }
        
        lastValue = current;
    }

    cout << valor << endl;

    return 0;
}
