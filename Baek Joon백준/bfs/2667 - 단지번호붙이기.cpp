#include <bits/stdc++.h>
using namespace std;

int n;
string area[27];
int vis[27][27];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++)
            cin >> area[i];

    queue<pair<int, int>> q;
    int num = 0; //단지 번호
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (area[i][j] == '1' && vis[i][j] == 0) {
                q.push({ i,j });
                num++;
                vis[i][j] = num;
                while (!q.empty()) {
                    pair<int, int> cur = q.front(); q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
                        if (vis[nx][ny] != 0 || area[nx][ny] == '0')continue;
                        vis[nx][ny] = num;
                        q.push({ nx,ny });
                    }
                }
            }
        }
    }
    cout << num << '\n';
    int cnt = 0;
    vector<int> ansV;
    for(int k=1;k<=num;k++){
        cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == k) cnt++;
            }
        }
        ansV.push_back(cnt);
    }
    sort(ansV.begin(), ansV.end());
    for (auto a : ansV) cout << a << '\n';
}
