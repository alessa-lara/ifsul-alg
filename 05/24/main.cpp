#include "funcNum.hpp"
#include "funcArrMat.hpp"
#include "menu.hpp"

#define LENGTH 10
using std::string;

int main () {
    int optLen = 6;
    string opcoes[] {
        "Gerar arranjo random",
        "Gerar matriz random",
        "Ordenar matriz",
        "Ordenar arranjo",
        "Verificar Numero Perfeito",
        "Verificar Numero Primo",
    };

    int userOpt = menu("", opcoes, optLen);

    int len = 4;
    int arr[len];
    int mat[len][len];

    switch (userOpt) {
        case 1:
            arrayRandom(arr, len, 0, 10, true);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
    }
}