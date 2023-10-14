//실프에도 있는 문제;; 1시간안에 못풀었는데;;
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int r, c;
int area[55][55];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 }; // 북 동 남 서;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    pair<int, int> pos;
    int dir;
    cin >> r >> c;
    cin >> pos.X >> pos.Y >> dir;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) cin >> area[i][j];
    
    queue<pair<int, int>> q;
    int cnt = 0;
    q.push(pos);
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        if (area[cur.X][cur.Y] == 0) {
            area[cur.X][cur.Y] = 2;
            cnt++;
        }
        bool flag = false; //현재 칸의 주변 4칸 중 청소되지 않은 빈칸이 있는지 ?
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || ny < 0 || nx >= r || ny >= c)continue;
            if (area[nx][ny] == 0) {
                flag = true; //청소가 가능하다.
                break;
            }
        }
        if (flag) { //청소가 가능한 경우 case 3
            dir = (dir + 3) % 4; //반시계 방향으로 회전.
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (!(nx < 0 || ny < 0 || nx >= r || ny >= c)) {
                if (area[nx][ny] == 0) q.push({ nx,ny });
                else q.push(cur);
            }
        }
        else { //청소가 불가능한 경우 case 2
            int nx = cur.X + dx[(dir + 2) % 4];
            int ny = cur.Y + dy[(dir + 2) % 4];
            if (!(nx < 0 || ny < 0 || nx >= r || ny >= c)) {
                if (area[nx][ny] != 1) q.push({ nx,ny });
                else break;
            }
        }
    }
    cout << cnt;
}
