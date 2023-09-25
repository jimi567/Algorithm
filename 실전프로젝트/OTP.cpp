#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define X first
#define Y second

int tc;
int n, m;

ll mod = 999983;
ll co[105][3];

ll generate(int u, ll t) {
    if (t < 0) t = 0;
    t %= mod;
    return (((((co[u][0] * t) % mod * t) % mod) + (co[u][1] * t) % mod )% mod + co[u][2]) % mod;
}
string OTP(int u, int t, ll x) {
    for (int i = t - 3;i <= t + 3;i++) {
        if (generate(u, i) == x) return "YES";
    }
    return "NO";
}
int main(void) {
    fastIO;
    cin >> tc;
    
    while (tc--) {
        cin >> n;
        for (int i = 1;i <= n;i++) cin >> co[i][0] >> co[i][1] >> co[i][2];
        for (int i = 1;i <= n;i++)
            for (int j = 0;j < 3;j++) co[i][j] %= mod;
        cin >> m;
        for (int i = 0;i < m;i++) {
            int u, t;
            ll x;
            cin >> u >> t >> x;
            cout << OTP(u,t,x) << endl;
        }
    }
}
