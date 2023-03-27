#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long
int dx[4] = { 1,0,-1,0 };//아래, 오른, 위, 왼
int dy[4] = { 0,1,0,-1 };
int n, m;
ll ans;
ll arr[22][22];
ll tmp[22][22];
ll getMax() {
    ll mx = 0;
    for (int i = 0;i < n;i++) 
        for (int j = 0;j < n;j++) mx = max(mx, tmp[i][j]);
    return mx;
}
void go(int dir) {
    if (dir == 2 || dir == 3) {
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                if (tmp[i][j] == 0) continue;
                int nx = i;
                int ny = j;
                while (1) {
                    nx += dx[dir];
                    ny += dy[dir];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) break;
                    if (tmp[nx][ny] != 0) break;
                }
                nx -= dx[dir];
                ny -= dy[dir];
                swap(tmp[i][j], tmp[nx][ny]);
            }
        }
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                if (tmp[i][j] == 0) continue;
                int nx = i + dx[(dir+2)%4];
                int ny = j + dy[(dir + 2) % 4];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (tmp[i][j] == tmp[nx][ny]) {
                    tmp[i][j] = tmp[i][j] * 2;
                    tmp[nx][ny] = 0;
                }
            }
        }
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                if (tmp[i][j] == 0) continue;
                int nx = i;
                int ny = j;
                while (1) {
                    nx += dx[dir];
                    ny += dy[dir];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) break;
                    if (tmp[nx][ny] != 0 ) break;
                }
                nx -= dx[dir];
                ny -= dy[dir];
                swap(tmp[nx][ny], tmp[i][j]);
            }
        }
    }
    else if (dir == 0) {
        for (int i = n;i >= 0;i--) {
            for (int j = 0;j < n;j++) {
                if (tmp[i][j] == 0) continue;
                int nx = i;
                int ny = j;
                while (1) {
                    nx += dx[dir];
                    ny += dy[dir];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) break;
                    if (tmp[nx][ny] != 0) break;
                }
                nx -= dx[dir];
                ny -= dy[dir];
                swap(tmp[nx][ny], tmp[i][j]);
            }
        }
        for (int i = n;i >= 0;i--) {
            for (int j = 0;j < n;j++) {
                if (tmp[i][j] == 0) continue;
                int nx = i + dx[(dir + 2) % 4];
                int ny = j + dy[(dir + 2) % 4];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (tmp[i][j] == tmp[nx][ny]) {
                    tmp[i][j] = tmp[i][j] * 2;
                    tmp[nx][ny] = 0;
                }
            }
        }
        for (int i = n;i >= 0;i--) {
            for (int j = 0;j < n;j++) {
                if (tmp[i][j] == 0) continue;
                int nx = i;
                int ny = j;
                while (1) {
                    nx += dx[dir];
                    ny += dy[dir];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) break;
                    if (tmp[nx][ny] != 0) break;
                }
                nx -= dx[dir];
                ny -= dy[dir];
                swap(tmp[nx][ny],tmp[i][j]);
            }
        }
    }
    else if(dir==1){
        for (int i = 0;i < n;i++) {
            for (int j = n;j >=0;j--) {
                if (tmp[i][j] == 0) continue;
                int nx = i;
                int ny = j;
                while (1) {
                    nx += dx[dir];
                    ny += dy[dir];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) break;
                    if (tmp[nx][ny] != 0) break;
                }
                nx -= dx[dir];
                ny -= dy[dir];
                swap(tmp[nx][ny], tmp[i][j]);
            }
        }
 
        for (int i = 0;i < n;i++) {
            for (int j = n;j >=0;j--) {
                if (tmp[i][j] == 0) continue;
                int nx = i + dx[(dir + 2) % 4];
                int ny = j + dy[(dir + 2) % 4];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (tmp[i][j] == tmp[nx][ny]) {
                    tmp[i][j] = tmp[i][j] * 2;
                    tmp[nx][ny] = 0;
                }
            }
        }
        for (int i = 0;i < n;i++) {
            for (int j = n;j >=0;j--) {
                if (tmp[i][j] == 0) continue;
                int nx = i;
                int ny = j;
                while (1) {
                    nx += dx[dir];
                    ny += dy[dir];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) break;
                    if (tmp[nx][ny] != 0) break;
                }
                nx -= dx[dir];
                ny -= dy[dir];
                swap(tmp[nx][ny], tmp[i][j]);
            }
        }
    }
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++) cin >> arr[i][j];

    for (int k = 0;k < 1<<10;k++) {
        memcpy(tmp, arr, sizeof(tmp));
        int brute = k;   
        for (int i = 0;i < 5;i++) {
            int dir = brute % 4;
            brute /= 4;
            go(dir);
        }
        ans = max(ans, getMax());
    }
    cout << ans;
    return 0;
}
