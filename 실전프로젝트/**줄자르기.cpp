#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define X first
#define Y second
const int MOD = 10007;
int tc, n, m;
int dp[10005];

int main() {
    fastIO;
    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        memset(dp, 0, sizeof(dp));
        for (int i = 1;i <= n;i++) {
            if (i <= m) {
                dp[i] = 1;
                continue;
            }
            int q = (i - m) / 2;
            dp[i] = (dp[i - m] * dp[m]) % MOD;
            if (i % 2 == 0 && i/2 != i-m)  dp[i] += (dp[i / 2] * dp[i / 2]) % MOD;
            if (m % 2 == i % 2 && i - m != i - q && i - m != q && m != i - q && m != q) dp[i] += (dp[i - q] * dp[q]) % MOD;
            dp[i] %= MOD;
        }
        cout << dp[n] << endl;
    }
    return 0;
}
