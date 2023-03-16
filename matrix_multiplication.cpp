#include <vector>
using namespace std;

typedef vector<vector<int>> matrix_t;

void matrixmult(int n, matrix_t& A, matrix_t& B, matrix_t& C) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            C[i][j] = 0;
            for (int k = 1; k <= n; k++)
                C[i][j] += (A[i][k] * B[k][j]);
        }
    }
}
