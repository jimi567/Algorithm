#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define X first
#define Y second
int tc;
int n;
char arr[505][505];
int vis[505][505];
int dx[8] = { 0,1,0,-1,0,0,0,0 };
int dy[8] = { 1,0,-1,0,2,-2,3,-3 };

bool OOB(int x, int y) {
	return x < 0 || y < 0 || x >= n || y >= n;
}
bool chk(int x,int y, int ny) {
	if (y - ny > 0) {
		for (int i = y-1;i > ny;i--) {
			if (arr[x][i] != '.') return 0;
			if (arr[x - 1][i] != '.')return 0;
		}
	}
	else {
		for (int i = y+1;i < ny;i++) {
			if (arr[x][i] != '.') return 0;
			if (arr[x - 1][i] != '.') return 0;
		}
	}
	if (arr[x - 1][ny] != '.' || arr[x - 1][y] != '.') return 0;
	return 1;
}
int main(void) {
	fastIO;
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0;i < n;i++)
			for (int j = 0;j < n;j++) cin >> arr[i][j];
		for (int i = 0;i < n;i++) fill(vis[i], vis[i] + n, 0);
		queue<pair<int, int>> q;
		q.push({ n - 1,0 });
		vis[n - 1][0] = 1;
		while (!q.empty()) {
			auto cur = q.front();q.pop();
			//case - 1
			for (int i = 0;i < 4;i++) {
				int nx = cur.X + dx[i];
				int ny = cur.Y + dy[i];
				if (OOB(nx, ny)) continue;
				if (arr[nx][ny] != 'H' || vis[nx][ny]) continue;
				vis[nx][ny] = vis[cur.X][cur.Y] + 1;
				q.push({ nx,ny });
			}
			//case - 2
			for (int i = 4;i < 8;i++) {
				int nx = cur.X + dx[i];
				int ny = cur.Y + dy[i];
				if (OOB(nx, ny) || OOB(nx-1,ny)) continue;
				if (arr[nx][ny] != 'H' || vis[nx][ny]) continue;
				if(!chk(cur.X, cur.Y, ny)) continue;
				vis[nx][ny] = vis[cur.X][cur.Y] + 1;
				q.push({ nx,ny });
			}
			//case - 3
			if (!OOB(cur.X - 2, cur.Y)) {
				if (arr[cur.X - 1][cur.Y] == '.' && arr[cur.X - 2][cur.Y] == 'H' && vis[cur.X-2][cur.Y] == 0) {
					vis[cur.X - 2][cur.Y] = vis[cur.X][cur.Y] + 1;
						q.push({cur.X - 2, cur.Y});
				}
			}
			//case - 4
			if (!OOB(cur.X -1,cur.Y - 1)) {
				if (arr[cur.X-1][cur.Y] == '.' && arr[cur.X][cur.Y - 1] == '.' && arr[cur.X -1][cur.Y - 1] == 'H' && vis[cur.X-1][cur.Y-1] == 0) {
					vis[cur.X -1][cur.Y - 1] = vis[cur.X][cur.Y] + 1;
						q.push({cur.X-1,cur.Y-1});
				}
			}
			//case - 5
			if (!OOB(cur.X - 1, cur.Y + 1)) {
				if (arr[cur.X - 1][cur.Y] == '.' && arr[cur.X][cur.Y + 1] == '.' && arr[cur.X - 1][cur.Y + 1] == 'H' && vis[cur.X-1][cur.Y+1] ==0) {
					vis[cur.X - 1][cur.Y + 1] = vis[cur.X][cur.Y] + 1;
					q.push({ cur.X - 1,cur.Y + 1 });
				}
			}
		}
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				if (arr[i][j] == 'H' && vis[i][j] == 0) vis[i][j] = -1;
			}
		}
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				cout << vis[i][j] << ' ';
			}
			cout << endl;
		}

	}
}
