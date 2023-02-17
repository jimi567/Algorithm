#include<bin/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
int arr[101];
int dp[10001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = arr[i]; j <= m; j++) {
			if (dp[j - arr[i]]) {
				dp[j] += dp[j-arr[i]];
			}
		}
	}
	cout << dp[m];
}
