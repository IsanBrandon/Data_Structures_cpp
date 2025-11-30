#include <iostream>
using namespace std;

int N, a[16][16];
bool vis[16][16];
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };

long long dfs(int r, int c) {
    if (r == N - 1 && c == N - 1) return 1;
    vis[r][c] = true;
    long long cnt = 0;
    for (int d = 0; d < 4; d++) {
        int nr = r + dr[d], nc = c + dc[d];
        if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
        if (a[nr][nc] == 1 || vis[nr][nc]) continue;
        cnt += dfs(nr, nc);
    }
    vis[r][c] = false;
    return cnt;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> a[i][j];
    long long ans = 0;
    if (a[0][0] == 0 && a[N - 1][N - 1] == 0) ans = dfs(0, 0);
    cout << ans << "\n";
    return 0;
}
