#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int arr[105][105];
bool vis[105][105];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n;
void reset() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vis[i][j] = 0;
        }
    }
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    int mx = 1; //아무지역도 물에 안잠기는 경우가있으므로 mx초기값은 1
    for (int h = 1; h < 101; h++) {
        int cnt = 0;
        reset();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] > h && vis[i][j] == 0) {
                    q.push({ i,j });
                    vis[i][j] = 1;
                    cnt++;
                }
                while (!q.empty()) {
                    pair<int, int> cur = q.front(); q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
                        if (arr[nx][ny] <= h || vis[nx][ny] == 1) continue;
                        q.push({ nx,ny }); vis[nx][ny] = 1;
                    }
                }
            }
        }
        mx = max(mx, cnt);
    }
    cout << mx;
}
