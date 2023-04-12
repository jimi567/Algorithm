#include <bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define X first
#define Y second
#define ll long long
int dx[4] = {-1,1 ,0,0 };
int dy[4] = {0, 0 ,1,-1 };
int r, c, m;
struct SK {
    int z, s, d;
};
SK arr[105][105];
int get_sk(int p) {
    int ret = 0;
    for (int i = 1;i <= r;i++) {
        if (arr[i][p].z == 0) continue;
        ret = arr[i][p].z;
        arr[i][p] = { 0,0,0 };
        break;
    }
    return ret;
}
void move_sk() {
    SK tmp[105][105];
    for (int i = 1;i <= r;i++)
        for (int j = 1;j <= c;j++) tmp[i][j] = { 0,0,0 };

    for (int i = 1;i <= r;i++) {
        for (int j = 1;j <= c;j++) {
            if (!arr[i][j].z)continue;
            int nx = i;
            int ny = j;
            int dist = arr[i][j].s;
            
            while (dist) {
                if (arr[i][j].d == 0) {
                    if (dist > nx - 1) {
                        dist -= nx - 1;
                        nx = 1;
                        arr[i][j].d += 1;
                    }
                    else {
                        nx += dist * dx[arr[i][j].d];
                        dist = 0;
                    }
                }
                else if (arr[i][j].d == 1) {
                    if (dist > r - nx) {
                        dist -= r - nx;
                        nx = r;
                        arr[i][j].d -= 1;
                    }
                    else {
                        nx += dist * dx[arr[i][j].d];
                        dist = 0;
                    }
                }
                else if (arr[i][j].d == 2) {
                    if (dist > c - ny) {
                        dist -= c - ny;
                        ny = c;
                        arr[i][j].d += 1;
                    }
                    else {
                        ny += dist * dy[arr[i][j].d];
                        dist = 0;
                    }
                }
                else {
                    if (dist > ny - 1) {
                        dist -= ny - 1;
                        ny = 1;
                        arr[i][j].d -= 1;
                    }
                    else {
                        ny += dist * dy[arr[i][j].d];
                        dist = 0;
                    }
                }
            }
            if (tmp[nx][ny].z > 0) { 
                if (tmp[nx][ny].z < arr[i][j].z) tmp[nx][ny] = arr[i][j];
            }
            else tmp[nx][ny] = arr[i][j];
        }
    }
    for (int i = 1;i <= r;i++)
        for (int j = 1;j <= c;j++) arr[i][j] = tmp[i][j];
   
}
int main(void) {
    fastIO;
    cin >> r >> c >> m;
    for (int i = 0;i < m;i++) {
        int r1, c1, s, d, z;
        cin >> r1 >> c1 >> s >> d >> z;
        arr[r1][c1] = { z,s, d-1 };
    }
    int ans = 0;

    for (int p = 1;p <= c;p++) {
        ans += get_sk(p);
        move_sk(); 
    }
    cout << ans;
}
