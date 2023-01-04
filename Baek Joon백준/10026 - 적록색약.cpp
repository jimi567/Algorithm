//내가 푼 방식 
//일반적인 눈을 가진사람이 보는 그림의 갯수 구하고 방문기록 초기화한 다음에 
//G을 R로 바꾼다음에 다시 bfs돌려 적록색약이 보는 그림 갯수 구해줌
#include <bits/stdc++.h>
using namespace std;
string arr[105]; // 그림판 
bool via[105][105]; //방문기록
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	char c[3] = { 'R','G','B' };
	int count[3] = { 0,0,0 }; // R G B 그림의 갯수

	//적록색약 아닌사람
	for (int id = 0; id < 3;id++) {
		int colorDr = 0; //해당 색깔 그림의 갯수
		queue<pair<int, int>> q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == c[id] && via[i][j] == 0) {
					q.push({ i,j });
					via[i][j] = 1;
					while (!q.empty()) {
						pair<int, int> cur = q.front(); q.pop();
						for (int idx = 0; idx < 4; idx++) {
							int px = cur.first + dx[idx];
							int py = cur.second + dy[idx];
							if (px < 0 || px >= n || py < 0 || py >= n)continue;
							if (arr[px][py] != c[id] || via[px][py] != 0)continue;
							q.push({ px,py });
							via[px][py] = 1;
						}
					}
					colorDr++;
				}
			}
		}
		count[id] = colorDr;
	}
	//평범한 사람이 보는 그림의 수 출력
	int normalEye = 0;
	for (int i = 0; i < 3; i++) normalEye += count[i];
	cout << normalEye << " ";
	for (int i = 0; i < n; i++) fill(via[i], via[i] + n, 0); //방문기록 초기화
	//적록색약이 보는 그림의 수 구하기
	//적록색약이니깐 G색을 R로 바꾸기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 'G') arr[i][j] = 'R';
		}
	}
	//적록색약 버전
	int c2[2] = { 'R','B' };
	int count2[2]= { 0,0 };
	
	for (int id = 0; id < 2; id++) {
		int cdr = 0;//해당 색의 그림의 수
		queue<pair<int, int>> q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == c2[id] && via[i][j] == 0) {
					q.push({ i,j });
					via[i][j] = 1;
					while (!q.empty()) {
						pair<int, int> cur = q.front(); q.pop();
						for (int idx = 0; idx < 4; idx++) {
							int px = cur.first + dx[idx];
							int py = cur.second + dy[idx];
							if (px < 0 || px >= n || py < 0 || py >= n)continue;
							if (arr[px][py] != c2[id] || via[px][py] != 0)continue;
							q.push({ px,py });
							via[px][py] = 1;
						}
					}
					cdr++;
				}
			}
		}
		count2[id] = cdr;
	}
	//적록색약 사람이 보는 그림의 수 출력
	int ProEye = 0;
	for (int i = 0; i < 2; i++) ProEye += count2[i];
	cout << ProEye << " ";

}
//풀이 방식은 똑같음 하지만 bfs코드가 두번겹치니깐 그걸 함수화 시켜서 효율적인 코드를 짬
// Authored by : seeys
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/99a676d859f54fa0944f81f94ade04a3
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
char board[101][101];
bool vis[101][101];
int n;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; 

void bfs(int i, int j) {
  queue<pair<int, int>> Q;
  Q.push({ i,j });
  vis[i][j] = 1;
  while (!Q.empty()) {
    auto cur = Q.front(); Q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if (vis[nx][ny] == 1 || board[i][j] != board[nx][ny]) continue;
      vis[nx][ny] = 1;
      Q.push({ nx,ny });
    }
  }
}

int area(){
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!vis[i][j]) {
        cnt++;
        bfs(i, j);
      }
    }
  }
  return cnt;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }
  int not_g = area(); //적록색약이 아닌사람

  // 적록색약인 사람을 구하기위한 방문배열 초기화
  for(int i = 0; i < n; i++)
    fill(vis[i], vis[i]+n, false);
  
  // 적록색약은 초록과 빨강을 구분 못하므로 초록이면 빨강으로 바꿔줌
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == 'G')
        board[i][j] = 'R';
    }
  }

  int is_g = area(); //적록색약인 사람
  cout << not_g << " " << is_g;
  return 0;
}
