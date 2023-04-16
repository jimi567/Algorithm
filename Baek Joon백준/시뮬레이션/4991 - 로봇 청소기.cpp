#include <bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define X first
#define Y second
#define ll long long
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int r, c;
string arr[22];
pair<int, int> pos;
pair<int, int> oripos;
int vis[22][22];
int dist[22][22][22][22]; //[i][j] -> [x][y]에 bf
int bfs(pair<int,int> st, pair<int,int> dst) {
    for (int i = 0;i < r;i++) fill(vis[i], vis[i] + c, 0);
    queue<pair<int, int>> q;
    q.push(st);
    while (!q.empty()) {
        auto cur = q.front();q.pop();
        if (cur.X == dst.X && cur.Y == dst.Y) {
            return vis[cur.X][cur.Y];
        }
        for (int i = 0;i < 4;i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || ny < 0 || nx >= r || ny >= c)continue;
            if (arr[nx][ny] == 'x' || vis[nx][ny]) continue;
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            q.push({ nx,ny });
        }
    }
    return -1;
}
int main(void) {
    fastIO;
    while (1) {
        cin >> c >> r;
        vector<pair<int, int>> htc; // 청소해야되느 위치
        memset(dist, 0, sizeof(dist));
        if (!r && !c) break;
        for (int i = 0;i < r;i++) {
            cin >> arr[i];
            for (int j = 0;j < c;j++) {
                if (arr[i][j] == 'o')  oripos = { i,j };
                else if (arr[i][j] == '*') htc.push_back({ i,j });
            }
        }
        bool canCleanup = true;
        vector<pair<int, int>> starts;
        starts.push_back(oripos);
        for (int i = 0;i < htc.size();i++) starts.push_back(htc[i]);
        for (int i = 0;i < starts.size();i++) {
            for (int j = 0;j < htc.size();j++) {
                dist[starts[i].X][starts[i].Y][htc[j].X][htc[j].Y] = bfs(starts[i], htc[j]);
                if (dist[starts[i].X][starts[j].Y][htc[j].X][htc[j].Y] == -1)canCleanup = false;
            }
            
        }
        if (!canCleanup) cout << -1 << endl;
        else {
            int ans = 0x7f7f7f7f;
            do {
                int cnt = 0;
                pos = oripos;
                for (int i = 0;i < htc.size();i++) {
                    cnt += dist[pos.X][pos.Y][htc[i].X][htc[i].Y];
                    pos = htc[i];
                }
                ans = min(ans, cnt);
            } while (next_permutation(htc.begin(), htc.end()));
            cout << ans << endl;
        }
    }
}
