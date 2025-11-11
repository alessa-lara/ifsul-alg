#include <iostream>

using namespace std;

int restoRacao(int* pKgRac, int* pGrRac);

int main() {
    int kgRacao;
    int* pKgRac = &kgRacao;
    cout << "Informe a quantidade de racao em KG comprado: ";
    cin >> kgRacao;
    cin.ignore();
    cout << endl;

    int gRacao;
    int* pGrRac = &gRacao;
    cout << "Informe a quantidade de racao em G que os gatos recebem a cada dia: ";
    cin >> gRacao;
    cin.ignore();
    cout << endl;

    int resto = restoRacao(pKgRac, pGrRac);
    cout << "Após 5 dias fornecendo " << *pGrRac << "g de ração por dia, sobrou " << resto << "g de ração dos " << *pKgRac << "kg comprados";
}

int restoRacao(int* pKgRac, int* pGrRac) {
    cout << pKgRac << endl;
    cout << pGrRac << endl;
    int consumo = (*pKgRac * 1000) - (*pGrRac * 5);
    return consumo;
}