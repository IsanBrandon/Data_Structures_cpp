#include <iostream>
#include <queue>
using namespace std;

int N, B[16][16];
bool V[16][16];
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };

bool in(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < N;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> B[i][j];

    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    queue<pair<int, int>> q;
    V[sx][sy] = true;
    q.push({ sx,sy });

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int r = cur.first, c = cur.second;
        if (r == tx && c == ty) {
            cout << "Yes";
            return 0;
        }

        for (int d = 0; d < 4; d++) {
            int nr = r, nc = c;
            bool jumped = false;

            while (true) {
                nr += dr[d];
                nc += dc[d];
                if (!in(nr, nc)) break;

                if (B[nr][nc] == 1) {
                    if (!jumped) { jumped = true; continue; }
                    else break;
                }
                else { // ºóÄ­
                    if (!jumped) continue;
                    if (!V[nr][nc]) {
                        V[nr][nc] = true;
                        q.push({ nr,nc });
                    }
                }
            }
        }
    }

    cout << "No";
    return 0;
}
