#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, m;
int area[10][10];
int wallPos[10][10];
int vis[10][10];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int mx = 0;
queue<pair<int, int>> q;
void cleanVis() {
    for (int i = 0; i<n; i++) {
        fill(vis[i], vis[i] + 10, 0);
    }
}
void bfs() {
    cleanVis();
    int bfsMap[10][10];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bfsMap[i][j] = area[i][j];
            if (wallPos[i][j] == 1) bfsMap[i][j] = 1;
        }
    }
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
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
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
            if (vis[nx][ny] == 1 || bfsMap[nx][ny] != 0) continue;
            q.push({ nx,ny }); vis[nx][ny] = 1;
        }
    }
    int safeArea = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] == 0 && bfsMap[i][j] != 1) safeArea++;
        }
    }
    mx = max(mx, safeArea);
}

void makeWall(int k) { //백트래킹으로 벽 세우기
    if (k == 3) { //벽 다세우면 bfs 호출
        bfs();
        return;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (area[i][j] == 0 && wallPos[i][j] == 0) {
                wallPos[i][j] = 1;
                makeWall(k + 1);
                wallPos[i][j] = 0;
            }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> area[i][j];
        }
    }
   
    makeWall(0);
    cout << mx;
 
}
