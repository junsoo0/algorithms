#include <vector>

using namespace std;

int fib(int n) { // recursive
    if (n <= 1)
        return n;
    
    return fib(n - 1) + fib(n - 2);
}

long long fib2(int n) { // iterative
    vector<long long> F;

    if (n <= 1)
        return n;
    
    F.push_back(0);
    F.push_back(1);
    for (int i = 2; i <= n; i++)
        F.push_back(F[i - 1] + F[i - 2]);
    return F[n];
}