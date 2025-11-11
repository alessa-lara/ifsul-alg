#include <iostream>

using namespace std;

inline void clearScreen() { std::cout << "\033[2J\033[1;1H"; }
void maiorElemento(int arr[], int len, int* rMaior, int* rCount);

#define LEN 5

int main() {
    int arr[LEN];

    for (int i = 0; i < LEN; i++) {
        cout << "Digite o valor para o número " << i + 1 << " do array: ";
        cin >> arr[i];
    }
    clearScreen();

    int rMaior;
    int rCount;
    maiorElemento(arr, LEN, &rMaior, &rCount);

    cout << "Maior elemento: " << *&rMaior << '\n';
    cout << "Este elemento aparece " << *&rCount << " vezes no array";
}

// mesmo que int* arr
// utilizando r como sufixo para as variaveis de retorno
void maiorElemento(int arr[], int len, int* rMaior, int* rCount) {
    // Determinar o maior elemento do array
    // determinar o numero de vezes que este elemento aparece
    *rMaior = 0;
    *rCount = 0;
    for (int i = 0; i < len; i++) {
        if (arr[i] > *rMaior) {
            *rMaior = arr[i];
            *rCount = 1;
        } else if (arr[i] == *rMaior) {
            *rCount += 1;
        }
    }
}