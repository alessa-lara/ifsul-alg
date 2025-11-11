#include <string>

struct leituraOpcoes {
    std::string padrao = ""; // Se queremos encontrar algum padrao no arquivo
    int offset = 0;     // capturar posicao X apos a ocorrencia do padrao
    bool ocorrencias = false; // Contar a quantia de ocorrencias?
};

struct ContaBancaria {
    int numConta;
    std::string nomeCliente;
    float saldo;
};

int readFile(leituraOpcoes opt, std::string valores[1] = 0, int valLen = 0); // retorna -1 em erro
int writeFile(ContaBancaria conta);