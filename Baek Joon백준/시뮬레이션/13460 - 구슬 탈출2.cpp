#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long
int n, m;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
string arr[15];
vector<pair<int, int>> red[15];
vector<pair<int, int>> blue[15];
tuple<int, int, bool> move(int x, int y, int dir,int ax,int ay) {
    bool isGoal = false;
    while (1) {
        int nx = x + dx[dir]; 
        int ny = y + dy[dir];
        if (arr[nx][ny] == 'O') {
            isGoal = true;
            x = -1; y = -1;
            break;
        }
        if (arr[nx][ny] != '.' || (nx == ax && ny == ay)) break;
        x = nx; y = ny;
    }
    return { x,y,isGoal };
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0;i < n;i++) cin >> arr[i];
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (arr[i][j] == 'R') {
                red[0].push_back({i,j});
                arr[i][j] = '.';
            }
            if (arr[i][j] == 'B') {
                blue[0].push_back({i,j});
                arr[i][j] = '.';
            }
        }
    }
    int rx, ry, bx, by;
    int k = 0;
    while (k<10) {
        k++;
        for (int i = 0;i < red[k-1].size();i++) {
            tie(rx, ry) = red[k-1][i];
            tie(bx, by) = blue[k-1][i];
            int rnx, rny, bnx, bny;
            bool goalRed, goalBlue;
            for (int dir = 0;dir < 4;dir++) {
                if (dir == 0) {
                    if (ry < by) {
                        tie(rnx, rny, goalRed) = move(rx, ry, dir,bx,by);
                        tie(bnx, bny, goalBlue) = move(bx, by, dir,rnx, rny);
                    }
                    else {
                        tie(bnx, bny, goalBlue) = move(bx, by, dir, rx, ry);
                        tie(rnx, rny, goalRed) = move(rx, ry, dir,  bnx, bny);
                    }
                }
                else if (dir == 1) {
                    if (ry > by) {
                        tie(rnx, rny, goalRed) = move(rx, ry, dir, bx, by);
                        tie(bnx, bny, goalBlue) = move(bx, by, dir, rnx, rny);
                    }
                    else {
                        tie(bnx, bny, goalBlue) = move(bx, by, dir, rx, ry);
                        tie(rnx, rny, goalRed) = move(rx, ry, dir,  bnx, bny);
                    }
                }
                else if (dir == 2) {
                    if (rx < bx) {
                        tie(rnx, rny, goalRed) = move(rx, ry, dir,  bx, by);
                        tie(bnx, bny, goalBlue) = move(bx, by, dir, rnx, rny);
                    }
                    else {
                        tie(bnx, bny, goalBlue) = move(bx, by, dir, rx, ry);
                        tie(rnx, rny, goalRed) = move(rx, ry, dir, bnx, bny);
                    }
                }
                else {
                    if (rx > bx) {
                        tie(rnx, rny, goalRed) = move(rx, ry, dir, bx, by);
                        tie(bnx, bny, goalBlue) = move(bx, by, dir, rnx, rny);
                    }
                    else {
                        tie(bnx, bny, goalBlue) = move(bx, by, dir, rx, ry);  
                        tie(rnx, rny, goalRed) = move(rx, ry, dir, bnx, bny);
                    }
                }
                if (goalRed && !goalBlue ) {
                    cout << k;
                    return 0;
                }
                if (goalBlue) continue;
                red[k].push_back({ rnx,rny });
                blue[k].push_back({ bnx,bny });
            }
        }
    }
    cout << -1;
}
