threshold = 1

def madd(A, B):
    n = len(A)
    C = [0] * n
    for i in range(n):
        C[i] = list(map(lambda a, b: a+b, A[i], B[i]));
    return C

def msub(A, B):
    n = len(A)
    C = [0] * n
    for i in range(n):
        C[i] = list(map(lambda a, b: a-b, A[i], B[i]));
    return C

def mmul(A, B):
    n = len(A)
    C = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            for k in range(n):
                C[i][j] += A[i][k] * B[k][j]
    return C

def partition(m, li):
    r11 = [0] * m
    r12 = [0] * m
    r21 = [0] * m
    r22 = [0] * m

    for i in range(m):
        r11[i] = li[i][:m]
        r12[i] = li[i][m:]
        r21[i] = li[i+m][:m]
        r22[i] = li[i+m][m:]
        
    return r11, r12, r21, r22

def combine(m, li11, li12, li21, li22):
    r = [0] * 2 * m
    for i in range(m):
        r[i] = li11[i] + li12[i]
        r[i+m] = li21[i] + li22[i]
    return r

def strassen(n, A, B):
    if (n <= threshold):
        return mmul(A, B)

    m = n // 2
    A11, A12, A21, A22 = partition(m, A)
    B11, B12, B21, B22 = partition(m, B)

    M1 = strassen(m, madd(A11, A22), madd(B11, B22))
    M2 = strassen(m, madd(A21, A22), B11)
    M3 = strassen(m, A11, msub(B12, B22))
    M4 = strassen(m, A22, msub(B21, B11))
    M5 = strassen(m, madd(A11, A12), B22)
    M6 = strassen(m, msub(A21, A11), madd(B11, B12))
    M7 = strassen(m, msub(A12, A22), madd(B21, B22))

    C11 = madd(msub(madd(M1, M4), M5), M7)
    C12 = madd(M3, M5)
    C21 = madd(M2, M4)
    C22 = madd(msub(madd(M1, M3), M2), M6)

    return combine(m, C11, C12, C21, C22)
