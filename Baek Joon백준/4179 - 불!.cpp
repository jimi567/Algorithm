#include <bits/stdc++.h>
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int viaJ[1005][1005];
int viaF[1005][1005];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int r, c;
	cin >> r >> c;

	char arr[r][c];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}
	queue< pair<int, int>> q;
	//불의 초기위치 찾고  bfs 불은 지훈이와 다르게 여러개가 존재함
	pair<int, int> posF;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 'F') {
				q.push({ i,j });
				viaF[i][j] = 1;
			}
		}
	}
	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int px = cur.first + dx[i];
			int py = cur.second + dy[i];
			if (px < 0 || px >= r || py < 0 || py >= c)continue;
			if (arr[px][py] != '.' || viaF[px][py] != 0)continue;
			q.push({ px,py });
			viaF[px][py] = viaF[cur.first][cur.second] + 1;
		}
	}
	pair<int, int> J; //지훈이가 미로를 탈출할때의 좌표중 최단 좌표
	int esct; // 탈출시간 bfs 돌리고 나면 여러 탈출구중 최댓값이 저장됨
	//지훈이 초기위치 찾고 bfs
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 'J') {
				q.push({ i,j });
				viaJ[i][j] = 1;
			}
		}
	}

	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int px = cur.first + dx[i];
			int py = cur.second + dy[i];
			if (px < 0 || px >= r || py < 0 || py >= c)continue;
			if (arr[px][py] != '.' || viaJ[px][py] != 0)continue;
			q.push({ px,py });
			viaJ[px][py] = viaJ[cur.first][cur.second] + 1;
			J = { px,py }; esct = viaJ[px][py];
		}
	}
	//지훈이의 탈출 최단좌표 구하기
	bool canEs = false;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (viaF[i][j] != 0) {
				if (i == 0 && viaJ[i][j] != 0 && viaF[i][j] > viaJ[i][j]) { //맨 윗쪽 탈출구
					if (esct >= viaJ[i][j]) {
						esct = viaJ[i][j]; //최단시간 갱신
						J = { i,j }; //최단좌표 갱신
						canEs = true;
					}
				}
				else if (i == r - 1 && viaJ[i][j] != 0 && viaF[i][j] > viaJ[i][j]) { //맨 아랫쪽 탈출구
					if (esct >= viaJ[i][j]) {
						esct = viaJ[i][j]; //최단시간 갱신
						J = { i,j }; //최단좌표 갱신
						canEs = true;
					}
				}
				else if (j == 0 && viaJ[i][j] != 0 && viaF[i][j] > viaJ[i][j]) { //맨 왼쪽 탈출구
					if (esct >= viaJ[i][j]) {
						esct = viaJ[i][j]; //최단시간 갱신
						J = { i,j }; //최단좌표 갱신
						canEs = true;
					}
				}
				else if (j == c - 1 && viaJ[i][j] != 0 && viaF[i][j] > viaJ[i][j]) { //맨 오른쪽 탈출구
					if (esct >= viaJ[i][j]) {
						esct = viaJ[i][j]; //최단시간 갱신
						J = { i,j }; //최단좌표 갱신
						canEs = true;
					}
				}
			}
			else {//불이없는 경우 혹은 탈출지점에 도달 못하는 경우
				if (i == 0 && viaJ[i][j] != 0) { //맨 윗쪽 탈출구
					if (esct >= viaJ[i][j]) {
						esct = viaJ[i][j]; //최단시간 갱신
						J = { i,j }; //최단좌표 갱신
						canEs = true;
					}
				}
				else if (i == r - 1 && viaJ[i][j] != 0) { //맨 아랫쪽 탈출구
					if (esct >= viaJ[i][j]) {
						esct = viaJ[i][j]; //최단시간 갱신
						J = { i,j }; //최단좌표 갱신
						canEs = true;
					}
				}
				else if (j == 0 && viaJ[i][j] != 0) { //맨 왼쪽 탈출구
					if (esct >= viaJ[i][j]) {
						esct = viaJ[i][j]; //최단시간 갱신
						J = { i,j }; //최단좌표 갱신
						canEs = true;
					}
				}
				else if (j == c - 1 && viaJ[i][j] != 0) { //맨 오른쪽 탈출구
					if (esct >= viaJ[i][j]) {
						esct = viaJ[i][j]; //최단시간 갱신
						J = { i,j }; //최단좌표 갱신
						canEs = true;
					}
				}
			}
		}
	}
	/*cout << J.first << " " << J.second << endl;
	cout << viaJ[J.first][J.second] << " " << viaF[J.first][J.second] << endl;*/

	if (canEs) cout << viaJ[J.first][J.second];
	else cout << "IMPOSSIBLE";
}
