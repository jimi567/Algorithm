#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define X first
#define Y second
int r, c;
int arr[1005][1005];
int dp[1005][1005];

int main() {
    fastIO;
    cin >> r >> c;
    for (int i = 1;i <= r;i++) {
        string in;
        cin >> in;
        for (int j = 1;j <= c;j++) arr[i][j] = in[j - 1] - '0';
    }
    int l = 0;
    for (int i = 1;i <= r;i++) {
        for (int j = 1;j <= c;j++) {
            if (!arr[i][j]) continue;
          //위,왼,왼쪽 대각선, 값 중 최솟값에 +1 값
          // 0 1
          // 1 ?   ? 값은 0의 부분의 dp값이 1이여야 정사각형임 고로 최솟값
            dp[i][j] = min({ dp[i - 1][j],dp[i][j-1],dp[i - 1][j-1] }) + 1;
            l = max(l, dp[i][j]);
        }
    }
    
    cout << l * l;
    return 0;
}
