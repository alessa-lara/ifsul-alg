#include "iostream"

using namespace std;

int main() {
    struct resultados{
        float numA = 0;
        float numB = 0;
        float adicao = 0;
        float subtracao = 0;
        float multiplicacao = 0;
        float potenciacao = 1;
    };

    resultados result;

    while (true) {
        cout << "Insira um valor para o numero A: ";
        cin >> result.numA;
        cout << endl;

        cout << "Insira um valor para o numero B: ";
        cin >> result.numB;
        cout << endl;

        result.adicao = result.numA + result.numB;
        result.subtracao = result.numA - result.numB;
        result.multiplicacao = result.numA * result.numB;
        
        for (int i = 0; i < result.numB; i++) {
            result.potenciacao *= result.numA;
        }

        cout << "resultado da adicao: " << result.adicao << endl;
        cout << "resultado da subtracao: " << result.subtracao << endl;
        cout << "resultado da multiplicacao: " << result.multiplicacao << endl;
        cout << "resultado da potenciacao: " << result.potenciacao << endl;
    }
}