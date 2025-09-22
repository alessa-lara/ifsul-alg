#include <iostream>
using std::cout, std::endl;

int somaInteirosDiviseisA(int a, int b, int c) {
    if (a < 1) {return 1;}

    int sum = 0;
    for (int i = b; i <= c; i++) { // b ..= c 
        if (i % a == 0) {sum += i;}
    }

    return sum;
}

int main () {
    int x = somaInteirosDiviseisA(5, 3, 22);
    cout << "A soma dos valores inteiros divisíveis por A na faixa (B, C) = " << x << endl;
}