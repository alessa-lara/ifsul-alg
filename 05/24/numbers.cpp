

bool numPrimo(int num) {
    if (num <= 1) {
        return false;
    }

    int div = 0;
    for (int i = 0; i < num; i++) {
        if (div > 2) {
            return false;
        }
        if (num % i == 0) {
            div++;
        }
    }

    return true;
}

bool numPerfeito(int num) {
    int soma;
    for (int i = 0; i < num; i++) {
        if (num % i == 0) {
            soma++;
        }
    }

    if (soma != num) {
        return false;
    }

    return true;
}


