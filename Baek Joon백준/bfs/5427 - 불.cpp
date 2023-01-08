#include<bits/stdc++.h>
using namespace std;
//[h][w] -> nx,ny
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
string area[1005];
int vis[1005][1005];
int visF[1005][1005];
bool OutOfRange(int w, int h, int nx, int ny) {
	if (nx < 0 || nx >= h || ny < 0 || ny >= w) return true;
	else return false;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int loop;
	cin >> loop;
	while (loop--) {
		int w, h;
		cin >> w >> h;
		for (int i = 0; i < h; i++) {
			cin >> area[i];
			fill(vis[i], vis[i] + w, -1);
			fill(visF[i], visF[i] + w, -1);
		}
		queue<pair<int, int>> q;
		//불의 시작위치 넣기
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (area[i][j] == '*') {
					q.push({ i, j });
					visF[i][j] = 0;
				}
			}
		}
		//불 bfs
		while (!q.empty()) {
			pair<int, int> cur = q.front(); q.pop();
			for (int idx = 0; idx < 4; idx++) {
				int nx = cur.first + dx[idx];
				int ny = cur.second + dy[idx];
				if (OutOfRange(w, h, nx, ny)) continue;
				if (area[nx][ny] == '#' || visF[nx][ny] != -1) continue;
				q.push({ nx,ny });
				visF[nx][ny] = visF[cur.first][cur.second] + 1;
			}
		}
		//상근이 시작위치 큐에 푸쉬
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (area[i][j] == '@') {
					q.push({ i, j });
					vis[i][j] = 0;
				}
			}
		}
		int time = -1;
		int can = false; //탈출가능? 불가능?
		while (!q.empty()) {
			pair<int, int> cur = q.front(); q.pop();
			for (int idx = 0; idx < 4; idx++) {
				int nx = cur.first + dx[idx];
				int ny = cur.second + dy[idx];
				if (OutOfRange(w, h, nx, ny)) {
					if (time == -1) {
						time = vis[cur.first][cur.second] + 1;
						can = true;
					}
					continue;
				}
				if (area[nx][ny] != '.' || vis[nx][ny] != -1 )continue;
				//nx ny에 불이 왔다 && 현재 상근이 위치에서 1 더한 시간이 불이 도착한 시간보다 같거나 크면 continue 
				if (visF[nx][ny] != -1 && vis[cur.first][cur.second] + 1 >= visF[nx][ny]) continue;
				q.push({ nx,ny });
				vis[nx][ny] = vis[cur.first][cur.second] + 1;

			}
		}
		if (!can) cout << "IMPOSSIBLE" << '\n';
		else cout << time << '\n';
	}
}
