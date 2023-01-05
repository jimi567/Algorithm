#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int arr[105][105][105];//[h][n][m]
int vis[105][105][105];
int m, n, h;
int dx[6] = { 1, 0, -1, 0, 0, 0 };
int dy[6] = { 0, 1, 0, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };
void bfs(queue<vector<int>> q) {
    while (!q.empty()) {
        vector<int> cur = q.front(); q.pop();
        for (int idx = 0; idx < 6; idx++) {
            int pz = cur[0] + dz[idx];
            int py = cur[1] + dy[idx];
            int px = cur[2] + dx[idx];
            if (px < 0 || px >= m || py < 0 || py >= n || pz < 0 || pz >= h)continue;
            if (arr[pz][py][px] != 0 || vis[pz][py][px] != 0)continue;
            q.push({ pz,py,px });
            vis[pz][py][px] = vis[cur[0]][cur[1]][cur[2]] + 1;
            arr[pz][py][px] = 1; // 토마토 익은 상태로 바꿈
        }
    }

}
int main(void) {
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> m >> n >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> arr[i][j][k];
            }
        }
    }
    queue <vector<int>> q;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (arr[i][j][k] == 1) { //익은 토마토 q에 전부 집어넣음
                    vector<int> v;
                    v.push_back(i); v.push_back(j); v.push_back(k);
                    q.push(v);
                    vis[i][j][k] = 1;
                }
            }
        }
    }
    bfs(q);
    int day = 0;
    bool isA = true;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (arr[i][j][k] == 0) isA= false;// 다안익은 경우
                day = max(day, vis[i][j][k] );
            }
        }
    }
    if (isA)cout << day -1 ; //vis 초기값 0이라서 -1하고 출력
    else cout << -1;
    
    return 0;

}
