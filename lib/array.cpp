#include <stdlib.h> // srand(), rand()
#include <time.h>   // arrRandom()

void arrayRandom(int array[], int length, int min, int max,
                 bool valUnicos) {
    srand(time(NULL));
    int tmp;
    bool valDuplo;
    for (int i = 0; i < length; i++) {
        valDuplo = false;
        tmp = rand() % (max + 1 - min) + min;
        if (valUnicos) {
            for (int j = 0; j < i; j++) {
                if (array[j] == tmp) {
                    valDuplo = true;
                    break;
                }
            }
        }
        if (valDuplo) {
            i--;
            continue;
        }
        array[i] = tmp;
    }
}

void bubbleSort(int array[], int length, bool crescente) {
    int temp;
    bool troca;
    bool comp;

    for (int i = 0; i < length; i++) {
        troca = false;
        for (int j = 0; j < length - i - 1; j++) {
            if (crescente) {
                comp = array[j] > array[j + 1];
            } else {
                comp = array[j] < array[j + 1];
            }

            if (comp) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                troca = true;
            }
        }
        if (!troca) {
            break;
        }
    }
}

void sortMatrix(int** mat, int lin, int col) {
    // Como mat e passado como ponteiros, nao precisa ter retorno
    int transSize = lin * col;
    int temp[transSize];

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            temp[(i * col) + j] = mat[i][j];
        }
    }

    bubbleSort(temp, transSize, true);

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            mat[i][j] = temp[(i * col) + j];
        }
    }
}
