#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;


	stack<pair<int,int>> towers;
	
	for(int i= 1; i <= n; i++) {
		int h;
		cin >> h;

		while (!towers.empty()) {
			if (towers.top().second >= h) {
				cout << towers.top().first << " ";
				break;
			}
			towers.pop();
		}
		if (towers.empty()) cout << 0 << " ";
		towers.push(make_pair(i, h));
	}

}
