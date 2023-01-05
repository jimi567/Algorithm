#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int board[305][305];
int vis[305][305];
int n, m;
void removeIce() {
    int tmp[305][305];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            tmp[i][j] = board[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] != 0) {
                for (int id = 0; id < 4; id++) {
                    int nx = i + dx[id];
                    int ny = j + dy[id];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
                    if (tmp[nx][ny] != 0)continue;
                    board[i][j] = board[i][j] - 1;
                    if (board[i][j] == 0)break;
                }
            }
        }
   }
}
//빙산의 덩어리 갯수
int cnt() {
    int ans = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] != 0 && vis[i][j] == 0) {
                ans++;
                q.push({ i,j });
                vis[i][j] = 1;
                while (!q.empty()) {
                    pair<int, int> cur = q.front(); q.pop();
                    for (int idx = 0; idx < 4; idx++) {
                        int nx = cur.first + dx[idx];
                        int ny = cur.second + dy[idx];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
                        if (board[nx][ny] == 0 || vis[nx][ny] != 0)continue;
                        q.push({ nx,ny });
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
    }
    return ans;
}
bool isIce() {
    bool a = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] != 0) a = true;
        }
    }
    return a;
}
int main(void) {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    
    int year = 0;
    bool is = true; //빙산이 있는지 아닌지
    while (is) {
        for (int i = 0; i < n; i++)fill(vis[i], vis[i] + m, 0);//방문표시 초기화
        int ctm = cnt();
        if (ctm >= 2) break;
        removeIce();
        year++;
        is = isIce();
    }
    if (is) cout << year;
    else cout << 0;

}
