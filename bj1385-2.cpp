#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int board[2001][2001], dist[2001][2001];

int main() {
	fastio;
	memset(board, -1, sizeof(board));
	memset(dist, -1, sizeof(dist));
	int cx = 0, cy = 0, cnt = 0;
	while (++cnt <= 1000000) {
		board[cx + 1000][cy + 1000] = cnt;
		if (cx + cy <= 0 && cy >= 0) cy++;
		else if (cx + cy >= 0 && cx < 0) cx++;
		else if (cx >= 0 && cy > 0) cx++, cy--;
		else if (cx + cy > 0 && cy <= 0) cy--;
		else if (cx + cy <= 0 && cx > 0) cx--;
		else if (cx <= 0 && cy < 0) cx--, cy++;
	}
	int st, en; cin >> st >> en;
	int sx, sy, ex, ey;
	for (int i = 0; i <= 2000; i++) for (int j = 0; j <= 2000; j++) {
		if (board[i][j] == st) sx = i - 1000, sy = j - 1000;
		if (board[i][j] == en) ex = i - 1000, ey = j - 1000;
	}
	queue<pair<int, int>> Q;
	dist[sx + 1000][sy + 1000] = 0;
	Q.push({ sx, sy });
	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		if (board[x + 1000][y + 1000] == en) break;
		for (int k = 0; k < 6; k++) {
			int nx = x + "100122"[k] - '1';
			int ny = y + "221001"[k] - '1';
			if (board[nx + 1000][ny + 1000] == -1 || dist[nx + 1000][ny + 1000] != -1) continue;
			dist[nx + 1000][ny + 1000] = dist[x + 1000][y + 1000] + 1;
			Q.push({ nx, ny });
		}
	}
	vector<int> ans{ en };
	while (board[ex + 1000][ey + 1000] != st) {
		for (int k = 0; k < 6; k++) {
			int nx = ex + "100122"[k] - '1';
			int ny = ey + "221001"[k] - '1';
			if (board[nx + 1000][ny + 1000] == -1 || dist[nx + 1000][ny + 1000] == -1 || dist[nx + 1000][ny + 1000] >= dist[ex + 1000][ey + 1000]) continue;
			ex = nx, ey = ny;
			break;
		}
		ans.push_back(board[ex + 1000][ey + 1000]);
	}
	for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << ' '; cout << '\n';
}

