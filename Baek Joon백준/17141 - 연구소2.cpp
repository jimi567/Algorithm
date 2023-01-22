#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, m;
int area[52][52];
int virusPos[52][52];
int vis[52][52];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int mn = 0x7f7f7f7f;
queue<pair<int, int>> q;
void cleanMap(int (*arr)[52] ) {
    for (int i = 0; i<n; i++) {
        fill(arr[i], arr[i] + n, 0);
    }
}
void bfs() {
    cleanMap(vis);
    int bfsMap[52][52];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (virusPos[i][j] == 2) bfsMap[i][j] = 2;
            else if (area[i][j] == 1 || area[i][j] == 0 ) bfsMap[i][j] = area[i][j];
            else bfsMap[i][j] = 0;
        }
    }
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (bfsMap[i][j] == 2) {
                q.push({ i,j }); vis[i][j] = 1;
            }
        }
    }
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
            if (vis[nx][ny] != 0 || bfsMap[nx][ny] == 1) continue;
            q.push({ nx,ny }); vis[nx][ny] = vis[cur.X][cur.Y] + 1;
        }
    }
    int time = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j] == 0 && area[i][j] != 1) return;
            time = max(time, vis[i][j]);
        }
    }
    mn = min(mn, time);

}
void makeVirus(vector<pair<int,int>> k) {
    if (k.size() < m) { //m이 바이러스가 놓일 수 있는 칸보다 큰 경우
        for (int i = 0; i < k.size(); i++) virusPos[k[i].X][k[i].Y] = 2;
        bfs();
        return;
    }
    int conbi[k.size()] = { 0, };
    fill(conbi+m, conbi + k.size(), 1);
    do {
        cleanMap(virusPos);
        for (int i = 0; i < k.size(); i++) {
            if (conbi[i] == 0) {
                virusPos[k[i].X][k[i].Y] = 2;
            }
        }
        bfs();
    } while (next_permutation(conbi, conbi + k.size()));
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<pair<int, int>>  canbe; //2의 좌표모음
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> area[i][j];
            if (area[i][j] == 2) canbe.push_back({ i,j });
        }
    }
    makeVirus(canbe);
    if (mn == 0x7f7f7f7f) cout << -1;
    else cout << mn - 1; //바이러스 놓여진 위치가 1부터시작하므로
 
}
