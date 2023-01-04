#include <bits/stdc++.h>
using namespace std;
int arr[55][55]; // 밭
bool via[55][55]; //지렁이 방문기록
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int loop;
	cin >> loop;
	
	queue<pair<int,int>> q;
	
	while (loop--) {
		int m, n, k;
		cin >> m >> n >> k;
		int ans = 0;
		//밭,방문기록 정보 초기화
		for (int i = 0; i < 55; i++) {
			for (int j = 0; j < 55; j++) {
				arr[i][j] = 0;
				via[i][j] = 0;
			}
		}
		//배추 위치 입력받기
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			arr[x][y] = 1;
		}
		//bfs
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == 1 && via[i][j] == 0) {
					q.push({ i, j });
					via[i][j] = 1;
					while (!q.empty()) {
						pair<int, int> cur = q.front(); q.pop();
						for (int id = 0; id < 4; id++) {
							int px = cur.first + dx[id];
							int py = cur.second + dy[id];
							if (px < 0 || px >= m || py < 0 || py >= n)continue;
							if (arr[px][py] != 1 || via[px][py] != 0)continue;
							q.push({ px,py });
							via[px][py] = 1;
						}
					}
					ans++;
				}
			
			}
		}
		cout << ans << '\n';
		

	}

}
