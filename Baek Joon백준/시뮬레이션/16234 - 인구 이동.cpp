#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long
int dx[4] = { 1,0,-1,0 };//아래, 오른, 위, 왼
int dy[4] = { 0,1,0,-1 };
int arr[105][105];
int tmp[105][105];
int vis[105][105];
int n, l, r;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> l >> r;

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) cin >> arr[i][j];
    }

    queue<pair<int, int>> q; //bfs용 q
    vector<pair<int, int>> v;//연합 좌표 
    int ans = 0;
    bool flag = 1;
    memset(tmp, -1, sizeof(tmp));
    while (flag) {
        flag = 0;
        memset(vis, 0, sizeof(vis));
        memset(tmp, -1, sizeof(tmp));
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                if (vis[i][j]) continue;
                v.clear();
                q.push({ i,j });
                v.push_back({ i,j });
                vis[i][j] = 1;
                while (!q.empty()) {
                    auto cur = q.front();q.pop();
                    for (int dir = 0;dir < 4;dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                        if (vis[nx][ny])continue;
                        int sub = abs(arr[cur.X][cur.Y] - arr[nx][ny]);
                        if (sub < l || sub > r) continue;
                        q.push({ nx,ny }); vis[nx][ny] = 1;
                        v.push_back({ nx,ny });
                    }
                }
                if (v.size() > 1) flag = 1;
                int sum = 0;
                for (int c = 0;c < v.size();c++) sum += arr[v[c].X][v[c].Y];
                for (int c = 0;c < v.size();c++) {
                    tmp[v[c].X][v[c].Y] = sum / v.size();
                }
            }
        }
        if (flag) ans++;
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                if (tmp[i][j] != -1) arr[i][j] = tmp[i][j];
            }
        }
    }
    cout << ans;
}
