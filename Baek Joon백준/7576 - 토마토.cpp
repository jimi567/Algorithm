#include<bits/stdc++.h>
using namespace std;
int via[1005][1005];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int main() {
	ios::sync_with_stdio(false),cin.tie(0);
	int m, n;
	cin >> m >> n;
	int arr[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			via[i][j] = -1;
		}
	}
	queue<pair<int, int>> q;
	//시작점 넣기 토마토가 익은 좌표를 모두 큐에 넣고 시작
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1 && via[i][j] == -1) {
				q.push({ i,j });
				via[i][j] = 0;
			}
		}
	}
	int day = 0;// 마지막 안익은 토마토가 익은 날짜
	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int px = cur.first + dx[i];
			int py = cur.second + dy[i];
			if (px < 0 || px >= n || py < 0 || py >= m) continue;
			if (arr[px][py] == 0 && via[px][py] == -1) {
				via[px][py] = via[cur.first][cur.second] + 1;
				day = via[px][py];
				arr[px][py] = 1;
				q.push({ px,py });
			}
		}

	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0)day = -1;
		}
	}
	cout << day;
}
