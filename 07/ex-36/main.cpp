#include "arquivo.hpp"
#include "menu.hpp"
#include <iostream>

using namespace std;

struct Operacoes{
    bool leitura = false;
    bool deposito = false;
    bool sacar = false;
};

void verificarClientes();
void cadastro();
void operacaoConta(Operacoes operacao);

int NUM_CLIENTES;

int main() {
    verificarClientes();

    string opcoes[]{
        "Cadastrar contas;",
        "Visualizar dados da conta",
        "Depositar",
        "Sacar",
        "Sair"};
    size_t len = 5;

    Operacoes op;
    int userOpt = menu("", opcoes, len);
    switch (userOpt) {
        case 1:
            cadastro();
            break;
        case 2:
            op.leitura = true;
            operacaoConta(op);
            break;
        case 3:
            op.deposito = true;
            operacaoConta(op);
            break;
        case 4:
            op.sacar = true;
            operacaoConta(op);
            break;
        case 5:
            return 0;
    }

    return 0;
}

void cadastro() {
    ContaBancaria conta;

    cout << "Digite seu nome: ";
    cin >> conta.nomeCliente;

    NUM_CLIENTES++;
    conta.numConta = NUM_CLIENTES;
    cout << "Seu número de conta é: " << NUM_CLIENTES;

    string opt[2] {
        "Sim",
        "Não"
    };
    int userOpt = menu("Gostaria de realizar um depósito inicial?", opt, 2);
    switch (userOpt) {
        case 1:
            cin >> conta.saldo;
            break;
        case 2:
            break;
    }

    writeFile(conta);
}