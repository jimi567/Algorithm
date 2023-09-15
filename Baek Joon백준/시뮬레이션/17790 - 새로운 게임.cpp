#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define X first
#define Y second

int n, k;

int dx[5] = {0, 0,0,-1,1 };
int dy[5] = {0, 1,-1,0,0 };

int bd[15][15];
vector<int> pos[15][15];
vector < tuple<int,int,int>> pi;

bool isEndGame() {
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            if (pos[i][j].size() >= 4) return true;
        }
    }
    return false;
}

void move(int x,int y,int nx,int ny) {

    if (nx <= 0 || ny <= 0 || nx > n || ny > n || bd[nx][ny] == 2) return;

    else if (bd[nx][ny] == 0) {
        for (int i = 0;i < pos[x][y].size();i++) {
            pos[nx][ny].push_back(pos[x][y][i]);
            int d;
            tie(x, y, d) = pi[pos[x][y][i]];
            pi[pos[x][y][i]] = { nx,ny,d };
        }
    }
    else {
        for (int i = pos[x][y].size() - 1;i >= 0;i--) {
            pos[nx][ny].push_back(pos[x][y][i]);
            int d;
            tie(x, y, d) = pi[pos[x][y][i]];
            pi[pos[x][y][i]] = { nx,ny,d };
        }
    }
    pos[x][y].clear();
}
int main() {
    fastIO;
    cin >> n >> k;

    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cin >> bd[i][j];
        }
    }
    for (int i = 0;i < k;i++) {
        int x, y, d;
        cin >> x >> y >> d;

        pos[x][y].push_back(i);
        pi.push_back({x,y,d});
    }

    int ans = 0;
    while (1) {
        if (isEndGame()) break;
        if (ans >= 1000) {
            cout << -1 << endl;
            return 0;
        }
        for (int num = 0;num < k;num++) {
            int x, y, d;
            tie(x, y, d) = pi[num];
          
            if (pos[x][y][0] != num) continue;
     
            int nx = x + dx[get<2>(pi[num])];
            int ny = y + dy[get<2>(pi[num])];
            
            if (nx <= 0 || ny <= 0 || nx > n || ny > n || bd[nx][ny] == 2) {
                if (d % 2) pi[num] = { x,y,d + 1 };
                else pi[num] = { x,y,d - 1 };
                nx = x + dx[get<2>(pi[num])];
                ny = y + dy[get<2>(pi[num])];
            
            }
            move(x, y, nx, ny);
            
        }
        ans++;
   
    }    
    cout << ans << endl;
    
    return 0;
}
