#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long
int n;
int arr[22][22];
int vis[22][22];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
pair<int, int> pos;
int bfs(pair<int, int> des, int size) {
    memset(vis, 0, sizeof(vis));
    queue<pair<int, int>> q;
    q.push(pos);
    while (!q.empty()) {
        auto cur = q.front();q.pop();
        if (des.X == cur.X && des.Y == cur.Y) return vis[cur.X][cur.Y];
        for (int i = 0;i < 4;i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            
            if (vis[nx][ny] != 0 || arr[nx][ny] > size) continue;
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            q.push({ nx,ny });
        }
    }
    return -1;
}
int eat(int size) {
    int dist = 0x7f7f7f7f;
    int x = pos.X;
    int y = pos.Y;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if (arr[i][j] != 0 && arr[i][j] < size) {
                int tmp = bfs({ i,j },size);
                if (tmp != -1 && dist > tmp) {
                    dist = tmp;
                    x = i;
                    y = j;
                }
            }
        }
    }
    if (dist == 0x7f7f7f7f) return 0;
    arr[x][y] = 0;
    pos = { x,y };
    return dist;
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 9) {
                pos = { i,j };
                arr[i][j] = 0;
            }
        }
    }
    int ans = 0;
    int size = 2;
    int eating = 0;
    while (1) {
        int time = eat(size);
        if (time == 0) break;
        ans += time;
        eating++;
        if (eating == size) {
            size++;
            eating = 0;
        }
    }
    cout << ans;
}
