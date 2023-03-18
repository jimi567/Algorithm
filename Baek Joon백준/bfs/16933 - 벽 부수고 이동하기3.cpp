#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long
int dx[5] = { 1,0,-1,0,0 };
int dy[5] = { 0,1,0,-1,0 };
string arr[1005];
int vis[1005][1005][11][2];
int n, m, k;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0;i < n;i++) cin >> arr[i];
    queue<tuple<int,int,int,bool>> q;
    q.push({0,0,0,1});
    vis[0][0][0][1] = 1;
    while (!q.empty()) {
        int x, y, b, d;
        tie(x, y, b, d) = q.front(); q.pop();
        if (x == n - 1 && y == m - 1) {
            cout << vis[x][y][b][d];
            return 0;
        }
        for (int i = 0;i < 5;i++) {
            if (i == 4 && d) continue; //낮이면 멈춰있을 이유가없음
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (arr[nx][ny] == '1') {
                if (i != 4) {
                    if (b >= k || !d) continue;
                    if (vis[nx][ny][b + 1][!d] > 0) continue;
                    q.push({ nx,ny,b + 1,!d });
                    vis[nx][ny][b + 1][!d] = vis[x][y][b][d] + 1;
                }
                else {
                    q.push({ nx,ny,b ,!d });
                    vis[nx][ny][b][!d] = vis[x][y][b][d] + 1;
                }
            }
            else {
                if (vis[nx][ny][b][!d] > 0) continue;
                q.push({ nx,ny,b,!d });
                vis[nx][ny][b][!d] = vis[x][y][b][d] + 1;
            }
        }
    }
    cout << -1;
}
