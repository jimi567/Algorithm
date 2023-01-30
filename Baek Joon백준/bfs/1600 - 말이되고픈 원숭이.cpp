#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int area[205][205];
int vis[201][201][31]; //31 -> 점프를 사용한 횟수
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int jx[8] = { -2,-1,-2,-1,1,2,1,2 };
int jy[8] = { -1,-2,1,2,-2,-1,2,1 };
int k, w, h;
int mn = 0x7f7f7f7f;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> w >> h;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> area[i][j];
        }
    }
    queue<pair<int, pair<int, int> > > q;

    q.push({ 0,{ 0,0 } });
    vis[0][0][0] = 1;
    while (!q.empty()) {
        pair<int, pair<int, int> > cur = q.front(); q.pop();
        if (cur.X < k) { //점프가능하면
            for (int i = 0; i < 8; i++) {
                int nx = cur.Y.X + jx[i];
                int ny = cur.Y.Y + jy[i];
                if (nx < 0 || ny < 0 || nx >= h || ny >= w)continue;
                if (area[nx][ny] != 0 || vis[nx][ny][cur.X + 1] != 0) continue;
                q.push({ cur.X + 1,{nx,ny} });
                vis[nx][ny][cur.X + 1] = vis[cur.Y.X][cur.Y.Y][cur.X] + 1;
            }
        }
        for (int i = 0; i < 4; i++) {
            int nx = cur.Y.X + dx[i];
            int ny = cur.Y.Y + dy[i];
            if (nx < 0 || ny < 0 || nx >= h || ny >= w)continue;
            if (area[nx][ny] != 0 || vis[nx][ny][cur.X] != 0) continue;
            q.push({ cur.X,{nx,ny} });
            vis[nx][ny][cur.X] = vis[cur.Y.X][cur.Y.Y][cur.X] + 1;
        }
;
    }
    for (int i = 0; i <= k; i++) {
        if(vis[h-1][w-1][i] >0) mn = min(mn, vis[h - 1][w - 1][i]);
    }
    if (mn == 0x7f7f7f7f) cout << -1;
    else  cout << mn - 1;
}
