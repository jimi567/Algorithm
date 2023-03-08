#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, m;
int arr[55][55];
int vis[55][55];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> q;
vector<pair<int, int>> virus;
int ans = 0x7f7f7f7f;
int check() {
    int ret = 0;
    //모든 빈칸에 바이러스가 퍼졌는지 체크
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if (vis[i][j] == -1 && arr[i][j] == 0) return -1;
        }
    }
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
             if(arr[i][j] == 0)ret = max(ret, vis[i][j]); //빈칸만 체크
        }
    }
    return ret;
}
void bfs() {
    while (!q.empty()) {
        auto cur = q.front();q.pop();
        for (int i = 0;i < 4;i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (vis[nx][ny] > -1 || arr[nx][ny] == 1) continue;
            q.push({ nx,ny }); 
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
        }
    }
    int tmp = check();
    if (tmp!=-1) ans = min(ans, tmp);
}
void setVirus() {
    vector<int> cb(virus.size(),1);
    fill(cb.begin(), cb.begin()+cb.size()-m, 0);
    do {
        for (int i = 0;i < n;i++) fill(vis[i], vis[i] + n, -1);
        for (int i = 0;i < virus.size();i++) {
            if (cb[i] == 1) {
                q.push(virus[i]);
                vis[virus[i].X][virus[i].Y] = 0;
            }
        }
        bfs();
    } while (next_permutation(cb.begin(), cb.end()));

}
//0은 빈 칸, 1은 벽, 2는 바이러스
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 2)
                virus.push_back({ i,j });
        }
    }
    setVirus();
    if (ans == 0x7f7f7f7f) cout << -1;
    else cout << ans;

}
