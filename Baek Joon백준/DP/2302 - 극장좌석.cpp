#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long
int n, m;
int dp[45];
vector<int> vips;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vips.push_back(0);
    for (int i = 1;i <= m;i++) {
        int v;
        cin >> v;
        vips.push_back(v);
    }
    dp[0] = 1; //왜 dp[0]을 1로해줄 필요가있는지는 생각해보자
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 4;i <= 40;i++) dp[i] = dp[i - 1] + dp[i - 2];
    int ans = 1;
    for (int i = 1;i < vips.size();i++)ans *= dp[vips[i] - vips[i - 1] - 1];
    ans *= dp[n - vips[m]];
    cout << ans;
}
    
