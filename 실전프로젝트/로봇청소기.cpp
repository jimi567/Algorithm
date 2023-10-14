#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define X first
#define Y second
int tc;

//북 동 남 서
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int arr[55][55];
bool vis[55][55];
int n;
int dir;
int x, y;

void run() {
	int cnt = 0;
	while (1) {
		if (!vis[x][y]) cnt++;
		vis[x][y] = 1;
		while (1) {
			bool cleanup = 0;
			for (int i = 0; i < 4; i++) {
				dir = (dir + 3) % 4;
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (vis[nx][ny] || arr[nx][ny]) continue;
				x = nx;
				y = ny;
				cleanup = 1;
				break;
			}
			if (cleanup) break;
			x += dx[(dir + 2) % 4];
			y += dy[(dir + 2) % 4];
			if (!arr[x][y]) break;
			cout << cnt << endl;
			return;
		}
	}
}
int main(void) {
	fastIO;
	cin >> tc;
	while (tc--) {
		cin >> n >> dir >> x >> y;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) cin >> arr[i][j];
		for (int i = 0; i < n; i++) fill(vis[i], vis[i] + n, 0);
		run();
	}
}
