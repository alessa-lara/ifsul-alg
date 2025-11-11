int** createMat(int lin, int col) {
    int** mat = new int*[lin];
    int* data = new int[lin * col];

    for (int i = 0; i < lin; i++) {
        mat[i] = data + (i * col);
    }

    return mat;
}

void freeMat(int** mat) {
    delete mat[0];
    delete mat;
}
