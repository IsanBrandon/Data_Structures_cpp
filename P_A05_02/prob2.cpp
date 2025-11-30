#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int N, a[20][20];
int dr[4] = { -1, 1, 0, 0 }; // 위, 아래, 왼, 오른  
int dc[4] = { 0, 0, -1, 1 };
int dista[20][20][4]; // dista[r][c][d]: (r,c)에 방향 d로 도착했을 때의 최소 꺾임 수
const int INF = 1e9;

int main() {

	freopen("input2.txt", "r", stdin);				// input2.txt 파일에서 입력 받기

	// (1) 입력 및 초기화
	cin >> N;
	for (int i=0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> a[i][j];

	if (N == 1) { cout << 0 << "\n"; return 0; }	// 예외처리: 시작점이 곧 도착점인 경우

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int d = 0; d < 4; d++)
				dista[i][j][d] = INF;				// 나중에 실제로 방문하면서 최소값으로 갱신될 것임

	// (2) 시작 상태를 덱에 넣기
	deque<pair<pair<int, int>, int>> dq;

	for (int d = 0; d < 4; d++) {					// 첫 이동: (0,0)에서 한 칸 이동은 꺾임이 없음
		int nr = 0 + dr[d], nc = 0 + dc[d];
		if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
		if (a[nr][nc] == 1) continue;
		dista[nr][nc][d] = 0;						// 첫 이동은 꺾임 0
		dq.push_back({ {nr,nc}, d });				// 초기	상태 덱에 넣기
	}
	 
	// (3) 0-1 BFS 
	while (!dq.empty()) {
		auto cur = dq.front(); dq.pop_front();
		int r = cur.first.first, c = cur.first.second, dir = cur.second;	// 현재 위치와 방향
		int curCost = dista[r][c][dir];										// 현재 위치까지의 꺾임 수

		for (int nd = 0; nd < 4; nd++) {
			int nr = r + dr[nd], nc = c + dc[nd];
			if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;			// 범위 벗어남
			if (a[nr][nc] == 1) continue;									// 암석에 막힘

			int add = (nd == dir) ? 0 : 1;									// 방향이 같으면 꺾임 없음, 다르면 꺾임 1
			int nCost = curCost + add;										// 지금까지 꺾임 수 + 이번 이동에서의 꺾임 수

			if (nCost < dista[nr][nc][nd]) {					// 만약 지금 구한 nCost(비용)이 기존에 기록된 비용보다 작으면 
				dista[nr][nc][nd] = nCost;						// 최소 꺾임 수 갱신 그리고 이 새 상태를 덱에 넣기						
				if (add == 0) dq.push_front({ {nr, nc},nd });	// (방향 유지, 비용 0)이면 우선순위를 높여 먼저 처리되도록
				else		  dq.push_back({ {nr, nc},nd });
				// 꺾임이 적게 든 경로들이 큐 앞쪽에서 먼저, 많이 든 경로들은 뒤쪽에서 처리되면서 최소 꺾임 수가 잘 보장됨 
			}
		}
	}
	// (4) 도착점(N-1, N-1)에 도달하는 최소 꺾임 수 구하기
	int ans = INF;
	for (int d = 0; d < 4; d++)
		ans = min(ans, dista[N - 1][N - 1][d]);	// 목적지는 (N-1, N-1)이고, 거기에 도착했을 때의 방향은 상하좌우 무엇이든 상관 없음
	if (ans == INF) ans = -1;					// 한 번도 도달 못했다면 여전히 INF → 도달 불가 → -1
	cout << ans << "\n";
}  