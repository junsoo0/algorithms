def fib(n): # recursive
    if n <= 1:
        return n
    return fib(n - 1) + fib(n - 2)

def fib2(n): # iterative
    if n <= 1:
        return n
    
    F = [0, 1]
    for i in range(2, n + 1):
        F.append(F[i - 1] + F[i - 2])
    return F[n]
