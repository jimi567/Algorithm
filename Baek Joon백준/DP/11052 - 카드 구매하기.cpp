#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define X first
#define Y second
int n;
int arr[1005];
int dp[1005];
int main(void) {
	fastIO;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> arr[i];
	
	dp[0] = 0;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= i;j++) {
			dp[i] = max(arr[j] + dp[i - j], dp[i]);
		}
	}
	cout << dp[n];

}
