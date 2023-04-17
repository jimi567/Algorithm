#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define X first
#define Y second
int n;
pair<ll,ll> arr[1000005];
int main(void) {
    ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0;i < n;i++) {
	  cin >> arr[i].X >> arr[i].Y;
	}
	sort(arr, arr + n);
	ll ans = 0;
	ll en = arr[0].Y;
	ll st = arr[0].X;
	for (int i = 0;i < n;i++) {
		if (arr[i].X > en) { //줄이 끊어짐
			ans += en - st;
			st = arr[i].X;
			en = arr[i].Y;
			continue;
		}
		st = min(arr[i].X, st);
		en = max(arr[i].Y, en);
	}
	ans += en - st;
	cout << ans << endl;
}
