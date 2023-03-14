#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long
string arr[1005];
int vis[1005][1005][11];//벽부순횟수
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m,k;
int ans = 0x7f7f7f7f;
bool OOB(int x, int y) {
    return x < 0 || y < 0 || x >= n || y >= m;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }
    queue<tuple<int, int,int>> q;
    q.push({ 0,0,0 });
    vis[0][0][0] = 1;
    while (!q.empty()) {
        int x, y, b;
        tie(x, y, b) = q.front();
        if (x == n - 1 && y == m - 1) ans = min(ans, vis[x][y][b]);
        q.pop();
        for (int dir = 0;dir < 4;dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (OOB(nx, ny)) continue;
            if (arr[nx][ny] == '1') {
                if (b >= k ) continue;
                if (vis[nx][ny][b + 1] != 0) continue;
                vis[nx][ny][b + 1] = vis[x][y][b] + 1;
                q.push({ nx,ny,b + 1 });
            }
            else {
                if (vis[nx][ny][b] != 0) continue;
                vis[nx][ny][b] = vis[x][y][b] + 1;
                q.push({ nx,ny,b });
            }
        }
    }
    if (ans == 0x7f7f7f7f) cout << -1;
    else cout << ans;
}
