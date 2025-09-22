#include <stdlib.h> // srand(), rand()
#include <time.h>   // arrRandom()

#define LENGTH 10

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
        if (troca == false) {
            break;
        }
    }
}

void sortMatrix(int mat[LENGTH][LENGTH]) {
    // Como mat e passado como ponteiros, nao precisa ter retorno
    int transSize = LENGTH * 2;
    int temp[transSize];

    for (int i = 0; i < LENGTH; i++) {
        for (int j = 0; j < LENGTH; j++) {
            temp[i + j] = mat[i][j];
        }
    }

    bubbleSort(temp, transSize, true);

    for (int i = 0; i < LENGTH; i++) {
        for (int j = 0; j < LENGTH; j++) {
            mat[i][j] = temp[i + j];
        }
    }
}
