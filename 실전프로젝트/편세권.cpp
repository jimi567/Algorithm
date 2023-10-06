#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define X first
#define Y second

int tc;
bool arr[55][55];
int sc[55][55];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int n;
int c;

int calc(int x, int y) {

    int ret = 0;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if (!arr[i][j]) continue;
            if (abs(x - i) + abs(y - j) <= 10) ret++;
            if (abs(x - i) + abs(y - j) <= 3) ret += 2;
        }
    }
    return ret;
}
void result(int mx) {
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if (sc[i][j] == mx) {
                cout << i << " " << j << " " << mx << endl;
                return;
            }
        }
    }
}
int main(void) {
    fastIO;
    
   
    cin >> tc;
    while (tc--) {

        cin >> n >> c;

        memset(arr, false, sizeof(arr));
        memset(sc, 0, sizeof(sc));
        for (int i = 0;i < c;i++) {
            int px, py;
            cin >> px >> py;
            arr[px][py] = 1;
        }
        
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                if (arr[i][j]) continue;
                sc[i][j] = calc(i, j);
            }
        }
        int mx = 0;
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) mx = max(mx, sc[i][j]);
        }
        
        result(mx);
    }
}
