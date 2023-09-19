#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define X first
#define Y second

int n, m, h;

bool chk[32][32];


bool calc() {
    
    int pos;
    for (int i = 1;i <= n;i++) {
        pos = i; 
        for (int j = 1;j <= h;j++) {
            if (chk[j][pos]) pos++;
            else if (chk[j][pos - 1]) pos--;
        }
        if (pos != i) return false;
    }
    return true;
}
//k = 사다리놓은갯수, st = 탐색시작위치(중복방지), mx =최대놓을수있는 사다리갯수
void findConbi(int k, int st, int mx) {
    if (k == mx) {
        if (calc()) {
            cout << mx << endl;
            exit(0);
        }
        return;
    }
    
    for (int i = st;i <= (n-1)*h;i++) {
        int x = i % h ;
        int y = i / h + 1;
        if (i % h == 0) {
            x = h;
            y -= 1;
        }
        if (chk[x][y])continue;
        if (chk[x][y - 1] || chk[x][y + 1])continue;
        chk[x][y] = 1;
        findConbi(k + 1, i+1, mx);
        chk[x][y] = 0;
    }
}

int main() {
    fastIO;
    cin >> n >> m >> h;
 
    for (int i = 0;i < m;i++) {
        int a, b;
        cin >> a >> b;
        chk[a][b] = 1;
    }
    
    for (int i = 0;i <= 3;i++) {
        findConbi(0, 1, i);
    }
    cout << -1 << endl;
}
