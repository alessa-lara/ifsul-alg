#include <iostream>

using namespace std;

inline void clearScreen() { std::cout << "\033[2J\033[1;1H"; }

void repeatChar(char c, int* n) {
    for (int i = 0; i < *n; i++) {
        cout << c;
    }
}

int main() {
    int height;
    int* pHeight = &height;

    do {
        cout << "Insira um valor para n, tal que 3 <= n <= 9: ";
        cin >> *pHeight;
        clearScreen();
        if (*pHeight < 3 || *pHeight > 9) {
            cout << "Valor fora do intervalo \n";
        }
    } while(*pHeight < 3 || *pHeight > 9);

    int espacos;
    int* pEspacos = &espacos;
    for (int i = 1; i <= *pHeight; i++) {
        *pEspacos = (*pHeight - i) * 2;
        repeatChar(' ', pEspacos);

        for (int j = 1; j <= i; j++) {
            cout << j << ' ';
        }
        
        cout << '\n';
    }
}