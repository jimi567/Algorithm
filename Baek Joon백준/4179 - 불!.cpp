//내가 푼 방식
//불 bfs 지훈 bfs 실행 후 지훈이의 최단탈출 좌표를 따로 
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
//좋은 풀이 방식
// 각 큐에 지훈,불의 시작지점을 동시에 받아내고 
// 불의 bfs 실행후 지훈이의 bfs중 불의 전파속도보다 작은 곳만 이동하게 추가 조건문을 넣음, 그리고 만약 px py가 범위를 탈출했을 경우는 
// 탈출 성공한것이므로 바로 결과를 출력해주고 메인함수를 끝냄, 만약  지훈이 bfs가 다끝나도 메인함수가 끝나지않는다는건 탈출불가라는 뜻
#include <bits/stdc++.h>
using namespace std;
string arr[1005]; // 미로 배열
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int viaJ[1005][1005]; // 지훈이의 이동 시간
int viaF[1005][1005]; // 불의 전파 시간
int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int r, c;
	cin >> r >> c;
	//맵의 정보 입력받기
	for (int i = 0; i < r; i++) {
		cin >> arr[i];
	}
	queue <pair<int, int>> q1; // 지훈이 bfs용 큐
	queue <pair<int, int>>  q2;// 불 bfs용 큐
	//각 큐에 지훈이와 불의 시작지점 푸쉬하고 via에 표시
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 'J') {
				q1.push({ i,j });
				viaJ[i][j] = 1;
			}
			if (arr[i][j] == 'F') {
				q2.push({ i,j });
				viaF[i][j] = 1;
			}
		}
	}
	//불의 bfs
	while (!q2.empty()) {
		auto cur = q2.front(); q2.pop();
		for (int i = 0; i < 4; i++) {
			int px = cur.first + dx[i];
			int py = cur.second + dy[i];
			if (px < 0 || px >= r || py < 0 || py >= c)continue;
			if (viaF[px][py] != 0 || arr[px][py] != '.')continue; //이미 방문했거나 .이 아닌경우( 지날수없는 벽일 경우)
			q2.push({ px,py });
			viaF[px][py] = viaF[cur.first][cur.second] + 1;
		}
	}
	//지훈 bfs
	while (!q1.empty()) {
		auto cur = q1.front(); q1.pop();
		for (int i = 0; i < 4; i++) {
			int px = cur.first + dx[i];
			int py = cur.second + dy[i];
			if (px < 0 || px >= r || py < 0 || py >= c) {//범위를 벗어나면 탈출 성공
				cout << viaJ[cur.first][cur.second];
				return 0;
			}
			if (viaJ[px][py] != 0 || arr[px][py] != '.') continue;
			if (viaF[px][py] != 0 && viaJ[cur.first][cur.second] + 1 >= viaF[px][py]) continue; //지훈이의 도달 시간이 불의 전파속도보다 크거나 같으면 못지나가는곳임
			q1.push({ px,py });
			viaJ[px][py] = viaJ[cur.first][cur.second] + 1;

		}
	}
	cout << "IMPOSSIBLE"; //탈출 성공을 못하고 bfs가 끝나면 탈출못하는 미로
}

