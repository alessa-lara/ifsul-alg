#include <iostream>

inline void hang() {
    std::cout << "Pressione [enter] para continuar";
    std::cin.ignore();
    getchar();
}
