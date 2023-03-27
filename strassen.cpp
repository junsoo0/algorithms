#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> matrix_t;

int threshold = 1;

matrix_t operator+(matrix_t A, matrix_t B) {
    matrix_t C(A.size(), vector<int>(A.size()));
    for (int i = 0; i < A.size(); i++)
        for (int j = 0; j < A.size(); j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

matrix_t operator-(matrix_t A, matrix_t B) {
    matrix_t C(A.size(), vector<int>(A.size()));
    for (int i = 0; i < A.size(); i++)
        for (int j = 0; j < A.size(); j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

matrix_t operator*(matrix_t A, matrix_t B) {
    matrix_t C(A.size(), vector<int>(A.size()));
    for (int i = 0; i < A.size(); i++)
        for (int j = 0; j < A.size(); j++)
            for (int k = 0; k < A.size(); k++)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

void partition(int m, matrix_t& M, matrix_t& M11, matrix_t& M12, matrix_t& M21, matrix_t& M22) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            M11[i][j] = M[i][j];
            M12[i][j] = M[i][j+m];
            M21[i][j] = M[i+m][j];
            M22[i][j] = M[i+m][j+m];
        }
    }
}

void combine(int m, matrix_t& M, matrix_t& M11, matrix_t& M12, matrix_t& M21, matrix_t& M22) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            M[i][j] = M11[i][j];
            M[i][j+m] = M12[i][j];
            M[i+m][j] = M21[i][j];
            M[i+m][j+m] = M22[i][j];
        }
    }
}

void strassen(int n, matrix_t A, matrix_t B, matrix_t& C) {
    if (n <= threshold) {
        C = A * B;
        return;
    }

    int m = n / 2;
    vector<matrix_t> Ap(4, matrix_t(m, vector<int>(m)));
    vector<matrix_t> Bp(4, matrix_t(m, vector<int>(m)));
    vector<matrix_t> Cp(4, matrix_t(m, vector<int>(m)));
    vector<matrix_t> M(7, matrix_t(m, vector<int>(m)));

    partition(m, A, Ap[0], Ap[1], Ap[2], Ap[3]);
    partition(m, B, Bp[0], Bp[1], Bp[2], Bp[3]);

    strassen(m, Ap[0] + Ap[3], Bp[0] + Bp[3], M[0]);
    strassen(m, Ap[2] + Ap[3], Bp[0], M[1]);
    strassen(m, Ap[0], Bp[1] - Bp[3], M[2]);
    strassen(m, Ap[3], Bp[2] - Bp[0], M[3]);
    strassen(m, Ap[0] + Ap[1], Bp[3], M[4]);
    strassen(m, Ap[2] - Ap[0], Bp[0] + Bp[1], M[5]);
    strassen(m, Ap[1] - Ap[3], Bp[2] + Bp[3], M[6]);

    Cp[0] = M[0] + M[3] - M[4] + M[6];
    Cp[1] = M[2] + M[4];
    Cp[2] = M[1] + M[3];
    Cp[3] = M[0] + M[2] - M[1] + M[5];

    combine(m, C, Cp[0], Cp[1], Cp[2], Cp[3]);
}
