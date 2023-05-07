#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define X first
#define Y second
int tc;
int n, m;
int coin[22];
int dp[10005];

int main(void) {
	fastIO;
	cin >> tc;
	while (tc--) {
		cin >> n;
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++) cin >> coin[i];
		cin >> m;
		dp[0] = 1; // 동전의 가치랑 m의 크기가 같을 경우
		for (int i = 0; i < n; i++) {
			for (int j = coin[i]; j <= m; j++) {
				dp[j] += dp[j - coin[i]];
			}
		}
		cout << dp[m] << endl;
	}
}
