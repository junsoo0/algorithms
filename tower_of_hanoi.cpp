#include <iostream>
using namespace std;

void hanoi(int n, char src, char via, char dst) {
    if (n == 1) cout << src << " -> " << dst << '\n';
    else {
        hanoi(n - 1, src, dst, via);
        hanoi(1, src, via, dst);
        hanoi(n - 1, via, src, dst);
    }
}
