#include<bits/stdc++.h>
using namespace std;
string area[31][31];
int vis[31][31][31];
int dx[6] = { 0,-1,1,0,0,0 };
int dy[6] = { 1,0,0,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
int L,R, C;

int main() {
	ios::sync_with_stdio(false), cin.tie(0);

	while (1) {
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) break;

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				cin >> area[i][j];
				fill(vis[i][j], vis[i][j] + C, 0);
			}
		}
		tuple<int, int, int> target;
		queue<tuple<int, int, int>> q;
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					if (area[i][j][k] == 'S') {
						q.push({ i,j,k });
						vis[i][j][k] = 1;
					}
				}
			}
		}
		int ans = -1;
		while (!q.empty()) {
			tuple<int, int, int> cur = q.front(); q.pop();
			if (area[get<0>(cur)][get<1>(cur)][get<2>(cur)] == 'E') ans = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)]; 
			for (int idx = 0; idx < 6; idx++) {
				int nz = get<0>(cur) + dz[idx];
				int ny = get<1>(cur) + dy[idx];
				int nx = get<2>(cur) + dx[idx];

				if (nz < 0 || ny < 0 || nx < 0 || nz >= L || ny >= R || nx >= C)continue;
				if (area[nz][ny][nx] == '#' || vis[nz][ny][nx] != 0)continue;
				q.push({ nz,ny,nx });
				vis[nz][ny][nx] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
				
			}
		}
		if (ans == -1) cout << "Trapped!" << '\n';
		else cout << "Escaped in " << ans-1 << " minute(s)." << '\n'; //vis 시작점이 1이라서 -1
	}
}
