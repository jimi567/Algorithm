#include<bits/stdc++.h>
using namespace std;
int m, n, k;
int area[105][105];
bool vis[105][105];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> m >> n >> k;



	for (int i = 0; i < k; i++) {
		pair<int, int> st;
		pair<int, int> ed;
		cin >> st.first >> st.second >> ed.first >> ed.second;
		for (int y = 0; y < m; y++) {
			for (int x = 0; x < n; x++) {
				if (x >= st.first && x < ed.first && y >= st.second && y < ed.second) area[y][x] = 1;
			}
		}
	}

	queue<pair<int, int>> q;
	int areaCnt = 0;
	vector<int> ans;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (area[i][j] == 0 && vis[i][j] != 1) {
				int cnt = 1;
				q.push({ i,j });
				vis[i][j] = 1;
				while (!q.empty()) {
					pair<int, int> cur = q.front(); q.pop();
					for (int idx = 0; idx < 4; idx++) {
						int nx = cur.first + dx[idx];
						int ny = cur.second + dy[idx];
						if (nx < 0 || nx >= m || ny < 0 || ny >= n)continue;
						if (area[nx][ny] == 1 || vis[nx][ny] == 1) continue;
						q.push({ nx,ny });
						vis[nx][ny] = 1;
						cnt++;
					}
				}
				ans.push_back(cnt);
				areaCnt++;
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << areaCnt << '\n';
	for (auto i : ans) cout << i << ' ';
}
