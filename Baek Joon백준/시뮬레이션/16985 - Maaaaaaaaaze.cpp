// 내 코드 시간 1100ms
// 회전방향은 백트래킹으로 구하고
//큐브를 쌓는건 next_per~로 쌓고 bfs
#include <bits/stdc++.h>
using namespace std;

int dx[] = { -1, 0, 1, 0, 0, 0 };
int dy[] = { 0, 1, 0, -1, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };

int input[5][5][5];//오리지널 입력값
int cube[5][5][5]; //각 경우의 큐브상태를 담는 배열
int vis[5][5][5]; //bfs용 방문여부 배열
int degress[5] = { -1,-1,-1,-1,-1 }; //각 층이 회전하는 횟수
int ans = 0x7f7f7f7f;
struct pos {
    int z, x, y;
};

void spin(int z, int degree) { //몇번째 판을 얼마나 회전시키는가
    int tmp[5][5];
    memcpy(cube[z], input[z], sizeof(input[z]));
    for(int c=0;c<degree;c++) {
        memcpy(tmp, cube[z], sizeof(cube[z]));
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cube[z][i][j] = tmp[j][4 - i];
            }
        }
    }
}
int bfs(int argCube[5][5][5]) {

    vector<pos> starts;
    vector<pos> ends;
    if (argCube[0][0][0] == 1 && argCube[4][4][4] == 1) {
        starts.push_back({ 0,0,0 });
        ends.push_back({ 4,4,4 });
    }
    if (argCube[0][0][4] ==1 && argCube[4][4][0] == 1) {
        starts.push_back({ 0,0,4 });
        ends.push_back({ 4,4,0 });
    }
    if (argCube[0][4][0] == 1 && argCube[4][0][4] == 1) {
        starts.push_back({ 0,4,0 });
        ends.push_back({ 4,0,4 });
    }
    if (argCube[0][4][4] == 1 && argCube[4][0][0] == 1) {
        starts.push_back({ 0,4,4 });
        ends.push_back({ 4,0,0 });
    }

    queue<pos> q;
    int ret = 0x7f7f7f7f;
    for (int i = 0; i < starts.size(); i++) {
        memset(vis, -1, sizeof(vis)); // vis배열 초기화
        q.push(starts[i]);
        vis[starts[i].z][starts[i].x][starts[i].y] = 0;
        while (!q.empty()) {
            pos cur = q.front(); q.pop();
            for (int dir = 0; dir < 6; dir++) {
                int nz = cur.z + dz[dir];
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                if (nz < 0 | nx < 0 || ny < 0 || nz >= 5 || nx >= 5 || ny >= 5) continue;
                if (vis[nz][nx][ny] != -1 || argCube[nz][nx][ny] == 0) continue;
                q.push({ nz,nx,ny });
                vis[nz][nx][ny] = vis[cur.z][cur.x][cur.y] + 1;
            }
        }
        if (vis[ends[i].z][ends[i].x][ends[i].y] != -1) ret = min(ret, vis[ends[i].z][ends[i].x][ends[i].y]);
    }
    return ret;
}
void stackCube() {
    int seq[5] = { 0,1,2,3,4 };
    do {
        int tmp[5][5][5];
        memcpy(tmp, cube, sizeof(cube));
        for (int i = 0; i < 5; i++) {
            memcpy(tmp[i], cube[seq[i]], sizeof(tmp[i]));
       }
        ans = min(ans,bfs(tmp));
    } while (next_permutation(seq,seq+5));
    
}
void makeCube(int k) {
    if (k == 5) {
        for (int i = 0; i < 5; i++) spin(i, degress[i]);
        stackCube();
        return;
    }
    for (int i = k; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (degress[i] == -1) {
                degress[i] = j;
                makeCube(k + 1);
                degress[i] = -1;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++) cin >> input[i][j][k];
    makeCube(0);
    if (ans == 0x7f7f7f7f) cout << -1;
    else cout << ans;
}

//바킹독 선생님 코드
//next_per로 회전값, 쌓는순서를 정하고 bfs
//나는 각 꼭짓점에 대해 start,end 인덱스를 넣고 bfs를 최대 4번 했는데 그럴필요가없는거같음
#include <bits/stdc++.h>
using namespace std;

// board[dir][i][j][k] :  i번째 판을 시계방향으로 dir번 돌렸을 때 (j, k)의 값
int board[4][5][5][5]; 
int maze[5][5][5];

int dx[6] = {1,0,0,0,0,-1};
int dy[6] = {0,1,-1,0,0,0};
int dz[6] = {0,0,0,1,-1,0};
int solve(){
  int dist[5][5][5] = {0,};
  if(maze[0][0][0] == 0 or maze[4][4][4] == 0) return 9999;

  queue<tuple<int,int,int>> q;
  q.push({0,0,0});
  dist[0][0][0] = 1;
  while(!q.empty()){
    tuple<int,int,int> cur = q.front(); q.pop();
    for(int dir = 0; dir < 6; dir++){
      int x, y, z;
      tie(x, y, z) = cur;
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      int nz = z + dz[dir];
      if(0 > nx || 5 <= nx || 0 > ny || 5 <= ny || 0 > nz || 5 <= nz) continue;      
      if(maze[nx][ny][nz] == 0 || dist[nx][ny][nz] != 0) continue;
      if(nx == 4 && ny == 4 && nz == 4)        
        return dist[x][y][z];
      dist[nx][ny][nz] = dist[x][y][z]+1;
      q.push({nx,ny,nz});
    }
  }
  return 9999;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++)
      for(int k = 0; k < 5; k++)
        cin >> board[0][i][j][k];
    
    for(int j = 0; j < 5; j++)
      for(int k = 0; k < 5; k++)
        board[1][i][j][k] = board[0][i][4-k][j];        
      
    for(int j = 0; j < 5; j++)
      for(int k = 0; k < 5; k++)
        board[2][i][j][k] = board[1][i][4-k][j]; 

    for(int j = 0; j < 5; j++)
      for(int k = 0; k < 5; k++)
        board[3][i][j][k] = board[2][i][4-k][j];      
  }

  int order[5] = {0,1,2,3,4}; // 판을 쌓는 순서
  int ans = 9999;
  do{
    for(int tmp = 0; tmp < 1024; tmp++){
      int brute = tmp; // 5개의 판에 대해 dir을 정해주기 위한 변수
      for(int i = 0; i < 5; i++){
        int dir = brute % 4; // brute & 3 이라고 멋있게 쓸 수도 있음
        brute /= 4; // brute >>= 2 라고 멋있게 쓸 수도 있음
        for(int j = 0; j < 5; j++)
          for(int k = 0; k < 5; k++)
            maze[i][j][k] = board[dir][order[i]][j][k];        
      }
      ans = min(ans,solve());
    }
  }while(next_permutation(order,order+5));

  if(ans == 9999) ans = -1;
  cout << ans;
}
//리팩토링 후
//기존 시작지점 도착지점 최대 4개를 구해서 bfs를 돌리는부분을 제외하고 0 0 0 -> 4 4 4의 경우만 체크
//320ms에 
#include <bits/stdc++.h>
using namespace std;

