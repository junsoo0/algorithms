def collatz(n):
    while (1):
        print(n, end=' ')
        if (n == 1): break
        if (n % 2 == 0): n = (int)(n / 2)
        else: n = n * 3 + 1
