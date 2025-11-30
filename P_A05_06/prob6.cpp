#include <iostream>
#include <string>
using namespace std;

string S, cur;
int N, K;

void gen(int idx, int diff) {
    if (diff > K) return;
    if (idx == N) {
        if (diff == K) cout << cur << "\n";
        return;
    }
    cur[idx] = '0';
    gen(idx + 1, diff + (S[idx] != '0'));
    cur[idx] = '1';
    gen(idx + 1, diff + (S[idx] != '1'));
}

int main() {
    cin >> S >> K;
    N = S.size();
    cur.assign(N, '0');
    gen(0, 0);
    return 0;
}
