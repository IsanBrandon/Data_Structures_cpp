#include <cstdio>
#include <iostream>
using namespace std;

struct P { int y, x; };

class Stack {
    P* a; int topIdx, cap;
public:
    Stack(int n) : a(new P[n]), topIdx(0), cap(n) {}
    ~Stack() { delete[] a; }
    void push(P v) { a[topIdx++] = v; }
    P pop() { return a[--topIdx]; }
    bool empty() const { return topIdx == 0; }
};

int main() {
    freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; if (!(cin >> T)) return 0;
    const int dy[8] = { -1,-1,-1,0,0,1,1,1 };
    const int dx[8] = { -1,0,1,-1,1,-1,0,1 };

    while (T--) {
        int N; cin >> N;
        int NN = N * N;

        // 평면 배열로 저장(최소 메모리/연산)
        int* img = new int[NN];
        char* vis = new char[NN](); // 0으로 초기화

        for (int i = 0; i < NN; i++) cin >> img[i];

        Stack st(NN);
        bool first = true;

        for (int r = 0; r < N; r++) for (int c = 0; c < N; c++) {
            int idx = r * N + c;
            if (img[idx] == 1 && !vis[idx]) {
                int cnt = 0;
                vis[idx] = 1; st.push({ r,c });
                while (!st.empty()) {
                    P p = st.pop(); cnt++;
                    for (int k = 0; k < 8; k++) {
                        int ny = p.y + dy[k], nx = p.x + dx[k];
                        if (0 <= ny && ny < N && 0 <= nx && nx < N) {
                            int j = ny * N + nx;
                            if (img[j] == 1 && !vis[j]) {
                                vis[j] = 1; st.push({ ny,nx });
                            }
                        }
                    }
                }
                if (!first) cout << ' ';
                cout << cnt; first = false;
            }
        }
        cout << '\n';

        delete[] vis; delete[] img;
    }
    return 0;
}
