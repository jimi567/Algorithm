#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
// 나이트가 움직일 수있는 좌표
int dx[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[8] = { -1, 1,  -2, 2, -2, 2, -1, 1 };
int board[305][305];
int vis[305][305];


int main(void) {
    ios::sync_with_stdio(0), cin.tie(0);
    int loop;
    cin >> loop;
    while (loop--) {

        int l; pair<int, int> pos; pair<int, int> target;
        cin >> l >> pos.X >> pos.Y >> target.X >> target.Y;

        queue<pair<int, int>> q;
        q.push(pos); // 나이트 좌표 푸쉬
        vis[pos.X][pos.Y] = 1; //초기 위치 1

        int ans;
        while (!q.empty()) {
            pair<int, int> cur = q.front(); q.pop();
            if (cur.X == target.X && cur.Y == target.Y) {
                ans = vis[cur.X][cur.Y] - 1;
                break;
            }
            for (int i = 0; i < 8; i++) {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if (nx < 0 || nx >= l || ny < 0 || ny >= l)continue;
                if (vis[nx][ny] != 0) continue;
                q.push({ nx,ny });
                vis[nx][ny] = vis[cur.X][cur.Y] + 1;
                
            }
        }

        cout << ans << '\n';
        for (int i = 0; i < l; i++) fill(vis[i], vis[i] + l, 0);//방문기록초기화
    }
}
