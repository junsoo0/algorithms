#include <iostream>
using namespace std;

void collatz(int n) {
    while (1) {
        cout << n << ' ';
        if (n == 1) break;
        if (n % 2 == 0) n /= 2;
        else n = n * 3 + 1;
    }
}
