#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define X first
#define Y second
int n, m;
int arr[55][55];

int dx[8] = { 0,-1,-1,-1,0,1,1,1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };

vector<pair<int, int>> cloud;

bool chk(int r, int c) {

    for (int i = 0;i < cloud.size();i++) {
        if (cloud[i].X == r && cloud[i].Y == c) return false;
    }
    return true;
}

void rain(int d,int s) {

    for (int i = 0;i < cloud.size();i++) {
        int nx = cloud[i].X + (dx[d] * s);
        int ny = cloud[i].Y + (dy[d] * s);

        while (nx > n) nx -=n;
        while (nx <= 0) nx += n;

        while (ny > n) ny -= n;
        while (ny <= 0) ny += n;

        cloud[i] = { nx,ny };
       
    }

    for (int i = 0;i < cloud.size();i++) {
        arr[cloud[i].X][cloud[i].Y]++;
    }

    for (int i = 0;i < cloud.size();i++) {
        for (int j = 1;j < 8;j += 2) {
            int nx = cloud[i].X + dx[j];
            int ny = cloud[i].Y + dy[j];
            if (nx > n || nx <= 0 || ny > n || ny <= 0) continue;
            if (arr[nx][ny] == 0) continue;
            arr[cloud[i].X][cloud[i].Y]++;
        }
    }
    vector<pair<int, int>> newCloud;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            if (!chk(i, j)) continue; //구름이 사라진곳인지 체크
            if (arr[i][j] >= 2) {
                newCloud.push_back({ i, j });
                arr[i][j] -= 2;
            }
        }
    }
    cloud = newCloud;
}

int main() {
    fastIO;
    
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cin >> arr[i][j];
        }
    }
    cloud.push_back({ n,1 });
    cloud.push_back({ n,2 });
    cloud.push_back({ n - 1,1 });
    cloud.push_back({ n - 1,2 });

    for (int i = 0;i < m;i++) {
        int d, s;
        cin >> d >> s;
        rain(d-1, s);
    }

    int ret = 0;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            ret += arr[i][j];
        }
    }

    cout << ret << endl;

    return 0;
}
