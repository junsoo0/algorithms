#include <vector>
using namespace std;

void binsearch(int n, vector<int> S, int x, int& location) {
    int low, high, mid;
    low = 1; high = n;
    location = 0;

    while (low <= high) {
        mid = (low + high) / 2;

        if (x == S[mid]) {
            location = mid;
            break;
        }
        
        if (x < S[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
}