#include <iostream>
using namespace std;

int dfs_component(int N, int img[50][50], bool vis[50][50], int sr, int sc) {
    const int dy[8] = { -1,-1,-1,0,0,1,1,1 };
    const int dx[8] = { -1,0,1,-1,1,-1,0,1 };

    int sy[2500], sx[2500]    // 스택에 들어갈 좌표들을 각각 저장하는 배열
		, top = 0;            // 스택 크기(다음 삽입 위치)
    int cnt = 0;              // 컴포넌트 크기(방문한 1의 개수)

    vis[sr][sc] = true;
    sy[top] = sr; sx[top] = sc; top++;                     

    while (top > 0) {
        top--;
        int y = sy[top], x = sx[top];
        cnt++;

        for (int k = 0; k < 8; k++) {
            int ny = y + dy[k], nx = x + dx[k];

            if (0 <= ny && ny < N && 0 <= nx && nx < N &&
                img[ny][nx] == 1 && !vis[ny][nx]) {
                vis[ny][nx] = true;
                sy[top] = ny; sx[top] = nx; top++;
            }
        }
    }
    return cnt;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        int img[50][50];
        bool vis[50][50] = { 0 };

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> img[i][j];

        bool first = true;

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (img[r][c] == 1 && !vis[r][c]) {
                    int cnt = dfs_component(N, img, vis, r, c);
                    if (!first) cout << ' ';
                    cout << cnt;
                    first = false;
                }
            }
        }
        cout << '\n';
    }
    return 0;
}
