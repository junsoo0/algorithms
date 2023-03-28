#include <vector>
using namespace std;
typedef vector<vector<int>> matrix_t;

matrix_t b;
int cnt;

int whereis(int n, pair<int, int> s, pair<int, int> h) {
    int q;
    int m = n / 2;

    if (h.first - s.first < m)
        if (h.second - s.second < m) q = 1;
        else q = 2;
    else
        if (h.second - s.second < m) q = 3;
        else q = 4;
    
    return q;
}

void fill(pair<int, int> s, int q) {
    cnt++;
    if (q != 1) b[s.first][s.second] = cnt;
    if (q != 2) b[s.first][s.second+1] = cnt;
    if (q != 3) b[s.first+1][s.second] = cnt;
    if (q != 4) b[s.first+1][s.second+1] = cnt;
}

pair<int, int> hole(int n, pair<int, int> s, pair<int, int> h, int q, int w) {
    if (q == w)
        return h;
    
    int m = n / 2;
    pair<int, int> t = s;
  
    t.first += m - 1;
    t.second += m - 1;
    if (q == 2 || q == 4) t.second++;
    if (q == 3 || q == 4) t.first++;

    return t;
}

void tromino(int n, pair<int, int> s, pair<int, int> h) {
    int q = whereis(n, s, h);
    if (n == 2) {
        fill(s, q);
        return;
    }

    int m = n / 2;
    pair<int, int> t;
 
    fill({s.first + m - 1, s.second + m - 1}, q);
    t = hole(n, s, h, q, 1);
    tromino(m, s, t);
    t = hole(n, s, h, q, 2);
    tromino(m, {s.first, s.second+m}, t);
    t = hole(n, s, h, q, 3);
    tromino(m, {s.first+m, s.second}, t);
    t = hole(n, s, h, q, 4);
    tromino(m, {s.first+m, s.second+m}, t);
}
