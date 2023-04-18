#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define X first
#define Y second
int n, k;
int used[105];
int seq[105];
int cur = 0;
int st = 0;
bool chk(int e) {
	for (int i = 0;i < cur;i++) {
		if (used[i] == e) return 1;
	}
	return 0;
}
void replace(int st,int e) {
	int idx = 0;//대체되는 탭
	vector<bool> state(n, 1);
	for (int i = st;i < k;i++) {
		for (int j = 0;j < cur;j++) {
			if (used[j] == seq[i]) state[j] = 0;
		}
		int cnt = 0;
		for (int j = 0;j < cur;j++) {
			if (state[j]) cnt++;
		}
		if (cnt == 1) {
			for(int j=0;j<cur;j++) if(state[j]) idx = j;
			break;
		}
	}
	used[idx] = e;
}
int main(void) {
    ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;

	for (int i = 0;i < k;i++) cin >> seq[i];
	int ans = 0;
	for (int i = 0;i < k;i++) {
		if (chk(seq[i])) continue;
		if (cur < n) {
			used[cur++] = seq[i];
		}
		else {
			replace(i+1,seq[i]);
			ans++;
		}
	}
	cout << ans;
}
