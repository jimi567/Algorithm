//bfs
#include<bits/stdc++.h>
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int main() {
	ios::sync_with_stdio(false),cin.tie(0);
	int n, m;
	cin >> n >> m;
	char arr[n][m];
	for (int i = 0; i < n; i++) {
			cin >> arr[i]; //입력이 붙어서 들어오니깐 string이 들어옴
	}
	int via[n][m]; //시작점에서 떨어진 거리 저장
	for (int i = 0; i < n; i++) fill(via[i], via[i] + m, 0); //0으로 초기화
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	via[0][0] = 1;

	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int px = cur.first + dx[i];
			int py = cur.second + dy[i];
			if (px < 0 || px >= n || py < 0 || py >= m) continue;
			if (arr[px][py] == '0' || via[px][py] != 0) continue; //이미 방문했거나, 맵에서 1이 아닐때
			via[px][py] = via[cur.first][cur.second] + 1;
			q.push({ px,py });
		}
	}

	cout << via[n - 1][m - 1];
}
