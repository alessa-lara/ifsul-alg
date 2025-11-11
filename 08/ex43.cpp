#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void randomArray(int arr[], int* len, int* max, int* min);

int main() {
    int len, max, min;
    int *pLen, *pMax, *pMin;

    pLen = &len;
    pMax = &max;
    pMin = &min;

    *pLen = 6;
    *pMax = 50;
    *pMin = 1;

    int arr[*pLen];
    randomArray(arr, pLen, pMax, pMin);

    int par[*pLen];
    int posPar[*pLen];
    int indPar = 0;

    int imp[*pLen];
    int posImp[*pLen];
    int indImp = 0;

    for (int i = 0; i < *pLen; i++) {
        par[i] = 0;
        imp[i] = 0;
    }

    for (int i = 0; i < *pLen; i++) {
        if (*&arr[i] % 2 == 0) {
            *&par[*&indPar] = *&arr[i];
            *&posPar[*&indPar] = i;
            *&indPar += 1;
        } else {
            *&imp[*&indImp] = *&arr[i];
            *&posImp[*&indImp] = i;
            *&indImp += 1;
        }
    }

    cout << "Relatório \n";

    cout << "Os números pares são: \n";
    int soma = 0;
    int* pSoma = &soma;
    for (int i = 0; i < *pLen; i++) {
        if (par[i] != 0) {
            cout << "número " << par[i] << " na posição " << posPar[i] << endl;
            *pSoma += par[i];
        } else {
            cout << "Soma dos pares = " << *pSoma << "\n \n";
            break;
        }
    }

    cout << "Os números ímpares são: \n";
    for (int i = 0; i < *pLen; i++) {
        if (imp[i] != 0) {
            cout << "número " << imp[i] << " na posição " << posImp[i] << endl;
        } else {
            cout << "Quantidade de ímpares = " << *&i;
            break;
        }
    }
}

void randomArray(int arr[], int* len, int* max, int* min) {
    int range = *max - *min; // n
    unsigned int isUsed[range];
    for (int i = 0; i < range; i++) {
        isUsed[i] = 0;
    }

    srand(time(NULL));
    int iRange = 0;
    for (int i = range - *len; i < range && iRange < *len; ++i) {
        int randNum = rand() % (i + 1);

        if (isUsed[randNum]) {
            randNum = i;
        }

        arr[iRange++] = randNum + *min;
        isUsed[randNum] = 1;
    }
}