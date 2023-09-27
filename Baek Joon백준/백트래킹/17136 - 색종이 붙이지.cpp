#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define X first
#define Y second

int n = 10;
//1x1 ~ 5x5 갯수
int paperCnt[5] = { 5,5,5,5,5 };
int arr[12][12];

int ret = 0x7f7f7f7f;

bool OOB(int x, int y) {
    return x < 0 || y < 0 || x >= n || y >= n;
}

bool isAllZero() {
    
    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
            if (arr[i][j] == 1) return 0;
    return 1;
}
bool canDup(int x, int y, int k) {
    if (OOB(x + k, y + k)) return 0;
    for (int i = x;i <= x+k;i++) {
        for (int j = y;j <= y+k;j++) {
            if (arr[i][j] != 1) return 0;
        }
    }
    return 1;
}
void dup(int x, int y, int k) {
    for (int i = x;i <= x + k;i++) {
        for (int j = y;j <= y + k;j++) {
            arr[i][j] = 2;
        }
    }
}
void rm(int x, int y, int k) {
    for (int i = x;i <= x + k;i++) {
        for (int j = y;j <= y + k;j++) {
            arr[i][j] = 1;
        }
    }
}
void print() {
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) cout << arr[i][j] << " ";
        cout << endl;
    }
}
void go(int cnt) {
    if (ret <= cnt) return; //이미 최소가아닌 케이스
    if (isAllZero()) {
        ret = min(ret, cnt);
        return;
    }

    for (int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            if (arr[i][j] != 1) continue;
            for (int k = 4;k >=0;k--) {
                if (!canDup(i, j, k) || paperCnt[k] == 0) continue;
                dup(i, j, k);
                paperCnt[k]--;
                go(cnt + 1);
                rm(i, j, k);
                paperCnt[k]++;
            }
            return; //이부분에 왜 리턴을 넣어야되지?
        }
    }
}
int main(void) {
    fastIO;
    
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cin >> arr[i][j];
        }
    }
    
    go(0);

    if (ret == 0x7f7f7f7f) cout << -1;
    else cout << ret;
}
