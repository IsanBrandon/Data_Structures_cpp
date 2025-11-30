#include <iostream>
#include <queue>
using namespace std;

int N, K;
int a[30][30];					// 문제의 격자판 
int dista[30][30];				// BFS로 구한 “시작점에서 각 칸까지의 거리 (년 수)”
int dr[4] = { -1, 1, 0, 0 };	// 상/하/좌/우를 나타내는 델타
int dc[4] = { 0, 0, -1, 1 };

int bfs(int sr, int sc) {
	// (1) 거리 배열 초기화 
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			dista[i][j] = -1;
	// (2) BFS 준비
	queue<pair<int, int>> q;	// BFS용 큐
	dista[sr][sc] = 0;			// 시작점 거리 0
	q.push({ sr, sc });			// 큐에 시작점을 넣고 BFS 시작 
	// (3) BFS 반복 
	while (!q.empty()) {
		auto cur = q.front(); q.pop();		// 큐에서 현재 위치 꺼내기
		int r = cur.first, c = cur.second;	// 현재 위치 행/열
		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d], nc = c + dc[d];
			if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;	// 범위 벗어남
			if (a[nr][nc] == 1) continue;							// 암석에 막힘
			if (dista[nr][nc] != -1) continue;						// 이미 방문함
			dista[nr][nc] = dista[r][c] + 1;						// 새 칸의 거리 = 현재 칸의 거리 + 1
			q.push({ nr, nc });										// 큐에 새 칸 넣고, 그 칸에서도 다시 퍼져나가도록 함 
		}
	}
	// (4) K년 이내에 도달 가능한 빈칸(0)의 개수 세기
	int cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			// 흰 칸이고, 도달한 적 있으며, K년 이내인 경우
			if (a[i][j] == 0 && dista[i][j] != -1 && dista[i][j] <= K)
				cnt++;
	return cnt;
}

int main() {
	freopen("input1.txt", "r", stdin);	// input1.txt 파일에서 입력 받기
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> a[i][j];
	cin >> K;

	int best = -1, br = 0, bc = 0;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			if (a[i][j] == 0) {
				int c = bfs(i, j);
				if (c > best) { best = c; br = i; bc = j; }
			}
	cout << br << " " << bc << "\n" << best << "\n";
	return 0;
}