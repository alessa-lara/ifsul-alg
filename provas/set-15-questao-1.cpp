#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int transformacaoNum(string sFormatado);

int main() {
    string ENTRADA = "nomes.txt";
    ifstream arqIn(ENTRADA, ios::in);

    if (arqIn.good() == true) {
        cout << "Arquivo nomes lido corretamente" << endl;
    }

    string SAIDA = "resultado.txt";
    ofstream arqOut(SAIDA, ios::out);

    string nome;
    for (string linha; getline(arqIn, linha);) { // passa as linhas
        nome = linha;
        for (int i = 0; i < linha.size(); i++) { // passa caractere por caractere
            if (isspace(linha[i])) {
                linha.erase(i, 1); // apaga o caractere
            }
            linha[i] = toupper(linha[i]); // converte para maiuscula
        }
        int numMagico = transformacaoNum(linha); // passa a linha ja formatada para gerar o numero
        arqOut << nome << " = " << numMagico << "\n"; // Escreve a linha formatada
    }

    arqIn.close();
    arqOut.close();
}

int transformacaoNum(string sFormatado) {
    int somatorio = 0;
    for (char c : sFormatado) {
        somatorio += (c - 'A') % 9 + 1; // Fiz isso em casa apos analise

        // switch (c) {
        //     case 'A': // 65
        //     case 'J': // 74
        //     case 'S': // 83
        //             somatorio += 1;
        //             break;
        //     case 'B': // 66
        //     case 'K': // 75
        //     case 'T': // 84
        //             somatorio += 2;
        //             break;
        //     case 'C': // 67
        //     case 'L': // 76
        //     case 'U': // 85
        //             somatorio += 3;
        //             break;
        //     case 'D': // 68
        //     case 'M':
        //     case 'V': // 86
        //             somatorio += 4;
        //             break;
        //     case 'E': // 69
        //     case 'N':
        //     case 'W': // 87
        //             somatorio += 5;
        //             break;
        //     case 'F': // 70
        //     case 'O':
        //     case 'X': // 88
        //             somatorio += 6;
        //             break;
        //     case 'G': // 71
        //     case 'P':
        //     case 'Y': // 89
        //             somatorio += 7;
        //             break;
        //     case 'H': // 72
        //     case 'Q':
        //     case 'Z':
        //             somatorio += 8;
        //             break;
        //     case 'I': // 73
        //     case 'R':
        //             somatorio += 9;
        //             break;
        // }
    }

    int numMagico = somatorio;
    string numString;
    do {
        if (numMagico == 11 || numMagico == 22) {
            break;
        }

        numString = to_string(numMagico);
        numMagico = 0;

        for (int i = 0; i < numString.size(); i++) {
            numMagico += numString[i] - '0';
        }

    } while (numMagico > 9);

    return numMagico;
}