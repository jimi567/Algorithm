#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	string s = "";
	cin >> s;
	char order;

	

	int n;
	cin >> n;
	
	list<char> L;
	auto cur = L.end();
	for (auto c : s) L.push_back(c);

	for (int i = 0; i < n; i++) {
		cin >> order;
		if (order == 'L') {
			if (cur != L.begin())cur--;
		}
		else if (order == 'D') {
			if (cur != L.end())cur++;
		}
		else if (order == 'B') {
			if (cur != L.begin()) cur = L.erase(--cur);
		}
		else {
			char c;
			cin >> c;
		
			L.insert(cur,c);
		}
	}
	for (auto c : L) cout << c;

}
