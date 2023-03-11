using namespace std;
#define X first
#define Y second
#define ll long long
string arr[205];
bool vis[205][205];
int dx[3] = { 0,0,-1 };
int dy[3] = { 1,-1,0 };
int tc, n, m, d;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tc;
    while (tc--) {
        cin >> n >> m >> d;
        cin.ignore();
        for (int i = 0;i < m;i++) {
            getline(cin, arr[i]);
        }
        memset(vis, false, sizeof(vis));
        queue<pair<int, int>> q;
        q.push({ m - 1,2 * (d - 1) });
        vis[m - 1][2 * (d - 1)] = 1;
        while (!q.empty()) {
            auto cur = q.front();q.pop();
            if (cur.X == 0) {
                cout << (cur.Y + 2) / 2 << '\n';
                break;
            }
            for (int dir = 0;dir < 3;dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || ny<0 || nx>=m  || ny > 2*(n-1)) continue;
                if (arr[nx][ny] != '+' || vis[nx][ny]) continue;
                q.push({ nx,ny });
                vis[nx][ny] = 1;
                break;
            }
        }
    }

}
