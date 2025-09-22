#include <iostream>
using std::cout, std::endl;

float pesoIdeal(float alt, bool masc) {
    float pesoIdeal;
    if (masc) {
        pesoIdeal = 72.7 * alt - 58;
    } else {
        pesoIdeal = 62.1 * alt - 44.7;
    }

    return pesoIdeal;
}

int main() {
    float elise = pesoIdeal(1.73, false);
    float ana = pesoIdeal(1.50, false);
    float jean = pesoIdeal(1.75, true);

    cout << "peso ideal de elise " << elise << endl;
    cout << "peso ideal de ana " << ana << endl;
    cout << "peso ideal de jean " << jean << endl;
}