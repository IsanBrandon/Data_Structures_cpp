#include <iostream>
#include <fstream>
using namespace std;

int N, a[16][16];
bool vis[16][16];				// 현재 경로에서 이미 밟았던 칸인지 표시
int dr[4] = { -1, 1, 0, 0 };	// 위, 아래, 왼, 오른
int dc[4] = { 0, 0, -1, 1 };

int dfs(int r, int c) {
	if (r == N - 1 && c == N - 1) return 1;	// base case: 현재 위치가 (N-1,N-1)이면 경로 1개 완성

	vis[r][c] = true;						// 현재 칸은 지금 경로에서 방문했다고 표시 
	int cnt = 0;

	for (int d = 0; d < 4; d++) {
		int nr = r + dr[d], nc = c + dc[d];
		if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;	// 범위 밖
		if (a[nr][nc] == 1 || vis[nr][nc]) continue;			// 벽이거나 이미 방문한 칸 
		cnt += dfs(nr, nc);
	}

	vis[r][c] = false;						// 백트래킹: 현재 칸을 다시 미방문 상태로 되돌려 놓기
	// 한 경로에서는 같은 칸을 두 번 방문하면 안 되지만, 다른 경로에서는 같은 칸을 다시 밟을 수 있어야
	return cnt;
}

int main() {
	ifstream fin("input.txt");   // input.txt 파일에서 입력 받는다고 가정

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> a[i][j];

	int ans = 0;
	if (a[0][0] == 0 && a[N - 1][N - 1] == 0) ans = dfs(0, 0);

	cout << ans << "\n";
	return 0;
}