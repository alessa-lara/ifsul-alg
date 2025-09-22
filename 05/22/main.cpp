#include <iostream>
using std::cout, std::endl;

float media(char tipoMedia, float notas[3]) {
    float dividendo = 0;
    float divisor = 0;
    int pesos[3] = {5, 3, 2};
    switch (tipoMedia) {
        case 'a':
            for (int i = 0; i < 3; i++) {
                dividendo += notas[i];
            };
            divisor = 3;
            break;
        case 'p':
            for (int i = 0; i < 3; i++) {
                dividendo += notas[i] * pesos[i];
                divisor += pesos[i];
            };
            break;
        case 'h':
            for (int i = 0; i < 3; i++) {
                divisor += 1 / notas[i];
            };
            dividendo = 3;
            break;
    }

    return dividendo /= divisor;
}

int main() {
    float notas[3] = {7, 6, 4};
    float arit = media('a', notas);
    float pond = media('p', notas);
    float harmon = media('h', notas);

    
    cout << "media aritmetica: " << arit << endl;
    cout << "media ponderada: " << pond << endl;
    cout << "media harmonica: " << harmon << endl;
}