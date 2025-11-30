#include <iostream>
using namespace std;

int N;
long long K, a[1000];

long long floorRec(int l, int r, long long K) {
    if (l > r) return -1;
    int m = (l + r) / 2;
    if (a[m] > K) return floorRec(l, m - 1, K);
    long long t = floorRec(m + 1, r, K);
    return (t == -1 ? a[m] : t);
}

long long ceilRec(int l, int r, long long K) {
    if (l > r) return -1;
    int m = (l + r) / 2;
    if (a[m] < K) return ceilRec(m + 1, r, K);
    long long t = ceilRec(l, m - 1, K);
    return (t == -1 ? a[m] : t);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];
    cin >> K;
    cout << floorRec(0, N - 1, K) << "\n";
    cout << ceilRec(0, N - 1, K) << "\n";
    return 0;
}
