#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_SIZE = 100;
int maze[MAX_SIZE][MAX_SIZE];
int n;

int main() {
	read_maze();
	queue<pair<int, int>> que;
	pair<int, int> cur(0, 0);
	maze[cur.first][cur.second] = -1; // 방문 표시
	que.push(cur);

	while (!que.empty()) {
		cur = que.front();
		que.pop();
		for (int dir = 0; dir < 4; dir++) {
			if (movable(cur, dir)) {
				pair<int, int> p = move_to(cur, dir);
				maze[p.first][p.second] = maze[cur.first][cur.second] - 1; // 방문 표시
				if (p.first == n-1 && p.second == n - 1) {
					cout << "Found the path." << endl;
					print_maze();
					return 0;
				}
				que.push(p);
			}
		}
	}
	cout << "No path found." << endl;
	return 0;
}