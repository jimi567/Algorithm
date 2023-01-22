#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, m, x, y, k;
int dx[4] = { 0,0,-1,1 };//동 서 북 남
int dy[4] = { 1,-1,0,0 };
int arr[22][22];
int oper[1005];
int cube[6];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> x >> y >> k;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < k; i++) {
        cin >> oper[i];
    }
    
    int nx = x;
    int ny = y;
    for (int i = 0; i < k; i++) {
        if (nx + dx[oper[i] - 1] < 0 || nx + dx[oper[i] - 1] >= n)continue;
        if (ny + dy[oper[i] - 1] < 0 || ny + dy[oper[i] - 1] >= m)continue;
        nx += dx[oper[i] - 1];
        ny += dy[oper[i] - 1];
        int d0 = cube[0];
        int d1 = cube[1];
        int d2 = cube[2];
        int d3 = cube[3];
        int d4 = cube[4];
        int d5 = cube[5];
        if (oper[i] == 1) {
            cube[0] = d2;
            cube[1] = d1;
            cube[2] = d5;
            cube[3] = d0;
            cube[4] = d4;
            cube[5] = d3;
        }
        else if (oper[i] == 2) {
            cube[0] = d3;
            cube[1] = d1;
            cube[2] = d0;
            cube[3] = d5;
            cube[4] = d4;
            cube[5] = d2;
        }
        else if (oper[i] == 3) {
            cube[0] = d1;
            cube[1] = d5;
            cube[2] = d2;
            cube[3] = d3;
            cube[4] = d0;
            cube[5] = d4;
        }
        else if (oper[i] == 4) {
            cube[0] = d4;
            cube[1] = d0;
            cube[2] = d2;
            cube[3] = d3;
            cube[4] = d5;
            cube[5] = d1;
        }
        if (arr[nx][ny] == 0) {
            arr[nx][ny] = cube[0];
        }
        else {
            cube[0] = arr[nx][ny];
            arr[nx][ny] = 0;
        }
        cout << cube[5] << '\n';
    }
} 

------------------
  #include <bits/stdc++.h>
using namespace std;

int N, M, x, y, K, command;
int board[21][21];  // 지도
int dice[7];        // 주사위
//  윗면이 2이고, 동쪽을 바라보는 방향이 6
//     [1]
//  [5][2][6]
//     [3]
//     [4]

int idx[5][4] = {
  {},        // dummy
  {2,6,4,5}, // 동쪽, 5->2, 2->6, 6->4, 4->5
  {2,5,4,6}, // 서쪽, 6->2, 2->5, 5->4, 4->6
  {3,2,1,4}, // 북쪽, 4->3, 3->2, 2->1, 1->4
  {2,3,4,1}, // 남쪽, 1->2, 2->3, 3->4, 4->1
};

// 명령어가 유효한지 검증하는 함수
bool isOk(int nx, int ny){
  if(nx<0||nx>=N||ny<0||ny>=M) return false;
  return true;
}

// 주사위를 굴리는 함수
void roll(int com){
  // 회전 시 기존 주사위의 값을 별도로 보존하기 위한 배열 생성
  int tmp[7];
  for(int i = 1; i <= 6; ++i) tmp[i]=dice[i];

  // 굴리는거 처리
  for(int i = 0; i < 4; i++)
    tmp[idx[com][i]] = dice[idx[com][(i+1)%4]];

  // 회전 결괏값을 기존 주사위에 대입
  for(int i = 1; i <= 6; ++i) dice[i]=tmp[i];
}

void score(int c){
  int nx=x, ny=y;
  // 주사위 위치 이동
  if(c==1) ++ny;
  else if(c==2) --ny;
  else if(c==3) --nx;
  else ++nx;

  if(isOk(nx, ny)){
    x=nx; y=ny; // 유효성 확인 후 주사위의 위치 대입
    roll(c);
    // 0일 경우
    if(board[nx][ny]==0)
      board[nx][ny]=dice[4]; // 칸에 바닥면 값 대입
    
    // 0이 아닐 경우
    else {
      dice[4]=board[nx][ny]; // 바닥면에 칸 값 대입
      board[nx][ny]=0; // 칸 값을 0으로 초기화
    }
    cout << dice[2] << '\n'; // 주사위 윗면 출력
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M >> x >> y >> K;
  for(int i = 0; i < N; ++i)
    for(int j = 0; j < M; ++j)
      cin >> board[i][j];

  while(K--){
    cin >> command;
    score(command);
  }
}
