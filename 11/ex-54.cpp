#include "floyd.hpp"

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <cmath>
#include <iomanip>

using namespace std;

const string LEITURA = "arquivo.txt";
const string ESCRITA = "arquivo.txt";

void criarArquivo();
int readQuantidadeNumeros();
void ordenar(string arr[], int* len);
int readFile(int vals[], int *len);
int writeFile(int arr[], int *len);

int main() {
    criarArquivo();
    // Agora que temos o arquivo gerado aleatoriamente, vamos: ler, ordenar e reescrever
    int* n = new int(readQuantidadeNumeros());
    
    if (*n <= 0) {
        cout << "Erro: Não foi possível ler a quantidade de números" << endl;
        return 1;
    }

    int* vals = new int[*n];
    readFile(vals, n);
    // ordenar(vals, n);
    writeFile(vals, n);

    return 0;
}

void criarArquivo() {
    // Criacao do arquivo com números aleatorios, pode ser retirado se ja tem o arquivo
    int* n = new int(10);
    int* vals = new int[*n]; // arr[]
    int* max = new int(50);
    int* min = new int (1);

    random(vals, *n, *min, *max);

    writeFile(vals, n);
}

int readQuantidadeNumeros() {
    ifstream* arq = new ifstream(LEITURA);

    if (! arq -> is_open()) {
        cout << "erro: falha na abertura do arquivo" << endl;
        return -1;
    }

    string* word = new string;
    int* cont = new int(0);
    while (*arq >> *word) {
        (*cont)++;
    }

    arq -> close();
    return *cont;
}

void ordenar(string arr[], int* len) {
    // TODO: transformar array para int

    int* tempArr = new int[*len];   
    for (int i = 0; i < *len; i++) {
        string cleanStr = "";
        for (char c : arr[i]) {
            if (isdigit(c)) {
                cleanStr += c;
            }
        }
        *(tempArr + i) = stoi(cleanStr);
    }

    bool troca = false;

    for (int i = 0; i < *len - 1; i++) {
        troca = false;
        for (int j = 0; j < *len - 1; j++) {
            if (tempArr[j] > tempArr[j + 1]) {
                swap(tempArr[j], tempArr[j + 1]);
                troca = true;
            }
        }
        if (!troca) {
            break;
        }
    }

    for (int i = 0; i < *len; i++) {
        *(arr + i) = to_string(*(tempArr + i));
    }
}

int readFile(int vals[], int *len) {
    ifstream* arq = new ifstream(LEITURA);

    if (! arq -> is_open()) {
        cout << "erro: falha na abertura do arquivo" << endl;
        return 1;
    }

    string* word = new string;
    int* i = vals + 0;
    while (*arq >> *word) {
        *i = stoi(*word); // vals[i] = word
        i++;
    }

    (*arq).close();
    return 0;
}

int writeFile(int arr[], int *len) {
    ofstream arq(ESCRITA, std::ios::app);

    if (!arq.is_open()) {
        cout << "erro: falha na abertura do arquivo" << endl;
        return -1;
    }

    for (int i = 0; i < *len; i++) {
        arq << *(arr + i) << ' '; // arr[i]
    }
    arq << endl;

    arq.close();
    return 0;
}
