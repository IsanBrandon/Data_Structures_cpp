#include <iostream>
#include <queue>
using namespace std;

int N;
int B[16][16];
bool V[16][16];

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

bool inside(int r, int c) {
    return 0 <= r && r < N && 0 <= c && c < N;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> B[i][j];

    int sr, sc, tr, tc;
    cin >> sr >> sc;
    cin >> tr >> tc;

    // BFS 준비
    queue<pair<int, int>> q;
    V[sr][sc] = true;
    q.push({ sr, sc });

    // BFS 루프 (핵심)
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int r = cur.first;
        int c = cur.second;

        if (r == tr && c == tc) {
            cout << "Yes\n";
            return 0;
        }

        for (int d = 0; d < 4; d++) {   // 한 번의 이동은 “상하좌우 중 한 방향 선택” → 4방향 시도
            int nr = r, nc = c;     // 그 방향으로 쭉 가며 탐색할 포인터
            bool jumped = false;    // 말(1)을 이미 1개 넘었는지 표시 (정확히 1개 규칙)

            while (true) {
                nr += dr[d];                // 한 방향으로 계속 전진
                nc += dc[d];
                if (!inside(nr, nc)) break; // 보드 밖이면 그 방향 탐색 종료

                if (B[nr][nc] == 1) {
                    if (!jumped) jumped = true; // 첫 번째 말이면: “이제부터” 착지 가능한 후보가 생긴다 → jumped=true
                    else break;                 // 두 번째 말이면: 규칙 위반(말 2개 넘기) → 그 방향 종료
                }
                else { // B[nr][nc] == 0
                    if (!jumped) continue;      // 말 넘기 전 빈칸: 착지 불가
                    if (!V[nr][nc]) {           // 말 1개 넘은 뒤의 빈칸: 착지 가능
                        V[nr][nc] = true;
                        q.push({ nr, nc });
                    }
                }
            }
        }
    }

    cout << "No\n";
    return 0;
}
