#include <bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define X first
#define Y second
#define ll long long
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
//위쪽 반시계 아랫쪽 시계
int r, c, t;
int arr[55][55];
vector<pair<int, int>> pos; //0 윗쪽, 1아랫쪽
void spear() {
    int tmp[55][55];
    memcpy(tmp, arr, sizeof(tmp));
    for (int i = 0;i < r;i++) {
        for (int j = 0;j < c;j++) {
            if (!arr[i][j] || arr[i][j] == -1) continue;
            int cnt = 0;
            for (int dir = 0; dir < 4;dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if (arr[nx][ny] == -1) continue;
                tmp[nx][ny] += arr[i][j] / 5;
                cnt++;
            }
            tmp[i][j] -= (arr[i][j] / 5) * cnt;
        }
        
    }
    memcpy(arr, tmp, sizeof(arr));
}
void work() {
    int tmp[55][55];
    memcpy(tmp, arr, sizeof(tmp));
    for (int i = 0;i <= pos[0].X;i++) {
        for (int j = 0;j < c;j++) {
            if (j == 0 && i != pos[0].X) {
                tmp[i + 1][j] = arr[i][j];
                if (tmp[i + 1][j] == -1) tmp[i + 1][j] = 0;
            }
            else if (j == c - 1 && i != 0) {
                tmp[i - 1][j] = arr[i][j];
                if (tmp[i - 1][j] == -1) tmp[i - 1][j] = 0;
            }
            else if (i == 0 && j != 0) {
                tmp[i][j - 1] = arr[i][j];
                if (tmp[i][j - 1] == -1) tmp[i][j - 1] = 0;
            }
            else if (i == pos[0].X && j != c - 1) {
                tmp[i][j + 1] = arr[i][j];
                if (tmp[i][j + 1] == -1) tmp[i][j + 1] = 0;
            }
        }
    }
    for (int i = pos[1].X;i < r;i++) {
        for (int j = 0;j < c;j++) {
         
            if (i == pos[1].X && j != c - 1) {
                tmp[i][j + 1] = arr[i][j];
                if (tmp[i][j + 1] == -1) tmp[i][j + 1] = 0;
            }
            else if (i == r - 1 && j != 0) {
                tmp[i][j - 1] = arr[i][j];
                if (tmp[i][j - 1] == -1) tmp[i][j - 1] = 0;
            }
            else if (j == 0 && i != pos[1].X) {
                tmp[i - 1][j] = arr[i][j];
                if (tmp[i - 1][j] == -1) tmp[i - 1][j] = 0;
            }
            else if (j == c - 1 && i != r - 1) {
                tmp[i + 1][j] = arr[i][j];
                if (tmp[i + 1][j] == -1) tmp[i + 1][j] = 0;
            }
        }
    }
    memcpy(arr, tmp, sizeof(tmp));
    arr[pos[0].X][pos[0].Y] = -1;
    arr[pos[1].X][pos[1].Y] = -1;
}
int main(void) {
    fastIO;
    cin >> r >> c >> t;

    for (int i = 0;i < r;i++) {
        for (int j = 0;j < c;j++) {
            cin >> arr[i][j];
            if (arr[i][j] == -1) pos.push_back({ i,j });
        }
    }
    while (t--) {
        spear();
        work();
    }
    int ans = 0;
    for (int i = 0;i < r;i++) {
        for (int j = 0;j < c;j++)
            if (arr[i][j] != -1) ans += arr[i][j];
    }
    cout << ans;
}
