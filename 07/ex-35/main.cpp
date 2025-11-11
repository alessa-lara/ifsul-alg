#include "menu.hpp"
#include "iostream"

using namespace std;

struct Aluno{
    string nome = "";
    string disciplina;
    float nota[3];
};

void cadastrar(Aluno aluno) {
    cout << "Digite o nome do aluno: ";
    cin >> aluno.nome;

    cout << "Digite a disciplina: ";
    cin >> aluno.disciplina;

    for (int i = 0; i < 3; i++) {
        cout << "Digite a " << i << "° nota do aluno: ";
        cin >> aluno.nota[i];
    }
}

void mostrar(Aluno aluno) {
    cout << "Nome do aluno: " << aluno.nome << endl;
    cout << "Disciplina: " << aluno.disciplina << endl;

    for (int i = 0; i < 3; i++) {
        cout << i << "° nota do aluno: " << aluno.nota[i] << endl;
    }
}

float media(Aluno aluno) {
    float media = 0;
    int pesos[3] = {2, 3, 5};
    for (int i = 0; i < 3; i++) {
        media += aluno.nota[i] * pesos[i];
    }
    media /= pesos[0] + pesos[1] + pesos[2];
    return media;
}

int main() {

    string opcoes[] {
        "Sair",
        "Cadastrar",
        "Mostrar",
        "Calcular Média",
    };
    size_t optLen = 4;

    int userOpt;
    Aluno aluno;
    while (true) {
        userOpt = menu("", opcoes, optLen);

        switch (userOpt) {
            case 0:
                return 0;
            case 1:
                cadastrar(aluno);
                break;
            case 2:
                mostrar(aluno);
                break;
            case 3:
                if (aluno.nome.empty()) {
                    cout << "Necessário cadastrar um aluno antes de calcular a média";
                    continue;
                }
                cout << "Média ponderada das notas: " << media(aluno);
                break;
        }
    }
}