int dx[] = { -1, 0, 1, 0, 0, 0 };
int dy[] = { 0, 1, 0, -1, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };

int input[5][5][5];//오리지널 입력값
int cube[5][5][5]; //각 경우의 큐브상태를 담는 배열
int vis[5][5][5]; //bfs용 방문여부 배열
int degress[5] = { -1,-1,-1,-1,-1 }; //각 층이 회전하는 횟수
int ans = 0x7f7f7f7f;
struct pos {
    int z, x, y;
};

void spin(int z, int degree) { //몇번째 판을 얼마나 회전시키는가
    int tmp[5][5];
    memcpy(cube[z], input[z], sizeof(input[z]));
    for(int c=0;c<degree;c++) {
        memcpy(tmp, cube[z], sizeof(cube[z]));
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cube[z][i][j] = tmp[j][4 - i];
            }
        }
    }
}
int bfs(int argCube[5][5][5]) {
    queue<pos> q;
    int ret = 0x7f7f7f7f;
    if (argCube[0][0][0] == 0 || argCube[4][4][4] == 0) return ret;
    memset(vis, -1, sizeof(vis)); // vis배열 초기화
    q.push({ 0,0,0 });
    vis[0][0][0] = 0;
    while (!q.empty()) {
        pos cur = q.front(); q.pop();
        for (int dir = 0; dir < 6; dir++) {
            int nz = cur.z + dz[dir];
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (nz < 0 | nx < 0 || ny < 0 || nz >= 5 || nx >= 5 || ny >= 5) continue;
            if (vis[nz][nx][ny] != -1 || argCube[nz][nx][ny] == 0) continue;
            q.push({ nz,nx,ny });
            vis[nz][nx][ny] = vis[cur.z][cur.x][cur.y] + 1;
        }
    }
    if (vis[4][4][4] != -1) ret = min(ret, vis[4][4][4]);
    return ret;
}
void stackCube() {
    int seq[5] = { 0,1,2,3,4 };
    do {
        int tmp[5][5][5];
        memcpy(tmp, cube, sizeof(cube));
        for (int i = 0; i < 5; i++) {
            memcpy(tmp[i], cube[seq[i]], sizeof(tmp[i]));
       }
        ans = min(ans,bfs(tmp));
    } while (next_permutation(seq,seq+5));
    
}
void makeCube(int k) {
    if (k == 5) {
        for (int i = 0; i < 5; i++) spin(i, degress[i]);
        stackCube();
        return;
    }
    for (int i = k; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (degress[i] == -1) {
                degress[i] = j;
                makeCube(k + 1);
                degress[i] = -1;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++) cin >> input[i][j][k];
    makeCube(0);
    if (ans == 0x7f7f7f7f) cout << -1;
    else cout << ans;
}
